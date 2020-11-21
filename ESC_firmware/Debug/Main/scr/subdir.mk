################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Main/scr/main.c \
../Main/scr/syscalls.c \
../Main/scr/sysinit.c \
../Main/scr/sysmem.c 

OBJS += \
./Main/scr/main.o \
./Main/scr/syscalls.o \
./Main/scr/sysinit.o \
./Main/scr/sysmem.o 

C_DEPS += \
./Main/scr/main.d \
./Main/scr/syscalls.d \
./Main/scr/sysinit.d \
./Main/scr/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Main/scr/main.o: ../Main/scr/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Analog/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/FreeRTOS_Source/include" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/SW_Fucntions/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Main/scr/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Main/scr/syscalls.o: ../Main/scr/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Analog/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/FreeRTOS_Source/include" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/SW_Fucntions/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Main/scr/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Main/scr/sysinit.o: ../Main/scr/sysinit.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Analog/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/FreeRTOS_Source/include" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/SW_Fucntions/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Main/scr/sysinit.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Main/scr/sysmem.o: ../Main/scr/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Analog/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/FreeRTOS_Source/include" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/SW_Fucntions/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Main/scr/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

