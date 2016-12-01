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

uint8_t valuesSet = 0;
uint8_t done = 112;

void plot_values(void *p){
	portTickType xLastWakeTime;
	portTickType xTimeIncrement = 100;		//ms
	xLastWakeTime = xTaskGetTickCount();
	
	uart_config(115200);

	while(1)
	{
		vTaskDelayUntil(&xLastWakeTime, xTimeIncrement);
		while(uart_receiver_ready())
		{
			//uint8_t done = 112;
			char matlabStr[10];
			sprintf(matlabStr, "%d", done);
			printf("%s\n",matlabStr);
		}
		
		
		//while(!uart_receiver_ready());
		//ioport_set_pin_dir(PIO_PB26_IDX, IOPORT_DIR_INPUT);
		//ioport_set_pin_level(PIO_PB26_IDX, 1);
		//if(valuesSet == 0){
		//setpoint = read_double();
		//Kp = read_double();
		//Ti = read_double();
		//Td = read_double();
		//dT = read_double();
		//
		//// TX-lamp on indicates that the values are set
		//ioport_set_pin_dir(PIO_PC30_IDX, IOPORT_DIR_INPUT);
		//ioport_set_pin_level(PIO_PC30_IDX, 1);
		//
		//valuesSet = 1;
		//}
		//else if(valuesSet == 1){
		//char matlabStr[10];
		//sprintf(matlabStr, "%d", PID);
		//printf("%s\n",matlabStr);
		//sprintf(matlabStr, "%d", error);
		//printf("%s\n",matlabStr);
		//sprintf(matlabStr, "%d", current_value);
		//printf("%s\n",matlabStr);
		//}
		
	}
	
}