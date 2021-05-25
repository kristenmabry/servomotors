#ifndef __DEV_GPIO_H__
#define __DEV_GPIO_H__

#include <stdint.h>
struct GPIO
{
  volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  volatile uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  volatile uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  volatile uint16_t BSRRL;    /*!< GPIO port bit set/reset low register,  Address offset: 0x18      */
  volatile uint16_t BSRRH;    /*!< GPIO port bit set/reset high register, Address offset: 0x1A      */
  volatile uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  volatile uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
};

#define GPIO_MODE_OUT              ((uint32_t)0x01)
#define GPIO_MODE_ANALOG           ((uint32_t)0x03)
#define GPIO_PUPDR_NOPULL          ((uint32_t)0x00)

#endif  /* __DEV_GPIO_H__ */
