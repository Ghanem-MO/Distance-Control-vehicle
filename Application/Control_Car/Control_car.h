/*
 * Control_car.h
 *
 *  Created on: May 1, 2024
 *      Author: TOP_WORLD
 */

#ifndef APPLICATION_CONTROL_CAR_CONTROL_CAR_H_
#define APPLICATION_CONTROL_CAR_CONTROL_CAR_H_
#include "../../MCAL/UART/UART.h"
#include "../../MCAL/UART/UART_interface.h"
#include "../../HAL/H_Bridge/H_Bridge.h"
#include "../../HAL/Servo Motor/Servo_Motor.h"
#include "../../HAL/Ultrasonic Sensor/Ultrasonic_Sensor.h"
#include "../../HAL/LED/LED.h"
#include "../../HAL/LCD/LCD.h"
#include "../../HAL/Buzzer/Buzzer.h"
#include "../Autonomous_Car/Autonomous_Car.h"
//#include "../../FreeRTOS/FreeRTOS.h"
//#include "../../FreeRTOS/task.h"
#define START_ANGLE 90
#define MAX_CW_ANGLE 180
#define MAX_CCW_ANGLE 0
#define DISTANCE_30 30.0
#define DISTANCE_10 10.0
#define MAX_SPEED 99
#define NUM_2 2
void APP_Control_Car_Init(void) ;
void APP_Control_Car_App(void) ;
#endif /* APPLICATION_CONTROL_CAR_CONTROL_CAR_H_ */
