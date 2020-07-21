######################################################################
# Automatically generated by qmake (3.1) Tue Jul 21 12:44:28 2020
######################################################################

TEMPLATE = app
TARGET = UserManager
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += About.h \
           Blowfish.h \
           editProperties.h \
           groupProperties.h \
           groups.h \
           HashEncode.h \
           HashingAlgorithm.h \
           HashingFactory.h \
           IHashing.h \
           InputDialogValidator.h \
           MainWindow.h \
           Md5.h \
           models.h \
           myLibb.h \
           pathfile.h \
           Settings.h \
           sha256.h \
           sha512.h \
           spc.h \
           userproperties.h \
           users.h
FORMS += ui/About.ui \
         ui/EditProperties.ui \
         ui/GroupProperties.ui \
         ui/HashingAlgorithm.ui \
         ui/mainwindow.ui \
         ui/Settings.ui \
         ui/UserProperties.ui
SOURCES += About.cpp \
           Blowfish.cpp \
           editProperties.cpp \
           groupProperties.cpp \
           groups.cpp \
           HashEncode.cpp \
           HashingAlgorithm.cpp \
           HashingFactory.cpp \
           InputDialogValidator.cpp \
           main.cpp \
           MainWindow.cpp \
           Md5.cpp \
           models.cpp \
           myLibb.cpp \
           Settings.cpp \
           sha256.cpp \
           sha512.cpp \
           spc.cpp \
           userproperties.cpp \
           users.cpp
RESOURCES += resources/images.qrc
TRANSLATIONS += language/el.ts
QMAKE_CXXFLAGS += -std=c++11 -O2 -fstack-protector-all -Wformat -Werror=format-security
QMAKE_CPPFLAGS += -Wdate-time -D_FORTIFY_SOURCE=2
QMAKE_CFLAGS += -O2 -fstack-protector-all -Wformat -Werror=format-security
LDFLAGS += -Wl,-z,relro
CONFIG += qt debug
QMAKE_LIBS += -lcrypt
QT += widgets
# installation
installfiles.files += usermanager
installfiles.path += /usr/bin/
INSTALLS += installfiles
