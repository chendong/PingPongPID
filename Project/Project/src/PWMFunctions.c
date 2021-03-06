/*
 * PWMFunctions.c
 *
 * Created: 11/28/2016 14:44:40
 * Author: Nadia Manoh and Elvin Lapovski
 */ 

#include <asf.h>
#include <inttypes.h>
#include <stdio.h>
#include "PWMFunctions.h"

static pwm_channel_t pwm_channel_instance;			// Define the PWM channel instance in order to configure channel

/* Initialize PWM for pin DAC1 */
void pwm_setup(void)
{
	pmc_enable_periph_clk(ID_PWM);					// Enable the module clock for PWM peripheral
	pwm_channel_disable(PWM, PWM_CHANNEL);			// Disable channel 0	
	pwm_clock_t clock_setting = {					// Setup clock for PWM module
		.ul_clka = 1000 * 100,						// Clock A is configured, frequency = 1KHz, fan power = 0-100
		.ul_clkb = 0,								// Clock B is not used
		.ul_mck = sysclk_get_cpu_hz()				// System main clock
	};
	pwm_init(PWM, &clock_setting);
	
	pwm_channel_instance.ul_prescaler = PWM_CMR_CPRE_CLKA;			// Clock A as source clock
	pwm_channel_instance.ul_period = 100;
	pwm_channel_instance.ul_duty = 0;
	pwm_channel_instance.channel = PWM_CHANNEL;						// Configure channel 0
	
	pwm_channel_init(PWM, &pwm_channel_instance);					// Initialize channel instance
	pio_set_peripheral(PIOB, PIO_PERIPH_B, PIO_PB16B_PWML0);		// Setup PWM for pin DAC1
	pwm_channel_enable(PWM, PWM_CHANNEL);							// Enable channel 0
}

/* Update duty cycle */
void pwm_update(int duty_cycle)
{
	pwm_channel_update_duty(PWM, &pwm_channel_instance, duty_cycle);
}