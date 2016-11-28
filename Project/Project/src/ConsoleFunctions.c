/*
 * ConsoleFunctions.c
 *
 * Created: 11/28/2016 13:49:23
 *  Author: Nadia, Elvin
 */ 

#include <asf.h>
#include "ConsoleFunctions.h"


void configure_console(void)
/* Enables feedback through the USB-cable back to terminal within Atmel Studio.
*  Note that the baudrate, parity and other parameters must be set in */
{
	const usart_serial_options_t uart_serial_options = {
		.baudrate = CONF_UART_BAUDRATE,
		.paritytype = CONF_UART_PARITY
	};
	
	/* Configure console UART */
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_UART, &uart_serial_options);
}