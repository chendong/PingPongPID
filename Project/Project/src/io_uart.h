/*
 * io_uart.h
 * This file contains functions for UART communication.
 * Author: Nadia, Elvin
 */ 

#ifndef IO_UART_H_
#define IO_UART_H_

#include <asf.h>

typedef uint32_t reg_address_t;

/* Master Clock Frequency (84 MHz) */
#define MCK 84000000U
/* UART Status Register */
#define UART_SR (*p_UART_SR)

/* Receiver Ready? */
int uart_receiver_ready(void);

double read_double(void);
uint8_t read_int(void);
uint32_t wait_rxready(void);
void setupUART(void);
uint8_t read_uart(void);

#endif