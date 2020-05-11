################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include source/src/subdir.mk
-include freertos/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: myproj_1.axf

# Tool invocations
myproj_1.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/bibin/Documents/MCUXpresso_10.3.1_2233/workspace/lpc_chip_175x_6x/Debug" -L"/home/bibin/Documents/MCUXpresso_10.3.1_2233/workspace/lpc_board_nxp_lpcxpresso_1769/Debug" -Xlinker -Map="myproj_1.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "freertos_blinky_Debug.ld" -o "myproj_1.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) myproj_1.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "myproj_1.axf"; # arm-none-eabi-objcopy -v -O binary "myproj_1.axf" "myproj_1.bin" ; # checksum -p LPC1769 -d "myproj_1.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
