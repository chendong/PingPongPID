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




int main (void)
{
	sysclk_init();			// Initialize system clock
	board_init();			// Initialize Arduino Due board
	configure_console();	// Initialize terminal window
	adc_setup();			// Initialize ADC
	pwm_setup();			// Initialize PWM
	motorshield_setup();	// Initialize motor shield
	delay_init();			// Initialize delay


	//test_terminal();
	//test_sensor();
	//test_fan();
	
	//while(1)
	//{
		//sensor_read();
	//}
	
	//pid_control();
	


	/* Create the first task for monitoring the procesor activity */
	if (xTaskCreate(pid_control, (const signed char * const) "PID Control", 1024, NULL, 1, NULL) != pdPASS)
	{
		printf("Failed to create PID Control task\r\n");
	}
		
	
	/* Start the FreeRTOS scheduler running all tasks indefinitely*/
	vTaskStartScheduler();
}
