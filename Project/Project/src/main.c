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

void test_subfunction(void);



int main (void)
{
	sysclk_init();	
	board_init();
	configure_console();
	adc_setup();


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
	while(1)
	{
		sensor_read();
	}
	/* -------------------------------------------- */
}