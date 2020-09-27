################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/src/system_stm32f3xx.c 

OBJS += \
./CMSIS/src/system_stm32f3xx.o 

C_DEPS += \
./CMSIS/src/system_stm32f3xx.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/src/system_stm32f3xx.o: ../CMSIS/src/system_stm32f3xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F302R8Tx -DSTM32F3 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/testProj8/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/testProj8/FreeRTOS_Source/include" -I"C:/Users/Admin/Desktop/GaNFET-ESC/testProj8/Code/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/src/system_stm32f3xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

