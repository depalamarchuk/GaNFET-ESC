################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Code/src/libPWM.c \
../Code/src/libUART.c \
../Code/src/main.c \
../Code/src/sysinit.c 

OBJS += \
./Code/src/libPWM.o \
./Code/src/libUART.o \
./Code/src/main.o \
./Code/src/sysinit.o 

C_DEPS += \
./Code/src/libPWM.d \
./Code/src/libUART.d \
./Code/src/main.d \
./Code/src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
Code/src/libPWM.o: ../Code/src/libPWM.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F302R8Tx -DSTM32F3 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/testProj8/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/testProj8/Code/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Code/src/libPWM.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Code/src/libUART.o: ../Code/src/libUART.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F302R8Tx -DSTM32F3 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/testProj8/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/testProj8/Code/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Code/src/libUART.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Code/src/main.o: ../Code/src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F302R8Tx -DSTM32F3 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/testProj8/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/testProj8/Code/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Code/src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Code/src/sysinit.o: ../Code/src/sysinit.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F302R8Tx -DSTM32F3 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/testProj8/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/testProj8/Code/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Code/src/sysinit.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

