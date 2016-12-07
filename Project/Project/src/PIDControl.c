/*
* PIDControl.c
* Created: 11/28/2016 17:37:26
* Author: Nadia, Elvin
*/

#include <asf.h>
#include "PIDControl.h"
#include "Motorshield.h"
#include "PWMFunctions.h"
#include "SensorFunctions.h"
#include "GlobalVariables.h"

uint16_t setpoint;
double Kp;
double Ti;
double Td;
double dT;
int16_t PID;
int16_t error;
uint16_t current_value;

int32_t sum;
int16_t prev_error = 0;
uint16_t proportional = 0;
uint16_t integral = 0;
uint16_t derivative = 0;

/* Task 1 (high priority)
* PID regulator
*/
void pid_control(void *p)
{	
	portTickType xLastWakeTime;
	portTickType xTimeIncrement = 100;	//ms
	xLastWakeTime = xTaskGetTickCount();
	
	while(1)
	{
		vTaskDelayUntil( &xLastWakeTime, xTimeIncrement);
		
		/* Start PID regulator if flag ('L' lamp) is 1 (parameters set) */
		if(ioport_get_pin_level(PIO_PB27_IDX)==1)
		{
			current_value = sensor_read();
			error = setpoint - current_value;
			
			/* Sum of P */
			proportional = Kp * error;
			
			/* Sum of I */
			sum = (sum + prev_error);
			integral = Kp * ((sum*dT)/Ti);
						
			/* Sum of D */
			derivative = Kp * ((Td/dT) * (error - prev_error));
			
			/* Control signal of PID */
			PID = proportional + integral + derivative;
			
			prev_error = error;
			//printf("C: %d, E: %d, P: %d\n", current_value, error, PID);	// Used for testing and debugging
			
			/* Anti-windup */
			if(PID > 100)
			{
				PID = 100;	
			}
			if(PID < 0)
			{
				PID = 0;
			}
			pwm_update(PID);
		}
	}
}
