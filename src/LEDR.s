# file: LEDR.s
# author: Kristen Mabry

.include "macros.inc"

  SET_TARGET

  .text

  FUNCTION	LEDR_Init,global		// initialize LEDs in port D

    push {lr}

		bl	gpio_d_init

    pop {lr}

    bx lr
  
  ENDFUNC LEDR_Init


	FUNCTION LEDR_Put_A,global

		push {lr}

		mov	r1,r0									// save input args in r1

		bl	gpio_d_get_current		// get current LEDs in r0

		ldr	r2,=#1								// create 1 bit mask
		and	r1,r2									// isolate new bits
		lsl	r1,#8									// de-normalize to bit 8
		lsl r2,#8
		mvn	r2,r2									// invert mask
		and	r0,r2									// clear target bit
		orr	r0,r1									// set new bit

		bl gpio_d_put							// write to port D

		pop {lr}

		bx lr

	ENDFUNC LEDR_Put_A


	FUNCTION LEDR_Put_B,global

		push {lr}

		mov	r1,r0									// save input args in r1

		bl	gpio_d_get_current		// get current LEDs in r0

		ldr	r2,=#(~(~0<<4))				// create 4 bit mask
		and	r1,r2									// isolate new bits
		lsl	r1,#2									// de-normalize to bits 5..2
		lsl r2,#2
		mvn	r2,r2									// invert mask
		and	r0,r2									// clear target bit
		orr	r0,r1									// set new bit

		bl gpio_d_put							// write to port D

		pop {lr}

		bx lr

	ENDFUNC LEDR_Put_B


	FUNCTION led_put_index,global

		push {lr}

		mov	r1,r0									// save input args in r1

		bl	gpio_d_get_current		// get current LEDs in r0

		ldr	r2,=#(~(~0<<3))				// create 3 bit mask
		and	r1,r2									// isolate new bits
		lsl	r1,#12								// de-normalize to bits 14..12
		lsl r2,#12
		mvn	r2,r2									// invert mask
		and	r0,r2									// clear target bit
		orr	r0,r1									// set new bit

		bl gpio_d_put							// write to port D

		pop {lr}

		bx lr

	ENDFUNC led_put_index

	FUNCTION led_put_segments,global

		push {lr}

		mov	r1,r0									// save input args in r1

		bl	gpio_d_get_current		// get current LEDs in r0

		ldr	r2,=#(~(~0<<7))				// create 7 bit mask
		and	r1,r2									// isolate new bits
		mvn	r2,r2									// invert mask
		and	r0,r2									// clear target bit
		orr	r0,r1									// set new bit

		bl gpio_d_put							// write to port D

		pop {lr}

		bx lr

	ENDFUNC led_put_segments

  .end
