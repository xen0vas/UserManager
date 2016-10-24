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
../qrc_images.cpp \
../userproperties.cpp \
../users.cpp 

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
./qrc_images.o \
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
./qrc_images.d \
./userproperties.d \
./users.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/qt4 -I/usr/include/qt4/Qt -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


