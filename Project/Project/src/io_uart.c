/*
 * io_uart.c
 *
 * This file contains functions for UART communication.
 *
 * Author: Nadia, Elvin
 */ 

#include "io_uart.h"

/* UART Status Register (pointer) */
reg_address_t *const p_UART_SR = (reg_address_t *) 0x400E0814U;

void uart_setup(void)
{
	pio_configure(PINS_UART_PIO, PINS_UART_TYPE, PINS_UART_MASK, PIO_DEFAULT);
	pmc_enable_periph_clk(ID_UART);
	const sam_uart_opt_t uart0_settings = {sysclk_get_cpu_hz(), CONF_UART_BAUDRATE, UART_MR_PAR_NO};
	ioport_set_pin_mode(PIO_PA8_IDX, IOPORT_MODE_PULLUP);
	uart_init(UART, &uart0_settings);
}

/*
 * Receiver Ready?
 * Return 1 if "Receiver Ready" flag is set, otherwise 0
 */
/* If receiver is ready, return 1. Returns 1 if "fwrite(s, uint8(1))" is executed in MATLAB */
int uart_receiver_ready(void)
{
	return (UART_SR & UART_SR_RXRDY);
}

/* Read a string and converts to double */
double read_double(void)
{
	double result;
	char str[10] = {0};
	scanf("%s", str);
	result = atof(str);
	
	return result;
}

/* Read a string and converts to int */
uint8_t read_int(void)
{
	uint8_t result;
	char str[10] = {0};
	scanf("%s", str);
	result = atof(str);
	
	return result;
}

/* Get and return a binary value. Used with "fwrite(s, uint8(1))" from MATLAB */
uint8_t read_uart(void)
{
	uint8_t result;
	uart_read(CONF_UART, &result);
	
	return result;
}