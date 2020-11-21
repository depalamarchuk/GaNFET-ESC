################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SW_Fucntions/src/conversions.c 

OBJS += \
./SW_Fucntions/src/conversions.o 

C_DEPS += \
./SW_Fucntions/src/conversions.d 


# Each subdirectory must supply rules for building sources it contributes
SW_Fucntions/src/conversions.o: ../SW_Fucntions/src/conversions.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Analog/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/FreeRTOS_Source/include" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/SW_Fucntions/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"SW_Fucntions/src/conversions.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

