################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
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
Main/scr/%.o: ../Main/scr/%.c Main/scr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G473CETx -DSTM32G4 -DDEBUG -c -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/CMSIS/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/Main/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/Peripheral/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/Main/Startup" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/SW_Fucntions/inc" -I"C:/Users/Admin/Desktop/GaNFET-ESC/FMAC_Demo/FreeRTOS_Source/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

