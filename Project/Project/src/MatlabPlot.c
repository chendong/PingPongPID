/*
* MatlabPlot.c
*
* Created: 11/29/2016 13:04:47
*  Author: Nadia, Elvin
*/

#include <asf.h>
#include "io_uart.h"
#include "MatlabPlot.h"
#include "GlobalVariables.h"
#include "io_uart.h"

uint16_t setpoint;
double Kp;
double Ti;
double Td;
double dT;

/* Task 2 (low priority)
* Used to set the values for parameters setpoint, Kp, Ti, Td and dT from MATLAB.
* If the values are set this task starts sending values to MATLAB for plotting
*/
void plot_values(void *p)
{
	portTickType xLastWakeTime;
	portTickType xTimeIncrement = 100;	//ms
	xLastWakeTime = xTaskGetTickCount();
	uart_setup();

	while(1)
	{
		if(uart_receiver_ready())
		{
			if(read_uart() == 1)
			{
				/* Set parameters if flag ('L' lamp) is 0 */
				if(ioport_get_pin_level(PIO_PB27_IDX)==0)
				{ 
					setpoint = read_int();
					Kp = read_double();
					Ti = read_double();
					Td = read_double();
					dT = read_double();
										
					/* Turns on 'L' lamp on Arduino when values are set */
					ioport_set_pin_dir(PIO_PB27_IDX, IOPORT_DIR_OUTPUT);
					ioport_set_pin_level(PIO_PB27_IDX, 1);
				}
			}
		}
		
		/* Plot values in realtime */
		else if(ioport_get_pin_level(PIO_PB27_IDX)==1)
		{
			/* Creates an empty string with 10 characters */
			char matlabStr[10];
			
			/* Converts the value from PID, error and current_value from int to string and assigns it to matlabStr */
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