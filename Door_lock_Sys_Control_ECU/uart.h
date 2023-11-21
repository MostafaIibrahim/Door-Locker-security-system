/*
 * usart.h
 *
 *  Created on: Apr 11, 2023
 *      Author: SOFT ZONE
 */

#ifndef UART_H_
#define UART_H_
#include"std_types.h"

/********************************************************************************************
 *                               User Define type declaration                               *
 ********************************************************************************************/
typedef enum{
	DISABLE,ENABLE_EVEN=2,ENABLE_ODD
}UART_ParityMode;

typedef enum{
	ONE_BIT,TWO_BIT
}UART_StopBit;

typedef enum{
	FIVE_BIT,SIX_BIT,SEVEN_BIT,EIGHT_BIT,NINE_BIT=7
}UART_CharacterSize;

typedef struct{
	UART_ParityMode     parity;
	UART_StopBit        stop_bit;
	UART_CharacterSize  bit_size;
	uint32              baud_rate;
}UART_ConfigType;

/********************************************************************************************
 *                               Functions Prototypes                                       *
 ********************************************************************************************/
/*
 * Description:
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART_init(const UART_ConfigType* config_type);
/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const uint8 byte);
/*
 * Description :
 * Functional responsible for receive byte to another UART device.
 */
uint8 UART_receiveByte(void);
/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *str);
/*
 * Description:
 *
 */
void UART_receiveString(uint8 *str);
#endif /* UART_H_ */
