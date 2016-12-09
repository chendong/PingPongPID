/*
 * PWMFunctions.h
 *
 * Created: 11/28/2016 14:45:36
 * Author: Nadia Manoh and Elvin Lapovski
 */ 

#ifndef PWMFUNCTIONS_H_
#define PWMFUNCTIONS_H_

#define PWM_CHANNEL	PWM_CHANNEL_0

void pwm_setup(void);
void pwm_update(int duty_cycle);

#endif /* PWMFUNCTIONS_H_ */