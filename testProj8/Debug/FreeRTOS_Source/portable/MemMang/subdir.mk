################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_Source/portable/MemMang/heap_1.c 

OBJS += \
./FreeRTOS_Source/portable/MemMang/heap_1.o 

C_DEPS += \
./FreeRTOS_Source/portable/MemMang/heap_1.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Source/portable/MemMang/heap_1.o: ../FreeRTOS_Source/portable/MemMang/heap_1.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F302R8Tx -DSTM32F3 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/testProj8/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/testProj8/FreeRTOS_Source/include" -I"C:/Users/Admin/Desktop/GaNFET-ESC/testProj8/Code/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS_Source/portable/MemMang/heap_1.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

