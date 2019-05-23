################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 6
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := "$(GNU_Make_Install_DirEnv)/rm" -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Sources/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Lib/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Timer_LD.abs \

EXECUTABLES_QUOTED += \
"Timer_LD.abs" \

EXECUTABLES_OS_FORMAT += \
Timer_LD.abs \

BURNER_OUTPUT_OUTPUTS += \
Timer_LD.abs.s19 \

BURNER_OUTPUT_OUTPUTS_QUOTED += \
"Timer_LD.abs.s19" \

BURNER_OUTPUT_OUTPUTS_OS_FORMAT += \
Timer_LD.abs.s19 \


# All Target
call-burner := 0
ifneq ($(strip $(EXECUTABLES)),)
ifneq ($(strip $(BBL_SRCS_QUOTED)),)
call-burner := 1
endif
endif
ifeq ($(call-burner),1)
all: Timer_LD.abs Timer_LD.abs.s19
else
all: Timer_LD.abs
endif

# Tool invocations
Timer_LD.abs: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #7 $@'
	@echo 'Invoking: S08 Linker'
	"$(HC08ToolsEnv)/linker" -ArgFile"Timer_LD.args" -O"Timer_LD.abs"
	@echo 'Finished building target: $@'
	@echo ' '

Timer_LD.abs.s19: $(BBL_SRCS) $(EXECUTABLES)
	@echo 'Executing target #8 $@'
	@echo 'Invoking: S08 Burner'
	"$(HC08ToolsEnv)/burner" -ArgFile"Timer_LD.abs.args" -f="$<" -env"ABS_FILE=$(strip $(EXECUTABLES_OS_FORMAT))"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) "./*/*.obj" "./*/*/*.obj"  $(CPP_DEPS_QUOTED) $(CC_DEPS_QUOTED) $(CXX_DEPS_QUOTED) $(BURNER_OUTPUT_OUTPUTS_QUOTED) $(C_UPPER_DEPS_QUOTED) $(C++_DEPS_QUOTED) $(EXECUTABLES_QUOTED) "./*/*.d" "./*/*/*.d"  $(ProjDirPath)/FLASH/Timer_LD.abs
	-@echo ' '

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

