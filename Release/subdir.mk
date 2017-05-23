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
../moc_About.cpp \
../moc_MainWindow.cpp \
../moc_Settings.cpp \
../moc_editProperties.cpp \
../moc_groupProperties.cpp \
../moc_groups.cpp \
../moc_myLibb.cpp \
../moc_userproperties.cpp \
../moc_users.cpp \
../models.cpp \
../myLibb.cpp \
../qrc_images.cpp \
../userproperties.cpp \
../users.cpp 

O_SRCS += \
../About.o \
../MainWindow.o \
../Settings.o \
../editProperties.o \
../groupProperties.o \
../groups.o \
../main.o \
../moc_About.o \
../moc_MainWindow.o \
../moc_Settings.o \
../moc_editProperties.o \
../moc_groupProperties.o \
../moc_groups.o \
../moc_myLibb.o \
../moc_userproperties.o \
../moc_users.o \
../models.o \
../myLibb.o \
../qrc_images.o \
../userproperties.o \
../users.o 

OBJS += \
./About.o \
./MainWindow.o \
./Settings.o \
./editProperties.o \
./groupProperties.o \
./groups.o \
./main.o \
./moc_About.o \
./moc_MainWindow.o \
./moc_Settings.o \
./moc_editProperties.o \
./moc_groupProperties.o \
./moc_groups.o \
./moc_myLibb.o \
./moc_userproperties.o \
./moc_users.o \
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
./moc_About.d \
./moc_MainWindow.d \
./moc_Settings.d \
./moc_editProperties.d \
./moc_groupProperties.d \
./moc_groups.d \
./moc_myLibb.d \
./moc_userproperties.d \
./moc_users.d \
./models.d \
./myLibb.d \
./qrc_images.d \
./userproperties.d \
./users.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DQT_CC_GNU=1 -DQT_CORE_LIB=1 -DQT_GUI_LIB=1 -DQT_SHARED=1 -DQT_SQL_LIB=1 -DQT_TESTLIB_LIB=1 -DQT_NO_DEBUG=1 -DQT_WEBKIT=1 -I/usr/include/qt4 -I/usr/include/qt4/Qt -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -O2 -g -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


