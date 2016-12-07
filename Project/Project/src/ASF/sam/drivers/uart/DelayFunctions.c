/*
 * DelayFunctions.c
 *
 * Created: 11/28/2016 15:37:51
 *  Author: Nadia, Elvin
 */ 

#include "asf.h"
#include "DelayFunctions.h"

int delay_init(void)
{
	pmc_enable_periph_clk(ID_TC0);
	tc_init(TC0,0,0);
	tc_set_block_mode(TC0,0);
	tc_stop(TC0,0);
	return 0;
}


void delay(uint32_t us)
{
	tc_start(TC0, 0);
	while(tc_read_cv(TC0,0) < us*42)
	{
		/* Do nothing */
	}
	tc_stop(TC0,0);
}