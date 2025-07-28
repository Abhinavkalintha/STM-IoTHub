################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/SD/fatfs_sd.c \
../Core/Src/SD/user_diskio.c 

OBJS += \
./Core/Src/SD/fatfs_sd.o \
./Core/Src/SD/user_diskio.o 

C_DEPS += \
./Core/Src/SD/fatfs_sd.d \
./Core/Src/SD/user_diskio.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/SD/%.o Core/Src/SD/%.su Core/Src/SD/%.cyclo: ../Core/Src/SD/%.c Core/Src/SD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSSD1306_INCLUDE_FONT_6x8 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Core/Inc/SSD1306 -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Core/Inc/BME680 -I../Core/Inc/RELAY -I../Core/Inc/WIFI -I../Core/Inc/PZEM004T -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Core/Inc/SD -I../Core/Inc/TASKS -I../Core/Inc/BLYNK -I../Core/Src/BLYNK/Blynk -I../Core/Src/BLYNK -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-SD

clean-Core-2f-Src-2f-SD:
	-$(RM) ./Core/Src/SD/fatfs_sd.cyclo ./Core/Src/SD/fatfs_sd.d ./Core/Src/SD/fatfs_sd.o ./Core/Src/SD/fatfs_sd.su ./Core/Src/SD/user_diskio.cyclo ./Core/Src/SD/user_diskio.d ./Core/Src/SD/user_diskio.o ./Core/Src/SD/user_diskio.su

.PHONY: clean-Core-2f-Src-2f-SD

