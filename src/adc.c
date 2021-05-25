#include <stdbool.h>
#include <stdint.h>
#include "dev_rcc.h"
#include "dev_gpio.h"
#include "dev_adc.h"

#define PERIPH_BASE         ((uint32_t)0x40000000)
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000)
#define RCC_BASE            (AHB1PERIPH_BASE + 0x3800)
#define GPIOA_BASE          (AHB1PERIPH_BASE + 0x0000)

#define APB2PERIPH_BASE     (PERIPH_BASE + 0x00010000)
#define ADC_BASE            (APB2PERIPH_BASE + 0x2000)
#define ADC1_BASE           (ADC_BASE + 0x000)


struct RCC  * RCC  = (struct RCC*)RCC_BASE;
struct GPIO *GPIOA = (struct GPIO*)GPIOA_BASE;
struct ADC  *ADC1  = (struct ADC*)ADC1_BASE;

void adc_init(void)
{

  // enable GPIOA0
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  GPIOA->MODER |= ((uint32_t)(GPIO_MODE_ANALOG << ( 2 * 0))); // 0x3 is analog mode
  
 // enable APB2 for ADC1
  RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

  ADC1->CR1 = 0; // defaults are fine for now
  ADC1->CR2 = 0; // defaults are fine for now
  
  // Configure Channel/Sequence
  // SQR1[23:20] set sequence length -- 0 means one conversion 
  ADC1->SQR1 = 0;

  // NOTE: set ~10us to read 
  // ADCCLK is F_pclk2 (84MHz) / prescaler
  // default prescaler = 2, so default ADCCLK is 42MHz
  // 42MHz -> 23.9ns cycle, so we need 480 cycle sampling time
  // Set Sample Time (480 Cycles)
  ADC1->SMPR1 = 7<<18;

  // set the channel
  ADC1->SQR2 = 0;
  ADC1->SQR3 = 0; // choose ADC IN0

  // Enable ADC
  ADC1->CR2 |= ADC_CR2_ADON;
}

void adc_start(void)
{
  // Start Regular Channel Conversion
  ADC1->CR2 |= ADC_CR2_SWSTART;
}

bool adc_done(void)
{
  // This bit is SET by hardware once the conversion is complete
  // it is CLEARED by software OR by reading the ADC_DR register
  return (ADC1->SR & ADC_SR_EOC);
}

uint32_t adc_get(void)
{
  // this clears the ADC_SR_EOC bit
  return ADC1->DR;
}
