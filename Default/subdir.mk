################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../About.cpp \
../MainWindow.cpp \
../Settings.cpp \
../editProperties.cpp \
../groupProperties.cpp \
../groups.cpp \
../main.cpp \
../models.cpp \
../myLibb.cpp \
../userproperties.cpp \
../users.cpp 

O_SRCS += \
../About.o \
../MainWindow.o \
../editProperties.o \
../groupProperties.o \
../groups.o \
../main.o 

OBJS += \
./About.o \
./MainWindow.o \
./Settings.o \
./editProperties.o \
./groupProperties.o \
./groups.o \
./main.o \
./models.o \
./myLibb.o \
./userproperties.o \
./users.o 

CPP_DEPS += \
./About.d \
./MainWindow.d \
./Settings.d \
./editProperties.d \
./groupProperties.d \
./groups.d \
./main.d \
./models.d \
./myLibb.d \
./userproperties.d \
./users.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DQT_CC_GNU=1 -DQT_CORE_LIB=1 -DQT_GUI_LIB=1 -DQT_SHARED=1 -DQT_TESTLIB_LIB=1 -DQT_NO_DEBUG=1 -DQT_WEBKIT=1 -I/usr/include/qt4 -I/usr/include/qt4/Qt -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -O2 -g -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


