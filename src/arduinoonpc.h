#ifndef ARDUINOONPC_H
#define ARDUINOONPC_H
#ifdef PC

#include <QString>
typedef QString String;

#include <QtTest/QTest>
inline void delay(int msec) {
    QTest::qWait(msec);
}

#else
#include <Arduino.h>
#endif
#endif // ARDUINOONPC_H
