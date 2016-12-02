/*
 * Motorshield.c
 *
 * Created: 11/28/2016 14:57:17
 *  Author: Nadia, Elvin
 */ 

#include <asf.h>
#include "Motorshield.h"

/* Initialize motor shield, using pins for channel A */
void motorshield_setup(void)
{
	// Direction pin D12
	ioport_set_pin_dir(PIO_PD8_IDX, IOPORT_DIR_INPUT);
	ioport_set_pin_level(PIO_PD8_IDX, IOPORT_PIN_LEVEL_LOW);
	
	// Brake pin D9
	ioport_set_pin_dir(PIO_PC21_IDX, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIO_PC21_IDX, IOPORT_PIN_LEVEL_HIGH);
}