 /*
* TestFunctions.c
* Test if terminal window, fan, sensor and uart works separately
*
* Created: 11/28/2016 15:45:46
* Author: Nadia Manoh and Elvin Lapovski
*/

#include <asf.h>
#include "ConsoleFunctions.h"
#include "SensorFunctions.h"
#include "PWMFunctions.h"
#include "DelayFunctions.h"
#include "TestFunctions.h"
#include "io_uart.h"

/* Self-explanatory functions */
void test_terminal(void)
{
	while(1)
	{
		printf("Hej\n");
	}
	
}

void test_sensor(void)
{
	while(1)
	{
		sensor_read();
	}	
}


//Fan power: 0-100
void test_fan(void)
{
	while(1)
	{
		for(int i = 350; i < 1001; i+=150)
		{
			pwm_update(i);
			printf("Power = %d\n", i);
			delay(5000000);	// 5 seconds
		}
	}
}

void test_uart(void)
{
	while(1)
	{
		if(uart_receiver_ready())
		{
				uint8_t done = 112;
				char matlabStr[10];
				sprintf(matlabStr, "%d", done);
				printf("%s\n",matlabStr);
		}
	}
}
