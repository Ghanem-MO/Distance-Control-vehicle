

#include "Control_Car.h"
#include <avr/delay.h>

// Global Variables
f32 Glob_f32distance = 0;
u8 Glob_u8Event = 'S';
float last_speed =0;
float distance = 0;
float set_point_distance = 25;
float error = 0;
float Kp = 1, Ki = 0.1, Kd = 0.7;
float last_error = 0, integral = 0;

// Function Prototypes
float computePID(float e);
void APP_Control_Car_Init(void);
void APP_Control_Car_App(void);

// Initialize the car control system
void APP_Control_Car_Init(void) {
    // Initialize peripherals
    HAL_Buzzer_u8BuzzerInit(PortA, Pin3); // Buzzer
    HAL_SM_voidSMInit();                 // Servo Motor
    HAL_Ultrasonic_Sensor_voidInit();    // Ultrasonic Sensor
    HAL_void_H_BridgeInit();             // H-Bridge
    HAL_LED_u8LedInit(PortA, Pin0);      // LED1
    HAL_LED_u8LedInit(PortA, Pin1);      // LED2
    MCAL_UART_UARTInit();
    UART_voidInit();// UART
}

// Compute PID controller output
float computePID(float e) {
    integral += e; // Accumulate the error for the integral term
    float derivative = e - last_error; // Calculate the derivative of the error
    last_error = e;

    // Compute PID output
    return (Kp * e + Ki * integral + Kd * derivative);
}

// u32 Mapping (u32 Range1_max,u32 Range1_min,u32 Range2_max,u32 Range2_min,u32 Range1_reading){

// 	return (Range2_max-((Range2_max-Range2_min)*(Range1_max-Range1_reading)/(Range1_max-Range1_min)));
// }

float MapVel(int max1,int min1, int max2,int min2,float val){
    return (max2 - ((max2 - min2) * (max1 - val) /(max1 -min1)));
}

// Main application logic
void APP_Control_Car_App(void) {
    // Initialize UART
 //   MCAL_UART_UARTInit();
	APP_Control_Car_Init();


    while (1) {
        // Calculate distance using ultrasonic sensor


        HAL_Ultrasonic_Sensor_voidCalcDistancse(&distance);
        // Send distance to UART for debugging
        // Calculate error and compute PID output
        error =  distance - set_point_distance;
        float u = computePID(error);
        float speed = MapVel(200,0,90,14, last_speed - u);
        last_speed = speed;
        if(error<0)
        {
        	HAL_void_H_BridgeBack((int)speed);
        }
        else
        {

        // Control the car using H-Bridge
        HAL_void_H_BridgeFront((int)speed);

        }
        UART_voidSendNumber((u32)distance);
        // Delay for stabilization
        _delay_ms(50);



//        while(distance<10)
//        {
//            HAL_void_H_BridgeStop(0);
//            HAL_Ultrasonic_Sensor_voidCalcDistancse(&distance);
//        }
    }
}
