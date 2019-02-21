/*
 * FreeRTOS Kernel V10.1.1
 * Copyright (C) 2018 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/*-----------------------------------------------------------
 * Simple GPIO (parallel port) IO routines.
 *-----------------------------------------------------------*/

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Hardware includes. */
#include <saml11e16a.h>
#include <hal_gpio.h>
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hal_delay.h>
/* Standard demo include. */
#include "partest.h"

/* The port bits on which LEDs are connected. */
/* UPDATE */

/* The port bits on which LEDs are connected. */
/* UPDATE */

#define partstNUM_LEDS	( sizeof( ulLEDBits ) / sizeof( unsigned long ) )

/* Shift the LED bit into the correct position within the POW register to
perform the desired operation. */
#define partstON_SHIFT	( 16UL )
#define partstOFF_SHIFT	( 0UL )

/*-----------------------------------------------------------*/

/* UPDATE */
void vParTestInitialise( void )
{
	/* Configure relevant port P0 to push pull output to drive LEDs. */
	gpio_set_pin_level(LED0, false);
	gpio_set_pin_direction(LED0, GPIO_DIRECTION_OUT);
	gpio_set_pin_function(LED0, GPIO_PIN_FUNCTION_OFF);

	delay_init(SysTick);
}
/*-----------------------------------------------------------*/

/* UPDATE */
void vParTestSetLED( unsigned long ulLED, signed portBASE_TYPE xValue )
{
		if( xValue == pdTRUE )
		{
			/* Turn the LED on. */
			gpio_set_pin_level(LED0, true);
		}
		else
		{
			/* Turn the LED off. */
			gpio_set_pin_level(LED0, false);
			
		}
}
/*-----------------------------------------------------------*/

/* UPDATE */
void vParTestToggleLED( unsigned long ulLED )
{

	gpio_toggle_pin_level(LED0);
}
/*-----------------------------------------------------------*/

