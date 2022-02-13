################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripheral/src/CORDIC.c \
../Peripheral/src/DAC.c \
../Peripheral/src/LED.c \
../Peripheral/src/UART.c \
../Peripheral/src/dma.c \
../Peripheral/src/fmac.c \
../Peripheral/src/init_timers.c \
../Peripheral/src/vrefbuf.c 

OBJS += \
./Peripheral/src/CORDIC.o \
./Peripheral/src/DAC.o \
./Peripheral/src/LED.o \
./Peripheral/src/UART.o \
./Peripheral/src/dma.o \
./Peripheral/src/fmac.o \
./Peripheral/src/init_timers.o \
./Peripheral/src/vrefbuf.o 

C_DEPS += \
./Peripheral/src/CORDIC.d \
./Peripheral/src/DAC.d \
./Peripheral/src/LED.d \
./Peripheral/src/UART.d \
./Peripheral/src/dma.d \
./Peripheral/src/fmac.d \
./Peripheral/src/init_timers.d \
./Peripheral/src/vrefbuf.d 


# Each subdirectory must supply rules for building sources it contributes
Peripheral/src/%.o: ../Peripheral/src/%.c Peripheral/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/SW_Fucntions/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/FreeRTOS_Source/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

