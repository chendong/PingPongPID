/*
 * GlobalVariables.h
 *
 * Created: 11/29/2016 13:29:01
 *  Author: Nadia, Elvin
 */ 


#ifndef GLOBALVARIABLES_H_
#define GLOBALVARIABLES_H_

/* Hold variables that is sent between Arduino and MATLAB as well as between PIDControl.c and MatlabPlot.c */
extern uint16_t setpoint;
extern double dT;
extern double Kp;
extern double Ti;
extern double Td;
extern int16_t PID;
extern int16_t error;
extern uint16_t current_value;

#endif /* GLOBALVARIABLES_H_ */