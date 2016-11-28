/**
 * main.c
 *
 *  Author: Nadia, Elvin
 *
 */

#include <asf.h>
#include "ConsoleFunctions.h"
#include "SensorFunctions.h"
#include "PWMFunctions.h"
#include "Motorshield.h"
#include "DelayFunctions.h"
#include "TestFunctions.h"




int main (void)
{
	sysclk_init();	
	board_init();
	configure_console();
	adc_setup();
	pwm_setup();
	motorshield_setup();
	delay_init();


	
	//test_terminal();
	test_sensor();
	//test_fan();
}
