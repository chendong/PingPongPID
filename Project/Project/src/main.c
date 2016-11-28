/**
 * main.c
 *
 *  Author: Nadia, Elvin
 *
 */

#include <asf.h>
#include <conf_board.h>
#include "ConsoleFunctions.h"
#include "SensorFunctions.h"
#include "PWMFunctions.h"
#include "Motorshield.h"
#include "DelayFunctions.h"

void test_subfunction(void);



int main (void)
{
	sysclk_init();	
	board_init();
	configure_console();
	adc_setup();
	pwm_setup();
	motorshield_setup();
	delay_init();


	test_subfunction();	
}


/* Test if terminal window, fan and sensor works separately */
void test_subfunction(void)
{
	
	/* ------------ Test terminal window ---------- */
	//while(1)
	//{
		//printf("Hej\n");
	//}
	/* -------------------------------------------- */
	
	
	/* --------------- Test sensor ---------------- */
	//while(1)
	//{
		//sensor_read();
	//}
	/* -------------------------------------------- */
	
	
	
	//Fan power: 350 - 1000
	/* ---------------- Test fan ------------------ */
	while(1)
	{
		for(int i = 350; i < 1001; i+=150)
		{
			pwm_update(i);
			printf("Power = %d\n", i);
			delay(5000000);		// 5 seconds
		}
	}

	/* -------------------------------------------- */

}