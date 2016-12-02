/*
* MatlabPlot.c
*
* Created: 11/29/2016 13:04:47
*  Author: Nadia
*/
#include <asf.h>
#include "io_uart.h"
#include "MatlabPlot.h"
#include "GlobalVariables.h"
#include "io_uart.h"

uint8_t setpoint;
double dT;
double Kp;
double Ti;
double Td;

void plot_values(void *p){
	portTickType xLastWakeTime;
	portTickType xTimeIncrement = 100;		//ms
	xLastWakeTime = xTaskGetTickCount();
	setupUART();

	while(1)
	{
		if(uart_receiver_ready())
		{
			if(read_uart() == 1)
			{
				/* Set parameters. */
				if(ioport_get_pin_level(PIO_PB27_IDX)==0)
				{
					Kp = read_double();
					Ti = read_double();
					Td = read_double();
					dT = read_double();
					setpoint = read_int();		
					
					/* Turns on 'L' lamp on arduino when values are set. */
					ioport_set_pin_dir(PIO_PB27_IDX, IOPORT_DIR_OUTPUT);
					ioport_set_pin_level(PIO_PB27_IDX, 1);
				}
			}
		}
		/* Plot values in realtime */
		else if(ioport_get_pin_level(PIO_PB27_IDX)==1)
		{
			char matlabStr[10];
			sprintf(matlabStr, "%d", PID);
			printf("%s\n",matlabStr);
			sprintf(matlabStr, "%d", error);
			printf("%s\n",matlabStr);
			sprintf(matlabStr, "%d", current_value);
			printf("%s\n",matlabStr);
		}
		vTaskDelayUntil(&xLastWakeTime, xTimeIncrement);
	}
}