################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LED/src/LED.c 

OBJS += \
./LED/src/LED.o 

C_DEPS += \
./LED/src/LED.d 


# Each subdirectory must supply rules for building sources it contributes
LED/src/LED.o: ../LED/src/LED.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/CMSIS" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/LED/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/LED" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/UART" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/UART/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/Startup" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LED/src/LED.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

