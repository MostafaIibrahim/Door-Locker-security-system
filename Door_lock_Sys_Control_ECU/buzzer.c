/*----------------------------------------------------------------------------------------------
 * File Name:    buzzer.c                                                                      *
 * Author:       Mustafa Ibrahim                                                               *
 * Data Created: May 17, 2023                                                                  *
 * Description:  source file for the ATmega32 Buzzer driver.                                   *
 *---------------------------------------------------------------------------------------------*/
#include "buzzer.h"
#include "gpio.h"

/***********************************************************************************************
 *                                 Functions Definitions                                       *
 ***********************************************************************************************/
/*
 * Description:
 *  Setup the direction for the buzzer pin as output pin through the GPIO driver.
 *  Turn off the buzzer through the GPIO.
 * Input: None
 * Return: None
 */
void Buzzer_init(){
	GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}
/*
 * Description:
 *  Function to enable the Buzzer through the GPIO.
 * Input:None
 * Return:None
 */
void Buzzer_on(void){
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_HIGH);
}
/*
 * Description:
 *  Function to disable the Buzzer through the GPIO.
 * Input:None
 * Return: None
 */
void Buzzer_off(void){
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}


