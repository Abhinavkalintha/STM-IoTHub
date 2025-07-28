################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/PZEM004T/pzem004t.c \
../Core/Src/PZEM004T/pzem004t_app.c 

OBJS += \
./Core/Src/PZEM004T/pzem004t.o \
./Core/Src/PZEM004T/pzem004t_app.o 

C_DEPS += \
./Core/Src/PZEM004T/pzem004t.d \
./Core/Src/PZEM004T/pzem004t_app.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/PZEM004T/%.o Core/Src/PZEM004T/%.su Core/Src/PZEM004T/%.cyclo: ../Core/Src/PZEM004T/%.c Core/Src/PZEM004T/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSSD1306_INCLUDE_FONT_6x8 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Core/Inc/SSD1306 -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Core/Inc/BME680 -I../Core/Inc/RELAY -I../Core/Inc/WIFI -I../Core/Inc/PZEM004T -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Core/Inc/SD -I../Core/Inc/TASKS -I../Core/Inc/BLYNK -I../Core/Src/BLYNK/Blynk -I../Core/Src/BLYNK -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-PZEM004T

clean-Core-2f-Src-2f-PZEM004T:
	-$(RM) ./Core/Src/PZEM004T/pzem004t.cyclo ./Core/Src/PZEM004T/pzem004t.d ./Core/Src/PZEM004T/pzem004t.o ./Core/Src/PZEM004T/pzem004t.su ./Core/Src/PZEM004T/pzem004t_app.cyclo ./Core/Src/PZEM004T/pzem004t_app.d ./Core/Src/PZEM004T/pzem004t_app.o ./Core/Src/PZEM004T/pzem004t_app.su

.PHONY: clean-Core-2f-Src-2f-PZEM004T

