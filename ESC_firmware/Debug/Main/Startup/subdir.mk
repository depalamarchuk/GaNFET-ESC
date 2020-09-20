################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Main/Startup/startup_stm32g473cetx.s 

OBJS += \
./Main/Startup/startup_stm32g473cetx.o 

S_DEPS += \
./Main/Startup/startup_stm32g473cetx.d 


# Each subdirectory must supply rules for building sources it contributes
Main/Startup/startup_stm32g473cetx.o: ../Main/Startup/startup_stm32g473cetx.s
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -x assembler-with-cpp -MMD -MP -MF"Main/Startup/startup_stm32g473cetx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

