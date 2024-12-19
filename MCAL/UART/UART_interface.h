/*
 * UART_interface.h
 *
 *  Created on: Sep 4, 2024
 *      Author: DELL
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit();
void UART_voidSendData(u8 Copy_u8Data);
u8 UART_u8ReceiveData();
void UART_voidSendNumber(u32 Copy_u32Number);

#endif /* UART_INTERFACE_H_ */
