/*----------------------------------------------------------------------------------------------
 * File Name:    buzzer.h                                                                      *
 * Author:       Mustafa Ibrahim                                                               *
 * Data Created: May 17, 2023                                                                  *
 * Description:  header file for the ATmega32 Buzzer driver.                                   *
 *---------------------------------------------------------------------------------------------*/

#ifndef BUZZER_H_
#define BUZZER_H_
#include "std_types.h"

/**********************************************************************************************
 *                                 Static configuration                                       *
 **********************************************************************************************/
#define BUZZER_PORT_ID        PORTC_ID
#define BUZZER_PIN_ID         PIN3_ID
/**********************************************************************************************
 *                                 Functions Prototypes                                       *
 **********************************************************************************************/
/*
 * Description:
 *  Setup the direction for the buzzer pin as output pin through the GPIO driver.
 *  Turn off the buzzer through the GPIO.
 * Input: None
 * Return: None
 */
void Buzzer_init();
/*
 * Description:
 *  Function to enable the Buzzer through the GPIO.
 * Input:None
 * Return:None
 */
void Buzzer_on(void);
/*
 * Description:
 *  Function to disable the Buzzer through the GPIO.
 * Input:None
 * Return: None
 */
void Buzzer_off(void);

#endif /* BUZZER_H_ */
