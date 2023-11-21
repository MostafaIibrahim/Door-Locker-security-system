	/*----------------------------------------------------------------------------------------------
 * File Name:    pwm.c                                                                         *
 * Author:       Mustafa Ibrahim                                                               *
 * Data Created: Apr 4, 2023                                                                   *
 * Description:  source file for the ATmega32 pwm driver.                                      *
 *---------------------------------------------------------------------------------------------*/
#include "pwm.h"
#include "common_macros.h"
#include "gpio.h"
#include<avr/io.h>

/***********************************************************************************************
 *                                 Functions Definitions                                       *
 ***********************************************************************************************/

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
void PWM_Timer0_Start(uint8 duty_cycle)
{
	/* Setup the direction for OC0 as output pin through the GPIO driver. */
	GPIO_setupPinDirection(PWM_PORT_ID, PWM_PIN_ID,PIN_OUTPUT);
	/*
	 * Setup the PWM mode with Non-Inverting.
	 * Setup the prescaler with F_CPU/8.
	 */
	TCCR0 = (1<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<CS01);
	/* Initial value of Timer0 register */
	TCNT0 = 0;
	/*
	 * Setup the compare value based on the required input duty cycle.
	 */
	OCR0 = (uint8) ( ((uint16) duty_cycle * PWM_TIMER0_MAX_VALUE) / 100 );

}
