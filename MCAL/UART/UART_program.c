/*
 * UART_program.c
 *
 *  Created on: Sep 4, 2024
 *      Author: yousef.ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"

void UART_voidInit()
{
    u8 Local_u8CtrlCvalue = 0;
    SET_BIT(Local_u8CtrlCvalue, 7);
    SET_BIT(Local_u8CtrlCvalue, 1);
    SET_BIT(Local_u8CtrlCvalue, 2);
    CLR_BIT(Local_u8CtrlCvalue, 3);
    UCSRC = Local_u8CtrlCvalue;
    // NO INT
    // NO PARITY
    // UART
    // 9600 BaudRate
    UBRRL = 51;
    // Ch size -> 8 bits
    CLR_BIT(UCSRB, 2);
    // Full duplex
    SET_BIT(UCSRB, 3);
    SET_BIT(UCSRB, 4);
}

void UART_voidSendData(u8 Copy_u8Data)
{
    // Polling UDRE -> Send Data
    while (!GET_BIT(UCSRA, 5));
    UDR = Copy_u8Data;
}

u8 UART_u8ReceiveData()
{
    while (!GET_BIT(UCSRA, 7));
    return UDR;
}

void UART_voidSendNumber(u32 Copy_u32Number)
{
    char buffer[11]; // Enough for 10 digits + null terminator for u32
    u8 i = 0;

    // Convert number to string
    if (Copy_u32Number == 0)
    {
        UART_voidSendData('0');
        return;
    }

    while (Copy_u32Number > 0)
    {
        buffer[i++] = (Copy_u32Number % 10) + '0'; // Convert digit to ASCII
        Copy_u32Number /= 10;
    }

    // Send digits in correct order (reverse the string)
    while (i > 0)
    {
        UART_voidSendData(buffer[--i]);
    }
}
