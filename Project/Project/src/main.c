/**
 * main.c
 *
 * Author: Nadia Manoh and Elvin Lapovski
 */

#include <asf.h>
#include "ConsoleFunctions.h"
#include "SensorFunctions.h"
#include "PWMFunctions.h"
#include "Motorshield.h"
#include "DelayFunctions.h"
#include "TestFunctions.h"
#include "PIDControl.h"
#include "MatlabPlot.h"
#include "io_uart.h"

int main (void)
{
	sysclk_init();			// Initialize system clock
	board_init();			// Initialize Arduino Due board
	configure_console();	// Initialize terminal window
	adc_setup();			// Initialize ADC
	pwm_setup();			// Initialize PWM
	motorshield_setup();	// Initialize motor shield
	delay_init();			// Initialize delay
	
	/* Initialization of 'L' lamp used as a flag */
	ioport_set_pin_dir(PIO_PB27_IDX, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIO_PB27_IDX, 0);
	
	/* Test functions */
	//test_terminal();
	//test_sensor();
	//test_fan();
	//test_uart();
	//test_pin();
	
	/* Task with highest priority */
	if (xTaskCreate(pid_control, (const signed char * const) "PID Control", 1024, NULL, 2, NULL) != pdPASS)
	{
		printf("Failed to create PID Control task\r\n");
	}
	
	/* Task with lower priority */
	if (xTaskCreate(plot_values, (const signed char * const) "Plot Values", 1024, NULL, 1 , NULL) != pdPASS)
	{
		printf("Failed to create Plot Values task\r\n");
	}
	
	/* Start the FreeRTOS scheduler running all tasks indefinitely */
	vTaskStartScheduler();
}
