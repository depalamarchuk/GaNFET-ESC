################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/src/system_stm32g4xx.c 

OBJS += \
./CMSIS/src/system_stm32g4xx.o 

C_DEPS += \
./CMSIS/src/system_stm32g4xx.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/src/%.o: ../CMSIS/src/%.c CMSIS/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/SW_Fucntions/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/FreeRTOS_Source/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

