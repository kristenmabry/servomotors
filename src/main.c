/* 	file: main.c
 	author: Kristen Mabry
 	SW15: Automatic = 0, Manual = 1
 	SW0:  Control X = 1
 	SW1:  Control Y = 1
*/

/* Includes */
#include "adc.h"
#include "seg7.h"

/* Defines */
#define LEDs_ODR_Base       (0x40020C14)                         	/* LEDs Port D ODR Address */
#define SWs_IDR_Base		(0x40020810)							/* Switches Port C IDR Address */

#define NUM_LEVELS 180
#define period 0.02
#define AUTO_CYCLE 1

/* Outside Function Declarations */
void gpio_d_init(void);
void gpio_c_init(void);
void SetSysClock(void);
void SysTick_Config(unsigned int ticks);
void SysTick_Handler(void);

/* Internal Function Declarations */
void initialize(void);
uint32_t get_adc_value(void);
void update_manual_level(char manualMode, char controlling_x, char controlling_y, uint32_t adc_val);
void update_seg7_displays(char manualMode, char controlling_x, char controlling_y);

/* Global Variables */
char seg7[] = { 0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10, 0x08, 0x03, 0x46, 0x21, 0x06, 0x0e };
char seg7_off = 0x7f;

unsigned int *pLEDs = (unsigned int*)LEDs_ODR_Base;
unsigned int *pSWs = (unsigned int*)SWs_IDR_Base;

int counter = 1;
int auto_counter = 1;
int curr_level_x = (int)NUM_LEVELS;
int x_dir = 1;
int curr_level_y = (int)NUM_LEVELS;
int y_dir = 1;
int cycle;

int main()
{
	initialize();

	while(1)													//loop forever
	{
		uint32_t adc_val = get_adc_value();
		char manualMode = (*pSWs >> 15) & 1;
		char controlling_x = *pSWs & 1;
		char controlling_y = (*pSWs >> 1) & 1;

		update_manual_level(manualMode, controlling_x, controlling_y, adc_val);
		update_seg7_displays(manualMode, controlling_x, controlling_y);
			
	} // end while loop

  return 0;
}

void SysTick_Handler (void)     								//ISR - SysTick Interrupt Service Routine
{    
	/* Update Automatic Level */
	int manualMode = (*pSWs >> 15) & 1;
	if (auto_counter == (int)AUTO_CYCLE && !manualMode) 		// if automatic mode & 1 auto cycle has passed
	{
			curr_level_x += x_dir;								// increment/decrement x level
			if (!(curr_level_x % (int)NUM_LEVELS))				// if at max/min level, change direction
			{
				x_dir *= -1;	
			}

			curr_level_y += y_dir;								// increment/decrement y level
			if (!(curr_level_y % (int)NUM_LEVELS))				// if at max/min level, change direction
			{
				y_dir *= -1;	
			}
			auto_counter = 0;
	}

	if (!manualMode && !(counter % (int)cycle))
	{
		auto_counter++;
	}

	/* Update Servo Motors */
	char x_on = (counter % (int)cycle) < curr_level_x;
	char y_on = (counter % (int)cycle) < curr_level_y;
	*pLEDs = x_on + (y_on << 1);
	counter++;
}

void initialize(void)
{
	/* Init Ports */
 	gpio_d_init();												// Port D
	gpio_c_init();												// Port C
	adc_init();													// Port A0
	seg7_init();

	SetSysClock();

	/* PWM Calculations */
	float res = 0.001 / (float)NUM_LEVELS;
	cycle = (float)period / res;
	unsigned int reload_value = res * 168000000;
 	SysTick_Config(reload_value);								// configure SysTick System Timer

	seg7_put(6, seg7_off);										// not used
}

uint32_t get_adc_value(void)
{
	adc_start();												// start ADC
	uint32_t q = 0;

	while (!adc_done())
	{
		q++;
	}

	return adc_get();
}

void update_manual_level(char manualMode, char controlling_x, char controlling_y, uint32_t adc_val)
{
	if (manualMode)
	{
		if (controlling_x)
		{
			curr_level_x = (adc_val * (int)NUM_LEVELS / 4096) + (int)NUM_LEVELS; // range goes from NUM_LEVELS to 2*NUM_LEVELS
		}
		if (controlling_y)
		{
			curr_level_y = (adc_val * (int)NUM_LEVELS / 4096) + (int)NUM_LEVELS; // range goes from NUM_LEVELS to 2*NUM_LEVELS
		}
	}
}

void update_seg7_displays(char manualMode, char controlling_x, char controlling_y)
{
	/* Letters */
	seg7_put(7, manualMode ? seg7_off : seg7[10]);					// show 'A' if automatic mode
	seg7_put(5, (!manualMode || controlling_y) ? 0x63 : seg7_off); 	// 'u' => 0110 0011 = 0x63
	seg7_put(4, (!manualMode || controlling_x) ? 0x47 : seg7_off);	// 'L' => 0100 0111 = 0x47

	/* X/Y Levels */
	int display = (curr_level_y - ((int)NUM_LEVELS * 1.5)) * 180 / (int)NUM_LEVELS; // convert level to range 0 - 90 degrees
	if (display < 0)
	{
		display *= -1;
	}
	seg7_put(3, seg7[display / 10]); 							// y level tens
	seg7_put(2, seg7[display % 10]); 							// y level ones

	display = (curr_level_x - ((int)NUM_LEVELS * 1.5)) * 180 / (int)NUM_LEVELS; // convert level to range 0 - 90 degrees
	if (display < 0)
	{
		display *= -1;
	}
	seg7_put(1, seg7[display / 10]); 							// x level tens
	seg7_put(0, seg7[display % 10]);							// x level ones
}