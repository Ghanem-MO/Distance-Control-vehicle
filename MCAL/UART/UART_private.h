/*
 * UART_private.h
 *
 *  Created on: Sep 4, 2024
 *      Author: DELL
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UBRRL      *((volatile u8*)0x29)

#define UDR      *((volatile u8*)0x2c)
#define UCSRA     *((volatile u8*)0x2b)
#define UCSRB      *((volatile u8*)0x2a)
#define UCSRC     *((volatile u8*)0x40)

#endif /* UART_PRIVATE_H_ */
