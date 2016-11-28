/**
 * main.c
 *
 *  Author: Nadia, Elvin
 *
 */

#include <asf.h>
#include <conf_board.h>
#include "ConsoleFunctions.h"


int main (void)
{
	sysclk_init();	
	board_init();
	configure_console();

	// Insert application code here, after the board has been initialized.
	
	
	/* Test terminal window */
	while(1)
	{	
		printf("Hej\n");
	}
}
