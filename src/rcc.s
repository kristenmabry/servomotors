// file: rcc.s

   .syntax unified
   .thumb

   .include    "src/periph_regs.inc"
        
   .text

   .align      2
   .global     rcc_gpio_enable
   .thumb_func
   .type       rcc_gpio_enable, %function

rcc_gpio_enable:

  mov r3,#4
  cmp r0,r3
  bgt skip_enable
    
    ldr r3,=RCC_BASE
    ldr r1,[r3, #RCC_AHB1ENR]
    mov r2,#1
    lsl r2,r0
    orr r1,r2
    str r1,[r3, RCC_AHB1ENR]

  skip_enable:

  bx lr

    .end    