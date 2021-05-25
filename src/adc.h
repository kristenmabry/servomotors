#ifndef __ADC_H__
#define __ADC_H__

#include <stdbool.h>
#include <stdint.h>

void adc_init(void);
void adc_start(void);
bool adc_done(void);
uint32_t adc_get(void);

#endif  /*__ADC_H__ */
