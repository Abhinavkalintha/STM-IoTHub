################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/BME680/bme680_app.c \
../Core/Src/BME680/bme680_user.c \
../Core/Src/BME680/bme68x.c 

OBJS += \
./Core/Src/BME680/bme680_app.o \
./Core/Src/BME680/bme680_user.o \
./Core/Src/BME680/bme68x.o 

C_DEPS += \
./Core/Src/BME680/bme680_app.d \
./Core/Src/BME680/bme680_user.d \
./Core/Src/BME680/bme68x.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/BME680/%.o Core/Src/BME680/%.su Core/Src/BME680/%.cyclo: ../Core/Src/BME680/%.c Core/Src/BME680/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSSD1306_INCLUDE_FONT_6x8 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Core/Inc/SSD1306 -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Core/Inc/BME680 -I../Core/Inc/RELAY -I../Core/Inc/WIFI -I../Core/Inc/PZEM004T -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Core/Inc/SD -I../Core/Inc/TASKS -I../Core/Inc/BLYNK -I../Core/Src/BLYNK/Blynk -I../Core/Src/BLYNK -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-BME680

clean-Core-2f-Src-2f-BME680:
	-$(RM) ./Core/Src/BME680/bme680_app.cyclo ./Core/Src/BME680/bme680_app.d ./Core/Src/BME680/bme680_app.o ./Core/Src/BME680/bme680_app.su ./Core/Src/BME680/bme680_user.cyclo ./Core/Src/BME680/bme680_user.d ./Core/Src/BME680/bme680_user.o ./Core/Src/BME680/bme680_user.su ./Core/Src/BME680/bme68x.cyclo ./Core/Src/BME680/bme68x.d ./Core/Src/BME680/bme68x.o ./Core/Src/BME680/bme68x.su

.PHONY: clean-Core-2f-Src-2f-BME680

