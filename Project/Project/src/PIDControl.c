/*
* PIDControl.c
* Created: 11/28/2016 17:37:26
* Author: Nadia
*/

#include <asf.h>
#include "PIDControl.h"
#include "Motorshield.h"
#include "PWMFunctions.h"
#include "SensorFunctions.h"
#include "GlobalVariables.h"

uint8_t setpoint;
double Kp;
double Ti;
double Td;
double dT;
int16_t PID;
int16_t error;
uint16_t current_value;

int proportional = 0;
int32_t sum;
int16_t prev_error = 0;
uint16_t integral = 0;
uint16_t derivate = 0;

/* PID control */
void pid_control(void *p)
{	
	portTickType xLastWakeTime;
	portTickType xTimeIncrement = 100;		//ms
	xLastWakeTime = xTaskGetTickCount();
	
	while(1)
	{
		vTaskDelayUntil( &xLastWakeTime, xTimeIncrement); /* Wait for the next cycle */
		if(ioport_get_pin_level(PIO_PB27_IDX)==1)
		{
			//printf("%d\n", ioport_get_pin_level(PIO_PB27_IDX));
			current_value = sensor_read();
			error = setpoint - current_value;
			
			sum = (sum + prev_error);
			integral = (sum * (dT/Ti));
			derivate = ((Td/dT) * (error - prev_error));
			PID = (Kp* (error + integral + derivate))*100;
			prev_error = error;
			//printf("C: %d, E: %d, P: %d\n", current_value, error, PID);
			
			if(PID > 800)
			{
				PID = 800;
			}
			if(PID < 0)
			{
				PID = 0;
			}
			pwm_update(PID);
			//printf("PID: %d\n", PID);
		}
	}
}
