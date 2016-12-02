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

void setupUART(void)
{
	pio_configure(PINS_UART_PIO, PINS_UART_TYPE, PINS_UART_MASK, PIO_DEFAULT);
	pmc_enable_periph_clk(ID_UART);
	const sam_uart_opt_t uart0_settings = {sysclk_get_cpu_hz(), CONF_UART_BAUDRATE, UART_MR_PAR_NO};
	ioport_set_pin_mode(PIO_PA8_IDX, IOPORT_MODE_PULLUP);
	uart_init(UART, &uart0_settings);
}

/*
 * Receiver Ready?
 * Return 1 if "Receiver Ready" flag is set, otherwise 0.
 */
int uart_receiver_ready(void)
{
	return (UART_SR & UART_SR_RXRDY);
}

uint32_t wait_rxready(void)
{
	while(!((UART_SR & UART_SR_RXRDY)>0));
	
	return 1;
}

/* Converts string to double */
double read_double(void)
{
	double result;
	char str[10] = {0};
	scanf("%s", str);
	result = atof(str);
	
	return result;
}

/* Converts string to double */
uint8_t read_int(void)
{
	uint8_t result;
	char str[10] = {0};
	scanf("%s", str);
	result = atof(str);
	
	return result;
}

/* Get and return a binary value */
uint8_t read_uart(void)
{
	uint8_t result;
	uart_read(CONF_UART, &result);
	
	return result;
}