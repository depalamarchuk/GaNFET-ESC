################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripheral/src/FDCAN.c \
../Peripheral/src/LED.c \
../Peripheral/src/UART.c \
../Peripheral/src/cordic.c \
../Peripheral/src/dma.c \
../Peripheral/src/fmac.c \
../Peripheral/src/init_timers.c \
../Peripheral/src/watchdog.c 

OBJS += \
./Peripheral/src/FDCAN.o \
./Peripheral/src/LED.o \
./Peripheral/src/UART.o \
./Peripheral/src/cordic.o \
./Peripheral/src/dma.o \
./Peripheral/src/fmac.o \
./Peripheral/src/init_timers.o \
./Peripheral/src/watchdog.o 

C_DEPS += \
./Peripheral/src/FDCAN.d \
./Peripheral/src/LED.d \
./Peripheral/src/UART.d \
./Peripheral/src/cordic.d \
./Peripheral/src/dma.d \
./Peripheral/src/fmac.d \
./Peripheral/src/init_timers.d \
./Peripheral/src/watchdog.d 


# Each subdirectory must supply rules for building sources it contributes
Peripheral/src/FDCAN.o: ../Peripheral/src/FDCAN.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Analog/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/FreeRTOS_Source/include" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/SW_Fucntions/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/src/FDCAN.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Peripheral/src/LED.o: ../Peripheral/src/LED.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Analog/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/FreeRTOS_Source/include" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/SW_Fucntions/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/src/LED.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Peripheral/src/UART.o: ../Peripheral/src/UART.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Analog/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/FreeRTOS_Source/include" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/SW_Fucntions/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/src/UART.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Peripheral/src/cordic.o: ../Peripheral/src/cordic.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Analog/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/FreeRTOS_Source/include" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/SW_Fucntions/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/src/cordic.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Peripheral/src/dma.o: ../Peripheral/src/dma.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Analog/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/FreeRTOS_Source/include" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/SW_Fucntions/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/src/dma.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Peripheral/src/fmac.o: ../Peripheral/src/fmac.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Analog/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/FreeRTOS_Source/include" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/SW_Fucntions/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/src/fmac.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Peripheral/src/init_timers.o: ../Peripheral/src/init_timers.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Analog/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/FreeRTOS_Source/include" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/SW_Fucntions/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/src/init_timers.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Peripheral/src/watchdog.o: ../Peripheral/src/watchdog.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Analog/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/FreeRTOS_Source/include" -I"C:/Users/Admin/Desktop/GaNFET-ESC/ESC_firmware/SW_Fucntions/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Peripheral/src/watchdog.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

