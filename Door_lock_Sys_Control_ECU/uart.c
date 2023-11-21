/*
 * usart.c
 *
 *  Created on: Apr 11, 2023
 *      Author: SOFT ZONE
 */
#include"uart.h"
#include <avr/io.h>
#include "common_macros.h"

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
void UART_init(const UART_ConfigType* config_type)
{
	uint16 ubrr_value = 0;

	/* Set double transmission speed */
	UCSRA= (1<<U2X);
	/*
	 * 1- Enable receive and transmit.
	 * 2- choose Number of data bits per frame
	 */
	UCSRB = (1<<RXEN) | (1<<TXEN);
	UCSRB =  UCSRB | (config_type->bit_size & 0x04);
	/*
	 * 1-choose parity mode
	 * 2-choose stop bit for frame
	 * 3-choose number of data bits per frame
	 */
	UCSRC = (1<<URSEL) | (config_type->parity<<4) | (config_type->stop_bit<<3) | ((config_type->bit_size & 0x03)<<1);
	/* Calculate the UBRR register value */
	ubrr_value = (uint16)(((F_CPU / (config_type->baud_rate * 8UL))) - 1);
	/*
	 * Choose baud rate:
	 * First 8 bit of ubrr_value in UBRRL
	 * Last 4 bit of ubrr_value in UBRRH
	 */
	UBRRH = ubrr_value>>8;
	UBRRL = ubrr_value;
}
/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const uint8 byte)
{
	/*
	 * UDRE flag is set when the Tx buffer (UDR) is empty and ready for
	 * transmitting a new byte so wait until this flag is set to one
	 */
	while(BIT_IS_CLEAR(UCSRA,UDRE));
	/*
	 * Put the required data in the UDR register and it also clear the UDRE flag as
	 * the UDR register is not empty now
	 */
	UDR = byte;
	/************************* Another Method *************************
	check if TXC flag is set but here .
	 * UDR = byte;
	 * while(BIT_IS_CLEAR(UCSRA,TXC)); // Wait until the transmission is complete TXC = 1
	 * SET_BIT(UCSRA,TXC)); // Clear the TXC flag
	 *******************************************************************/
}
/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_receiveByte(void)
{
	/* RXC flag is set when the UART receive data so wait until this flag is set to one */
	while(BIT_IS_CLEAR(UCSRA,RXC));
	/*
	 * Read the received data from the Rx buffer (UDR)
	 * The RXC flag will be cleared after read the data
	 */
	return UDR;
}
/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *str)
{
	while(*str != '\0')
	{
		UART_sendByte(*str);
		str++;
	}
}
/*
 * Description :
 * Receive the required string through UART to the other UART device.
 */

void UART_receiveString(uint8 *str)
{
	sint8 i = -1 ;
	/* Receive the whole string until the '#' */
	do{
		i++;
		str[i] = UART_receiveByte();
	}while(str[i] != '#');
	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	str[i] = '\0';
	/******************************************************************************
	 *                             Another Method                                 *
	 ******************************************************************************/
	/*uint8 i = 0;                                                                *
	 *	Str[i] = UART_receiveByte();                                              *
	 *	while(Str[i] != '#'){                                                     *
	 *	i++;                                                                      *
	 *	Str[i] = UART_receiveByte();}                                             *
	 *	Str[i] = '\0';                                                            *
	 ******************************************************************************/
}



