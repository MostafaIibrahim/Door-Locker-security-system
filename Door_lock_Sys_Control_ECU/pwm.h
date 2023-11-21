/*----------------------------------------------------------------------------------------------
 * File Name:    pwm.h                                                                         *
 * Author:       Mustafa Ibrahim                                                               *
 * Data Created: Apr 4, 2023                                                                   *
 * Description:  header file for the ATmega32 pwm driver.                                      *
 *---------------------------------------------------------------------------------------------*/

#ifndef PWM_H_
#define PWM_H_
#include"std_types.h"

#define PWM_PORT_ID             PORTB_ID
#define PWM_PIN_ID              PIN3_ID

#define PWM_TIMER0_MAX_VALUE    255
/**********************************************************************************************
 *                                 Functions Prototypes                                       *
 **********************************************************************************************/

/*
 * Description:
 *  The function responsible for trigger the Timer0 with the PWM Mode.
 *  Setup the PWM mode with Non-Inverting.
 *  Setup the prescaler with F_CPU/8.
 *  Setup the compare value based on the required input duty cycle.
 *  Setup the direction for OC0 as output pin through the GPIO driver.
 *  The generated PWM signal frequency will be 500Hz to control the DC Motor speed.
 * Input:
 *  duty_cycle: The required duty cycle percentage of the generated PWM signal.
 *   Its value should be from 0 → 100.
 * Return:
 *  None.
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
