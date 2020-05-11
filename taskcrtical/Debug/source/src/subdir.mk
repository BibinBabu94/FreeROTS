################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/src/cr_startup_lpc175x_6x.c \
../source/src/proj1.c \
../source/src/sysinit.c 

OBJS += \
./source/src/cr_startup_lpc175x_6x.o \
./source/src/proj1.o \
./source/src/sysinit.o 

C_DEPS += \
./source/src/cr_startup_lpc175x_6x.d \
./source/src/proj1.d \
./source/src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
source/src/%.o: ../source/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M3 -I"/home/bibin/Documents/MCUXpresso_10.3.1_2233/workspace/lpc_chip_175x_6x/inc" -I"/home/bibin/Documents/MCUXpresso_10.3.1_2233/workspace/lpc_board_nxp_lpcxpresso_1769/inc" -I"/home/bibin/Documents/MCUXpresso_10.3.1_2233/workspace/myproj_1/freertos/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


