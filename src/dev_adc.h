#ifndef __DEV_ADC_H__
#define __DEV_ADC_H__

struct ADC
{
  volatile uint32_t SR;  // offset 0x00
  volatile uint32_t CR1; // offset 0x04
  volatile uint32_t CR2;  // offset 0x08
  volatile uint32_t SMPR1;  // offset 0x0C
  volatile uint32_t SMPR2;  // offset 0x10
  volatile uint32_t JOFR1;  // offset 0x14
  volatile uint32_t JOFR2;  // offset 0x18
  volatile uint32_t JOFR3;  // offset 0x1C
  volatile uint32_t JOFR4;  // offset 0x20
  volatile uint32_t HTR;  // offset 0x24
  volatile uint32_t LTR;  // offset 0x28
  volatile uint32_t SQR1;  // offset 0x2C
  volatile uint32_t SQR2;  // offset 0x30
  volatile uint32_t SQR3;  // offset 0x34
  volatile uint32_t JSQR;  // offset 0x38
  volatile uint32_t JDR1;  // offset 0x3C
  volatile uint32_t JDR2;  // offset 0x40
  volatile uint32_t JDR3;  // offset 0x44
  volatile uint32_t JDR4;  // offset 0x48
  volatile uint32_t DR;  // offset 0x4C
  volatile uint32_t CSR;  // offset 0x50
};

struct ADC_COMMON
{
  volatile uint32_t CSR;
  volatile uint32_t CCR;
  volatile uint32_t CDR;
};

#define ADC_CCR_TSVREFE (1<<23)
#define ADC_CR2_ADON    (1<<0)
#define ADC_CR2_SWSTART (1<<30)
#define ADC_SR_EOC      (1<<1)


#endif  /* __DEV_ADC_H__ */
