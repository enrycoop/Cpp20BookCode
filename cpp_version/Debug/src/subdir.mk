################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/cpp_version.cpp 

CPP_DEPS += \
./src/cpp_version.d 

OBJS += \
./src/cpp_version.o 


# Each subdirectory must supply rules for building sources it contributes
src/cpp_version.o: ../src/cpp_version.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -pedantic -std=gnu++20 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/cpp_version.d ./src/cpp_version.o

.PHONY: clean-src

