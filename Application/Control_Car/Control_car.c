/*
 * Control_car.c
 *
 *  Created on: May 1, 2024
 *      Author: TOP_WORLD
 */
#include "Control_Car.h"
f32 Glob_f32distance = 0;
u8 Glob_u8Event = 'S';
void sensor(void *pt);
void lcd_display(void *ptr);
void APP_Control_Car_Init(void) {
	//Init Buzzer
	HAL_Buzzer_u8BuzzerInit(PortA, Pin3);
	//Init LCD
	HAL_LCD_u8LCDInit();
	//Init Servo Motor
	HAL_SM_voidSMInit();
	//Init UltraSonic Sensor
	HAL_Ultrasonic_Sensor_voidInit();
	//Init H_Bridge
	HAL_void_H_BridgeInit();
	//Leds
	HAL_LED_u8LedInit(PortA, Pin0);
	HAL_LED_u8LedInit(PortA, Pin1);
	//UART
	MCAL_UART_UARTInit();
	//Free Rtos
//	xTaskCreate(lcd_display, "lcd_display", 80, 0, 1, 0);
//	xTaskCreate(sensor, "sensor", 80, 0, 1, 0);
//	vTaskStartScheduler();
}
void APP_Control_Car_App(void) {

	//	Initially Set Servo Angle 90
	HAL_SM_voidSMSetAngle(START_ANGLE);
	//Light Front LEDS
	HAL_LED_u8LedMode(PortA, Pin0, LED_ON);
	while (1) {
		MCAL_UART_UARTReceive(&Glob_u8Event);
		if (Glob_u8Event == 'F') {
			//if(Glob_f32distance>30){
			HAL_LED_u8LedMode(PortA, Pin0, LED_ON);
			HAL_LED_u8LedMode(PortA, Pin1, LED_OFF);
			HAL_void_H_BridgeFront(MAX_SPEED);
			//}else{
			//HAL_void_H_BridgeStop(NUM0);
			//}
		} else if (Glob_u8Event == 'B') {
			HAL_void_H_BridgeBack(MAX_SPEED);
			HAL_LED_u8LedMode(PortA, Pin1, LED_ON);
		} else if (Glob_u8Event == 'L') {
			HAL_void_H_BridgeCCW(MAX_SPEED);
		} else if (Glob_u8Event == 'R') {
			HAL_void_H_BridgeCW(MAX_SPEED);
		} else if (Glob_u8Event == 'S') {
			HAL_void_H_BridgeStop(NUM0);
		} else if (Glob_u8Event == 'W') {
			HAL_LED_u8LedMode(PortA, PIN0, LED_ON);
		} else if (Glob_u8Event == 'w') {
			HAL_LED_u8LedMode(PortA, PIN0, LED_OFF);
		} else if (Glob_u8Event == 'U') {
			HAL_LED_u8LedMode(PortA, PIN1, LED_ON);
		} else if (Glob_u8Event == 'u') {
			HAL_LED_u8LedMode(PortA, PIN1, LED_OFF);
		} else if (Glob_u8Event == 'V') {
			HAL_Buzzer_u8BuzzerMode(PortA, Pin3, Buzzer_ON);
		} else if (Glob_u8Event == 'v') {
			HAL_Buzzer_u8BuzzerMode(PortA, Pin3, Buzzer_OFF);
		} else if (Glob_u8Event == 'X') {
			APP_Autonomous_Car_voidApp();
		} else if (Glob_u8Event == 'G') {
			HAL_void_H_BridgeFR();
		} else if (Glob_u8Event == 'I') {
//			HAL_void_H_BridgeCW(99);
//			HAL_void_H_BridgeCCW(60);
		} else if (Glob_u8Event == 'H') {

		} else if (Glob_u8Event == 'J') {

		} else {
			//NOTHING
		}
	}

}
void lcd_display(void *ptr) {
	while (1) {
		switch (Glob_u8Event) {
		case 'F':
			if (Glob_f32distance > 30) {
				HAL_LCD_u8Clear();
				HAL_LCD_u8SendString("Moving Front: ");
				_delay_ms(500);
			} else {
				HAL_LCD_u8Clear();
				HAL_LCD_u8SendString("Stopping!!");
				_delay_ms(500);
			}
			break;
		case 'L':
			HAL_LCD_u8Clear();
			HAL_LCD_u8SendString("Moving Left: ");
			_delay_ms(500);
			break;
		case 'R':
			HAL_LCD_u8Clear();
			HAL_LCD_u8SendString("Moving Right: ");
			_delay_ms(500);
			break;
		case 'S':
			HAL_LCD_u8Clear();
			HAL_LCD_u8SendString("Stopping!!");
			_delay_ms(500);
			break;
		case 'B':
			HAL_LCD_u8Clear();
			HAL_LCD_u8SendString("Moving Back:");
			_delay_ms(500);
			break;
		}
	}
}
void sensor(void *pt) {
	while (1) {
		HAL_Ultrasonic_Sensor_voidCalcDistancse(&Glob_f32distance);
	}
}
