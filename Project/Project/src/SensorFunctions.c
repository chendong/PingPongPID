/*
 * SensorFunctions.c
 *
 * Created: 11/28/2016 14:26:32
 *  Author: Nadia,Elvin
 */ 

#include <asf.h>
#include <inttypes.h>
#include "SensorFunctions.h"


/* Initialize ADC for pin A8 */
void adc_setup(void)
{
	pmc_enable_periph_clk(ID_ADC);							// Enable specified peripheral clock
	
	adc_init(ADC, sysclk_get_main_hz(), 1000000, 8);		// Initialize the given ADC with the specified ADC clock and startup time
															// sysclk_get_main_hz() is used to get master clock frequency
															// ADC_CLOCK gives the ADC clock frequency
	adc_configure_timing(ADC, 0, ADC_SETTLING_TIME_3, 1);	// Configure ADC timing
	adc_set_resolution(ADC, ADC_MR_LOWRES_BITS_12);			// Set ADC resolution with 12 bits, 2^12 = 4096 (voltage read converted to number between 0-4095)
	adc_enable_channel(ADC, ADC_CHANNEL_10);				// Enable specified ADC channel (pin A8)
	adc_configure_trigger(ADC, ADC_TRIG_SW, 0);				// Configure software conversion trigger
}


/* Read sensor value */

/*
* <= 50cm =	1850	min value
* 50-45cm = 1760
* 45-40cm = 1660
* 40-35cm = 1510
* 35-30cm = 1380	max value
*/
uint16_t sensor_read(void)
{
	uint16_t distance = 0;	
	
	while(1)
	{	
		adc_start(ADC);
		uint16_t sensor_value = adc_get_channel_value(ADC, ADC_CHANNEL_10);
		//printf("sensor: %d\n", sensor_value);
	
		if(sensor_value > 1890)
		{
			distance = 30;
		}
		else if(sensor_value < 1890 && sensor_value >= 1850)
		{
			distance = 35;
		}
		else if(sensor_value < 1850 && sensor_value >= 1780)
		{
			distance = 40;
		}
		else if(sensor_value < 1780 && sensor_value >= 1690)
		{
			distance = 45;
		}	
		else if(sensor_value < 1690)	// && sensor_value >= 1800
		{
			distance = 50;
		}
		//printf("Sensor value: %d, Distance: %d\n", sensor_value, distance);
		return distance;
		
	}
	
}

