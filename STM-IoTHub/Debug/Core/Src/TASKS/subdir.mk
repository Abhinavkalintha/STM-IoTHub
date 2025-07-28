################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/TASKS/alert_task.c \
../Core/Src/TASKS/energy_task.c \
../Core/Src/TASKS/fan_task.c \
../Core/Src/TASKS/light_task.c \
../Core/Src/TASKS/oled_task.c \
../Core/Src/TASKS/pzem_task.c \
../Core/Src/TASKS/relay_automation_task.c \
../Core/Src/TASKS/relay_task.c \
../Core/Src/TASKS/sensor_data.c \
../Core/Src/TASKS/sensor_task.c \
../Core/Src/TASKS/shared_data.c \
../Core/Src/TASKS/uart_ring.c \
../Core/Src/TASKS/wifi_task.c 

OBJS += \
./Core/Src/TASKS/alert_task.o \
./Core/Src/TASKS/energy_task.o \
./Core/Src/TASKS/fan_task.o \
./Core/Src/TASKS/light_task.o \
./Core/Src/TASKS/oled_task.o \
./Core/Src/TASKS/pzem_task.o \
./Core/Src/TASKS/relay_automation_task.o \
./Core/Src/TASKS/relay_task.o \
./Core/Src/TASKS/sensor_data.o \
./Core/Src/TASKS/sensor_task.o \
./Core/Src/TASKS/shared_data.o \
./Core/Src/TASKS/uart_ring.o \
./Core/Src/TASKS/wifi_task.o 

C_DEPS += \
./Core/Src/TASKS/alert_task.d \
./Core/Src/TASKS/energy_task.d \
./Core/Src/TASKS/fan_task.d \
./Core/Src/TASKS/light_task.d \
./Core/Src/TASKS/oled_task.d \
./Core/Src/TASKS/pzem_task.d \
./Core/Src/TASKS/relay_automation_task.d \
./Core/Src/TASKS/relay_task.d \
./Core/Src/TASKS/sensor_data.d \
./Core/Src/TASKS/sensor_task.d \
./Core/Src/TASKS/shared_data.d \
./Core/Src/TASKS/uart_ring.d \
./Core/Src/TASKS/wifi_task.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/TASKS/%.o Core/Src/TASKS/%.su Core/Src/TASKS/%.cyclo: ../Core/Src/TASKS/%.c Core/Src/TASKS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSSD1306_INCLUDE_FONT_6x8 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Core/Inc/SSD1306 -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Core/Inc/BME680 -I../Core/Inc/RELAY -I../Core/Inc/WIFI -I../Core/Inc/PZEM004T -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Core/Inc/SD -I../Core/Inc/TASKS -I../Core/Inc/BLYNK -I../Core/Src/BLYNK/Blynk -I../Core/Src/BLYNK -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-TASKS

clean-Core-2f-Src-2f-TASKS:
	-$(RM) ./Core/Src/TASKS/alert_task.cyclo ./Core/Src/TASKS/alert_task.d ./Core/Src/TASKS/alert_task.o ./Core/Src/TASKS/alert_task.su ./Core/Src/TASKS/energy_task.cyclo ./Core/Src/TASKS/energy_task.d ./Core/Src/TASKS/energy_task.o ./Core/Src/TASKS/energy_task.su ./Core/Src/TASKS/fan_task.cyclo ./Core/Src/TASKS/fan_task.d ./Core/Src/TASKS/fan_task.o ./Core/Src/TASKS/fan_task.su ./Core/Src/TASKS/light_task.cyclo ./Core/Src/TASKS/light_task.d ./Core/Src/TASKS/light_task.o ./Core/Src/TASKS/light_task.su ./Core/Src/TASKS/oled_task.cyclo ./Core/Src/TASKS/oled_task.d ./Core/Src/TASKS/oled_task.o ./Core/Src/TASKS/oled_task.su ./Core/Src/TASKS/pzem_task.cyclo ./Core/Src/TASKS/pzem_task.d ./Core/Src/TASKS/pzem_task.o ./Core/Src/TASKS/pzem_task.su ./Core/Src/TASKS/relay_automation_task.cyclo ./Core/Src/TASKS/relay_automation_task.d ./Core/Src/TASKS/relay_automation_task.o ./Core/Src/TASKS/relay_automation_task.su ./Core/Src/TASKS/relay_task.cyclo ./Core/Src/TASKS/relay_task.d ./Core/Src/TASKS/relay_task.o ./Core/Src/TASKS/relay_task.su ./Core/Src/TASKS/sensor_data.cyclo ./Core/Src/TASKS/sensor_data.d ./Core/Src/TASKS/sensor_data.o ./Core/Src/TASKS/sensor_data.su ./Core/Src/TASKS/sensor_task.cyclo ./Core/Src/TASKS/sensor_task.d ./Core/Src/TASKS/sensor_task.o ./Core/Src/TASKS/sensor_task.su ./Core/Src/TASKS/shared_data.cyclo ./Core/Src/TASKS/shared_data.d ./Core/Src/TASKS/shared_data.o ./Core/Src/TASKS/shared_data.su ./Core/Src/TASKS/uart_ring.cyclo ./Core/Src/TASKS/uart_ring.d ./Core/Src/TASKS/uart_ring.o ./Core/Src/TASKS/uart_ring.su ./Core/Src/TASKS/wifi_task.cyclo ./Core/Src/TASKS/wifi_task.d ./Core/Src/TASKS/wifi_task.o ./Core/Src/TASKS/wifi_task.su

.PHONY: clean-Core-2f-Src-2f-TASKS

