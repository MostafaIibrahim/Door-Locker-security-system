/*************************************************************************************************
 * File Name: eeprom.c                                                                           *
 * Name: Mustafa Ibrahim                                                                         *
 * Created on: Apr 27, 2023                                                                      *
 * Description: Source file for E2PROM driver                                                    *
 *************************************************************************************************/
#include "external_eeprom.h"

#include "twi.h"

/*************************************************************************************************
 *                                    FUNCTIONS DEFINITION                                       *
 *************************************************************************************************/
uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data)
{
	/* Send start bit */
	TWI_start();
	/* Check status register of I2C if start bit was sent or not */
	if(TWI_getStatus() != TWI_START)
		return ERROR;

	/* Send E2PROM address */
	TWI_writeByte((uint8)(0xA0 | ((u16addr & 0x0700)>>7)));
	/* Check status register of I2C if Master sent slave address and received ACK or not */
	if(TWI_getStatus() != TWI_MT_SLA_W_ACK)
		return ERROR;

	/* Send location address */
    TWI_writeByte((uint8)(u16addr));
	/* Check status register of I2C if Master sent E2PROM word address and received ACK or not */
	if(TWI_getStatus() != TWI_MT_DATA_ACK)
		return ERROR;

	/* Send data */
	TWI_writeByte(u8data);
	if(TWI_getStatus() != TWI_MT_DATA_ACK)
		return ERROR;

	/* Send stop bit */
	TWI_stop();

	return SUCCESS;
}
uint8 EEPROM_readByte(uint16 u16addr, uint8 *u8data)
{
	/* Send the Start Bit */
    TWI_start();
    if (TWI_getStatus() != TWI_START)
        return ERROR;

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
    TWI_writeByte((uint8)((0xA0) | ((u16addr & 0x0700)>>7)));
    if (TWI_getStatus() != TWI_MT_SLA_W_ACK)
        return ERROR;

    /* Send the required memory location address */
    TWI_writeByte((uint8)(u16addr));
    if (TWI_getStatus() != TWI_MT_DATA_ACK)
        return ERROR;

    /* Send the Repeated Start Bit */
    TWI_start();
    if (TWI_getStatus() != TWI_REP_START)
        return ERROR;

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=1 (Read) */
    TWI_writeByte((uint8)((0xA0) | ((u16addr & 0x0700)>>7) | 1));
    if (TWI_getStatus() != TWI_MT_SLA_R_ACK)
        return ERROR;

    /* Read Byte from Memory without send ACK */
    *u8data = TWI_readByteWithNACK();
    if (TWI_getStatus() != TWI_MR_DATA_NACK)
        return ERROR;

    /* Send the Stop Bit */
    TWI_stop();

    return SUCCESS;
}


