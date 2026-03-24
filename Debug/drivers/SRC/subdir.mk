################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/SRC/stm32f401xc_gpio_driver.c \
../drivers/SRC/stm32f401xc_spi_driver.c 

OBJS += \
./drivers/SRC/stm32f401xc_gpio_driver.o \
./drivers/SRC/stm32f401xc_spi_driver.o 

C_DEPS += \
./drivers/SRC/stm32f401xc_gpio_driver.d \
./drivers/SRC/stm32f401xc_spi_driver.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/SRC/%.o drivers/SRC/%.su drivers/SRC/%.cyclo: ../drivers/SRC/%.c drivers/SRC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -I"D:/STM32_Workspace/stm32f4xx_drivers/Inc" -I"D:/STM32_Workspace/stm32f4xx_drivers/drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-drivers-2f-SRC

clean-drivers-2f-SRC:
	-$(RM) ./drivers/SRC/stm32f401xc_gpio_driver.cyclo ./drivers/SRC/stm32f401xc_gpio_driver.d ./drivers/SRC/stm32f401xc_gpio_driver.o ./drivers/SRC/stm32f401xc_gpio_driver.su ./drivers/SRC/stm32f401xc_spi_driver.cyclo ./drivers/SRC/stm32f401xc_spi_driver.d ./drivers/SRC/stm32f401xc_spi_driver.o ./drivers/SRC/stm32f401xc_spi_driver.su

.PHONY: clean-drivers-2f-SRC

