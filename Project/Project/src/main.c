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
	//uart_config(115200);

	//test_terminal();
	//test_sensor();
	//test_fan();
	//test_uart();

	
	//while(1)
	//{
		//sensor_read();
	//}
	
	//pid_control();
	
	/* Create the first task for monitoring the processor activity */
	if (xTaskCreate(pid_control, (const signed char * const) "PID Control", 1024, NULL, 2, NULL) != pdPASS)
	{
		printf("Failed to create PID Control task\r\n");
	}
	
	if (xTaskCreate(plot_values, (const signed char * const) "Plot Values", 1024, NULL, 1, NULL) != pdPASS)
	{
		printf("Failed to create PID Control task\r\n");
	}
	//
	///* Start the FreeRTOS scheduler running all tasks indefinitely*/
	vTaskStartScheduler();
}
