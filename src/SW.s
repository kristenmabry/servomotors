# file: SW.s
# author: Kristen Mabry

.include "macros.inc"

  SET_TARGET

  .text

  FUNCTION	SW_Init,global		// initialize switches in port C

    push {lr}

		bl	gpio_c_init

    pop {lr}

    bx lr
  
  ENDFUNC SW_Init


	FUNCTION SW_Get_A,global

		push {lr}

		bl	gpio_c_get						// get port C

		lsr	r0,#3
		and	r0,#1									// normalize bit 3

		pop {lr}

		bx lr

	ENDFUNC SW_Get_A


	FUNCTION SW_Get_B,global

		push {lr}

		bl	gpio_c_get						// get port C

		lsr	r0,#8
		ldr r1,=#(~(~0<<4))				// normalize bits 11..8
		and	r0,r1

		pop {lr}

		bx lr

	ENDFUNC SW_Get_B

	FUNCTION sw_get_index,global

		push {lr}

		bl	gpio_c_get						// get port C

		lsr	r0,#12
		ldr r1,=#(~(~0<<3))				// normalize bits 14..12
		and	r0,r1

		pop {lr}

		bx lr

	ENDFUNC sw_get_index

	FUNCTION sw_get_segments,global

		push {lr}

		bl	gpio_c_get						// get port C

		ldr r1,=#(~(~0<<7))				// normalize bits 6..0
		and	r0,r1

		pop {lr}

		bx lr

	ENDFUNC sw_get_segments

	FUNCTION sw_get_hex,global

		push {lr}

		bl	gpio_c_get						// get port C

		lsr	r0,#7
		ldr r1,=#(~(~0<<4))				// normalize bits 10..7
		and	r0,r1

		pop {lr}

		bx lr

	ENDFUNC sw_get_hex


	FUNCTION sw_get_latch,global

		push {lr}

		bl	gpio_c_get						// get port C

		lsr	r0,#15
		and	r0,#1									// normalize bit 15

		pop {lr}

		bx lr

	ENDFUNC sw_get_latch



  .end
