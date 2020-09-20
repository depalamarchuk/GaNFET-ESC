################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/src/system_stm32g4xx.c 

OBJS += \
./CMSIS/src/system_stm32g4xx.o 

C_DEPS += \
./CMSIS/src/system_stm32g4xx.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/src/system_stm32g4xx.o: ../CMSIS/src/system_stm32g4xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/ESC_code/ESC_firmware/CMSIS" -I"C:/Users/Admin/Desktop/ESC_code/ESC_firmware/CMSIS/inc" -I"C:/Users/Admin/Desktop/ESC_code/ESC_firmware" -I"C:/Users/Admin/Desktop/ESC_code/ESC_firmware/LED/inc" -I"C:/Users/Admin/Desktop/ESC_code/ESC_firmware/LED" -I"C:/Users/Admin/Desktop/ESC_code/ESC_firmware/UART" -I"C:/Users/Admin/Desktop/ESC_code/ESC_firmware/UART/inc" -I"C:/Users/Admin/Desktop/ESC_code/ESC_firmware/Main" -I"C:/Users/Admin/Desktop/ESC_code/ESC_firmware/Main/inc" -I"C:/Users/Admin/Desktop/ESC_code/ESC_firmware/Main/Startup" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/src/system_stm32g4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

