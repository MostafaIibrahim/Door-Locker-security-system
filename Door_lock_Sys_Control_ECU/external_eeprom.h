/*************************************************************************************************
 * File Name: eeprom.h                                                                           *
 * Name: Mustafa Ibrahim                                                                         *
 * Created on: Apr 27, 2023                                                                      *
 * Description: Header file for E2PROM driver                                                    *
 *************************************************************************************************/

#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_
#include "std_types.h"
/*************************************************************************************************
 *                                    Static configuration                                       *
 *************************************************************************************************/
#define ERROR    0
#define SUCCESS    1
/*************************************************************************************************
 *                                    FUNCTIONS PROTOTYPE                                        *
 *************************************************************************************************/
uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data);
uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data);
uint8 EEPROM_readArray(uint16 u16addr,uint8 *ptr2array,uint8 size);



#endif /* EXTERNAL_EEPROM_H_ */
