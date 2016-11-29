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


uint16_t setpoint = 40; //40
double dT = 0.1; //0.1
double Kp = 0.348; // 0.203; //0.348
double Ti = 1.4;//2.156;//0.7; //1.4
double Td = 0.35; //0.532; //0.35
int16_t PID;
int16_t error;
uint16_t current_value;

//T0 (period time) = 2.8 seconds for P regulation
int proportional = 0;
int32_t sum;
int16_t prev_error = 0;
uint16_t integral = 0;
uint16_t derivate = 0;


void pid_control(void *p)
{	
	portTickType xLastWakeTime;
	portTickType xTimeIncrement = 100;		//ms
	xLastWakeTime = xTaskGetTickCount();
	
	while(1)
	{
		vTaskDelayUntil( &xLastWakeTime, xTimeIncrement); /* Wait for the next cycle */
		
		current_value = sensor_read();
		error = setpoint - current_value;
		
		sum = (sum + prev_error);
		integral = (sum * (dT/Ti));
		derivate = ((Td/dT) * (error - prev_error));
		PID = (Kp* (error + integral + derivate))*100;
		prev_error = error;
		printf("C: %d, E: %d, P: %d\n", current_value, error, PID);
		
		if(PID > 800)
		{
			PID = 800;
		}
		if(PID < 0)
		{
			PID = 0;
		}
		pwm_update(PID);
		printf("PID: %d\n", PID);
		
	}
}
