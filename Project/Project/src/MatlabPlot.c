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

uint8_t valuesSet = 0;

void plot_values(void *p){
	portTickType xLastWakeTime;
	portTickType xSampleTime;
	xLastWakeTime = xTaskGetTickCount();
	xSampleTime = 100;

	while(1){
		vTaskDelayUntil(&xLastWakeTime, xSampleTime);
		//if(valuesSet == 0){
			//setpoint = read_double();
			//Kp = read_double();
			//Ti = read_double();
			//Td = read_double();
			//dT = read_double();
//
			//valuesSet = 1;
		//}
		//else{
			char matlabStr[10];
			sprintf(matlabStr, "%d", PID);
			printf("%s\n",matlabStr);
			sprintf(matlabStr, "%d", error);
			printf("%s\n",matlabStr);
			sprintf(matlabStr, "%d", current_value);
			printf("%s\n",matlabStr);
		//}
	}
}