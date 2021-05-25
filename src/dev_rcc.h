#ifndef __DEV_RCC_H__
#define __DEV_RCC_H__

struct RCC
{
  volatile uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  volatile uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  volatile uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  volatile uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  volatile uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  volatile uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  volatile uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
           uint32_t RESERVED0;     /*!< Reserved, 0x1C                                                                    */
  volatile uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  volatile uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
           uint32_t RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
  volatile uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  volatile uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  volatile uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
           uint32_t RESERVED2;     /*!< Reserved, 0x3C                                                                    */
  volatile uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  volatile uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
           uint32_t RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  volatile uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  volatile uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  volatile uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
           uint32_t RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  volatile uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  volatile uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
           uint32_t RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  volatile uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  volatile uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
           uint32_t RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  volatile uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  volatile uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
};

#define RCC_CR_HSEON        ((uint32_t)0x00010000)
#define RCC_CR_HSERDY       ((uint32_t)0x00020000)
#define RCC_CR_PLLON        ((uint32_t)0x01000000)
#define RCC_CR_PLLRDY       ((uint32_t)0x02000000)
#define RCC_CFGR_SW         ((uint32_t)0x00000003)        /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_PLL     ((uint32_t)0x00000002)        /*!< PLL selected as system clock */
#define RCC_CFGR_SWS        ((uint32_t)0x0000000C)        /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_PLL    ((uint32_t)0x00000008)        /*!< PLL used as system clock */
#define RCC_CFGR_HPRE_DIV1  ((uint32_t)0x00000000)        /*!< SYSCLK not divided */
#define RCC_CFGR_HPRE_DIV2  ((uint32_t)0x00000080)        /*!< SYSCLK divided by 2 */
#define RCC_CFGR_HPRE_DIV4  ((uint32_t)0x00000090)        /*!< SYSCLK divided by 4 */
#define RCC_CFGR_PPRE1_DIV4 ((uint32_t)0x00001400)        /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE2_DIV2 ((uint32_t)0x00008000)        /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE2_DIV4 ((uint32_t)0x0000A000)        /*!< HCLK divided by 4 */
#define RCC_PLLCFGR_PLLSRC_HSE              ((uint32_t)0x00400000)
#define RCC_APB1ENR_PWREN   ((uint32_t)0x10000000)

#define RCC_AHB1ENR_GPIOAEN       ((uint32_t)(1<<0))
#define RCC_AHB1ENR_GPIOBEN       ((uint32_t)(1<<1))
#define RCC_AHB1ENR_GPIOCEN       ((uint32_t)(1<<2))
#define RCC_AHB1ENR_GPIODEN       ((uint32_t)(1<<3))
#define RCC_AHB1ENR_GPIOEEN       ((uint32_t)(1<<4))

#define RCC_APB2ENR_ADC1EN ((uint32_t)(1<<8))
#define RCC_APB2ENR_ADC2EN ((uint32_t)(1<<9))
#define RCC_APB2ENR_ADC3EN ((uint32_t)(1<<10))


#endif  /* __DEV_RCC_H__ */
