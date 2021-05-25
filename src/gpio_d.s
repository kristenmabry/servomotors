# file: gpio_d.s
# author: Kristen Mabry

.include "macros.inc"
.include "gpio_regs.inc"

  SET_TARGET

  .text

  FUNCTION gpio_d_init,global		// initialize 16 bits of Port D to outputs

    push {lr}

		mov	r0,#3										// send 2 as argument to rcc_gpio_enable function
		bl	rcc_gpio_enable					// call rcc_gpio_enable

		ldr	r3,=#GPIOD_BASE					// r3 = GPIO PORT D base address

		ldr r2,=#0x00000000					// r2 = 0
		str	r2,[r3,#GPIO_PUPDR]			// clear Port D PUPD register
		str	r2,[r3,#GPIO_OTYPER]		// clear Port D Type register
		str	r2,[r3,#GPIO_ODR]				// clear Port D ouput data register

		ldr	r2,=#0x55555555						// set all 16 bits of Port D to outputs
		str	r2,[r3,#GPIO_MODER]

		ldr	r2,=#0xffffffff					// write 0xffffffff to Port D speed register
		str	r2,[r3,#GPIO_OSPEEDR]

    pop {lr}

    bx lr
  
  ENDFUNC gpio_d_init


	FUNCTION gpio_d_put,global		// put a value out to the 16 bits of Port D outputs

		push {lr}

		ldr	r3,=#GPIOD_BASE					// load r3 with base address of GPIO Port D

		str	r0,[r3,#GPIO_ODR]				// write r0 (function arg) to GPIO Port D output

		pop {lr}

		bx lr

	ENDFUNC gpio_d_put

	FUNCTION gpio_d_get_current,global

		push	{lr}

		ldr		r3,=#GPIOD_BASE
		ldr		r0,[r3,#GPIO_ODR]		// load Port D ODR into r0

		pop		{lr}
		bx		lr

	ENDFUNC	gpio_d_get_current

  .end
