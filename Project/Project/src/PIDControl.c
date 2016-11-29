/*
 * PIDControl.c
 *
 * Created: 11/28/2016 17:37:26
 *  Author: Nadia
 */ 

#include <asf.h>
#include "PIDControl.h"
#include "Motorshield.h"
#include "PWMFunctions.h"
#include "SensorFunctions.h"
#include "GlobalVariables.h"


int proportional = 0;
uint16_t setpoint = 40;
double dT;
double Kp = 0.58;
double Ti;
double Td;
int16_t PID;
int16_t error;
uint16_t current_value;


void pid_control(void *p)
{	
	portTickType xLastWakeTime;
	portTickType xTimeIncrement = 100;
	xLastWakeTime = xTaskGetTickCount();
	
	while(1)
	{
		vTaskDelayUntil( &xLastWakeTime, xTimeIncrement); /* Wait for the next cycle */
		
		current_value = sensor_read();
		error = setpoint - current_value;
		proportional= (Kp*error*100);
		
		if(proportional > 1000)
		{
			proportional = 1000;
		}
		if(proportional < 0)
		{
			proportional = 0;
		}
		pwm_update(proportional);
		printf("C: %d, E: %d, P: %d\n", current_value, error, proportional);
	}
}
