# peripheral registers

  .equ PWR_BASE,0x40007000

    .equ PWR_CR,0x00
      .equ PWR_CR_PMODE,0x4000
  
  .equ RCC_BASE,0x40023800
  
    .equ RCC_CR,0x00
      .equ RCC_CR_HSEON,0x00010000
      .equ RCC_CR_HSERDY,0x00020000
    
      .equ RCC_CR_PLLON,0x01000000
      .equ RCC_CR_PLLRDY,0x02000000
    
    .equ RCC_PLLCFGR,0x04

    .equ PLL_M,8
    .equ PLL_N,336
    .equ PLL_P,2
    .equ PLL_Q,7
    
    /* PLL_VCO = (HSE_VALUE or HSI_VALUE / PLL_M) * PLL_N */
    // #define PLL_M      8
    // #define PLL_N      336

    /* SYSCLK = PLL_VCO / PLL_P */
    // #define PLL_P      2

    /* USB OTG FS, SDIO and RNG Clock =  PLL_VCO / PLLQ */
    // #define PLL_Q      7

    .equ RCC_CFGR,0x08
      .equ RCC_CFGR_MCO1_MASK,0x00600000
      .equ RCC_CFGR_MCO1_HSI,0x00000000
      .equ RCC_CFGR_MCO1_LSI,0x00200000
      .equ RCC_CFGR_MCO1_HSE,0x00400000
      .equ RCC_CFGR_MCO1_PLL,0x00600000
      .equ RCC_CFGR_MCO2_MASK,0xC0000000
      .equ RCC_CFGR_MCO2_SYSCLK,0x00000000
      .equ RCC_CFGR_MCO2_PLLI2S,0x40000000
      .equ RCC_CFGR_MCO2_HSE,0x80000000
      .equ RCC_CFGR_MCO2_PLL,0xC0000000
      .equ RCC_CFGR_MCO2_Div_1,0x00000000
      .equ RCC_CFGR_HPRE_DIV1,0x00000000
      .equ RCC_CFGR_PPRE2_DIV2,0x00008000
      .equ RCC_CFGR_PPRE1_DIV4,0x00001400
      .equ RCC_CFGR_SW,0x00000003
      .equ RCC_CFGR_SW_PLL,0x00000002
      .equ RCC_CFGR_SWS,0x0000000C
      .equ RCC_CFGR_SWS_PLL,0x00000008
      .equ RCC_PLLCFGR_PLLSRC_HSE,0x00400000
      
    .equ RCC_CIR,0x0c      

    .equ RCC_AHB1ENR,0x30
      .equ RCC_AHB1ENR_GPIOA_EN,0x01
      .equ RCC_AHB1ENR_GPIOB_EN,0x02
      .equ RCC_AHB1ENR_GPIOC_EN,0x04
      .equ RCC_AHB1ENR_GPIOD_EN,0x08
      .equ RCC_AHB1ENR_GPIOE_EN,0x10

    .equ RCC_APB1ENR,0x40
      .equ RCC_APB1ENR_PWREN,0x10000000    

      
  .equ FLASH_BASE,0x08000000
  
  .equ FLASH_R_BASE,0x40023c00
  
    .equ FLASH_ACR,0x00
      .equ FLASH_ACR_ICEN,0x00000200
      .equ FLASH_ACR_DCEN,0x00000400
      .equ FLASH_ACR_LATENCY_5WS,0x00000005
 
  .equ VECT_TAB_OFFSET,0x00
  
  .equ SCB_BASE,0xE000ED00
    .equ SCB_VTOR,0x08

  .equ GPIOA_BASE,0x40020000
  .equ GPIOB_BASE,0x40020400
  .equ GPIOC_BASE,0x40020800
  .equ GPIOD_BASE,0x40020C00
  .equ GPIOE_BASE,0x40021000
  
    .equ GPIO_MODER,0x00
      .equ GPIO_MODER_IN,0b00
      .equ GPIO_MODER_OUT,0b01
      .equ GPIO_MODER_AF,0b10
      .equ GPIO_MODER_ANALOG,0b11
      
    .equ GPIO_OTYPER,0x04
      .equ GPIO_OTYPER_PP,0b00
      .equ GPIO_OTYPER_OD,0b01
    
    .equ GPIO_OSPEEDR,0x08
      .equ GPIO_OSPEEDR_LS,0b00
      .equ GPIO_OSPEEDR_MS,0b01
      .equ GPIO_OSPEEDR_FS,0b10
      .equ GPIO_OSPEEDR_HS,0b11
    
    .equ GPIO_PUPDR,0x0c
      .equ GPIO_PUPDR_NOPUP,0b00
      .equ GPIO_PUPDR_PUP,0b01
      .equ GPIO_PUPDR_PDOWN,0b10
    
    .equ GPIO_IDR,0x10
    .equ GPIO_ODR,0x14

  .equ SYST_BASE,0xE000E010
    .equ SYST_CSR,0x0
    .equ SYST_RVR,0x4
    .equ SYST_CVR,0x8
    .equ SYST_CALIB,0xC
    
    .equ SYST_RVR_MASK,0x00ffffff
    .equ SYST_CSR_CLKSOURCE,0x00000004
    .equ SYST_CSR_TICKINT,0x00000002
    .equ SYST_CSR_ENABLE,0x00000001
    
