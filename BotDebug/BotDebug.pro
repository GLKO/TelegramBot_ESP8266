QT -= gui
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle
#CONFIG += openssl

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += PC

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    ../src/arduinoonpc.h \
    ../src/bme280.h \
    ../src/config.h \
    ../src/device.h \
    ../src/internet.h \
    ../src/isensor.h \
    ../src/mainlogic.h \
    ../src/mystring.h \
    ../src/telegrambot.h \
    ../src/telegramobjects.h

SOURCES += \
        ../src/bme280.cpp \
        ../src/internet.cpp \
        ../src/main.cpp \
        ../src/mainlogic.cpp \
        ../src/mystring.cpp \
        ../src/telegrambot.cpp \
        ../src/telegramobjects.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


