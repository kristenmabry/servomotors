# file: SetSysClock.s

    .syntax unified
    .thumb
    .file	"SetSysClock.s"

.include "src/periph_regs.inc"
      
    .text
    .align	2
    .global	SetSysClock
    .thumb_func
    .type	SetSysClock, %function

SetSysClock:

  /******************************************************************************/
  /*            PLL (clocked by HSE) used as System clock source                */
  /******************************************************************************/

  push {r4,r5,r6,r7,lr}

  ldr r7,=#RCC_BASE

    /* Enable HSE */
  
    ldr r4,[r7,#RCC_CR]
    ldr r5,=#RCC_CR_HSEON
    orr r4,r5
    str r4,[r7,#RCC_CR]
 
  /* Wait till HSE is ready and if Time out is reached exit */

    ldr r3,=#0x500
  
    Wait_HSE_Ready:

      subs r3,#1
      beq  fail_startup
    
      ldr  r4,[r7,#RCC_CR]
      ldr  r5,=#RCC_CR_HSERDY
      ands r4,r5
      beq  Wait_HSE_Ready

      /* Enable high performance mode, System frequency up to 168 MHz */
    
    ldr r4,[r7,#RCC_APB1ENR]
    ldr r5,=#RCC_APB1ENR_PWREN
    orr r4,r5
    str r4,[r7,#RCC_APB1ENR]
    

  ldr r7,=#PWR_BASE
    
    ldr r4,[r7,#PWR_CR]
    ldr r5,=#PWR_CR_PMODE
    orr r4,r5
    str r4,[r7,#PWR_CR]

  ldr r7,=#RCC_BASE
    
    /* HCLK = SYSCLK / 1*/

    ldr r4,[r7,#RCC_CFGR]
    ldr r5,=#RCC_CFGR_HPRE_DIV1
    orr r4,r5
    str r4,[r7,#RCC_CFGR]
    
    /* PCLK2 = HCLK / 2*/
    
    ldr r4,[r7,#RCC_CFGR]
    ldr r5,=#RCC_CFGR_PPRE2_DIV2
    orr r4,r5
    str r4,[r7,#RCC_CFGR]
    
    /* PCLK1 = HCLK / 4*/

    ldr r4,[r7,#RCC_CFGR]
    ldr r5,=#RCC_CFGR_PPRE1_DIV4
    orr r4,r5
    str r4,[r7,#RCC_CFGR]
    
    /* Configure the main PLL */

    ldr r4,=#( PLL_M | (PLL_N << 6) | (((PLL_P >> 1) -1) << 16) | (RCC_PLLCFGR_PLLSRC_HSE) | (PLL_Q << 24) )              
    str r4,[r7,#RCC_PLLCFGR]
    
    /* Enable the main PLL */

    ldr r4,[r7,#RCC_CR]
    ldr r5,=#RCC_CR_PLLON
    orr r4,r5
    str r4,[r7,#RCC_CR]
    
    
    Wait_PLL_Ready:
      ldr r4,[r7,#RCC_CR]
      ldr r5,=#RCC_CR_PLLRDY
      ands r4,r5
      beq Wait_PLL_Ready
   
    /* Configure Flash prefetch, Instruction cache, Data cache and wait state */

  ldr r7,=#FLASH_R_BASE   

    ldr r4,=#(FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_LATENCY_5WS)
    str r4,[r7,#FLASH_ACR]

  ldr r7,=#RCC_BASE
  
    /* Select the main PLL as system clock source */
    
    ldr r4,[r7,#RCC_CFGR]
    ldr r5,=#~(RCC_CFGR_SW)
    and r4,r5
    str r4,[r7,#RCC_CFGR]

    ldr r4,[r7,#RCC_CFGR]
    ldr r5,=#RCC_CFGR_SW_PLL
    orr r4,r5
    str r4,[r7,#RCC_CFGR]
    
    Wait_PLL:
      ldr r4,[r7,#RCC_CFGR]
      ldr r5,=#RCC_CFGR_SWS
      and r4,r5
      ldr r5,=#RCC_CFGR_SWS_PLL
      cmp r4,r5
      bne Wait_PLL
   
    pop {r4,r5,r6,r7,lr}
    
    bx lr
  
  fail_startup:
    
    b fail_startup

  .end
