################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_Source/portable/GCC/ARM_CM4F/croutine.c \
../FreeRTOS_Source/portable/GCC/ARM_CM4F/event_groups.c \
../FreeRTOS_Source/portable/GCC/ARM_CM4F/list.c \
../FreeRTOS_Source/portable/GCC/ARM_CM4F/port.c \
../FreeRTOS_Source/portable/GCC/ARM_CM4F/queue.c \
../FreeRTOS_Source/portable/GCC/ARM_CM4F/stream_buffer.c \
../FreeRTOS_Source/portable/GCC/ARM_CM4F/tasks.c \
../FreeRTOS_Source/portable/GCC/ARM_CM4F/timers.c 

OBJS += \
./FreeRTOS_Source/portable/GCC/ARM_CM4F/croutine.o \
./FreeRTOS_Source/portable/GCC/ARM_CM4F/event_groups.o \
./FreeRTOS_Source/portable/GCC/ARM_CM4F/list.o \
./FreeRTOS_Source/portable/GCC/ARM_CM4F/port.o \
./FreeRTOS_Source/portable/GCC/ARM_CM4F/queue.o \
./FreeRTOS_Source/portable/GCC/ARM_CM4F/stream_buffer.o \
./FreeRTOS_Source/portable/GCC/ARM_CM4F/tasks.o \
./FreeRTOS_Source/portable/GCC/ARM_CM4F/timers.o 

C_DEPS += \
./FreeRTOS_Source/portable/GCC/ARM_CM4F/croutine.d \
./FreeRTOS_Source/portable/GCC/ARM_CM4F/event_groups.d \
./FreeRTOS_Source/portable/GCC/ARM_CM4F/list.d \
./FreeRTOS_Source/portable/GCC/ARM_CM4F/port.d \
./FreeRTOS_Source/portable/GCC/ARM_CM4F/queue.d \
./FreeRTOS_Source/portable/GCC/ARM_CM4F/stream_buffer.d \
./FreeRTOS_Source/portable/GCC/ARM_CM4F/tasks.d \
./FreeRTOS_Source/portable/GCC/ARM_CM4F/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Source/portable/GCC/ARM_CM4F/%.o: ../FreeRTOS_Source/portable/GCC/ARM_CM4F/%.c FreeRTOS_Source/portable/GCC/ARM_CM4F/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/SW_Fucntions/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/FreeRTOS_Source/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

