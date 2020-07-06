#ifndef ARDUINOONPC_H
#define ARDUINOONPC_H
#ifdef PC

#include <QString>
typedef QString String;

#include <chrono>
#include <thread>
inline void delay(int msec) {
    std::this_thread::sleep_for(std::chrono::milliseconds(msec));
}

#include <QCoreApplication>

#else
#include <Arduino.h>
#endif
#endif // ARDUINOONPC_H
