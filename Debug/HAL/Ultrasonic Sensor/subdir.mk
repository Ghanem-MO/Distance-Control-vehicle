################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Ultrasonic\ Sensor/Ultrasonic_Sensor.c 

OBJS += \
./HAL/Ultrasonic\ Sensor/Ultrasonic_Sensor.o 

C_DEPS += \
./HAL/Ultrasonic\ Sensor/Ultrasonic_Sensor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Ultrasonic\ Sensor/Ultrasonic_Sensor.o: ../HAL/Ultrasonic\ Sensor/Ultrasonic_Sensor.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"HAL/Ultrasonic Sensor/Ultrasonic_Sensor.d" -MT"HAL/Ultrasonic\ Sensor/Ultrasonic_Sensor.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


