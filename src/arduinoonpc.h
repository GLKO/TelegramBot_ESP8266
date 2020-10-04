#ifndef ARDUINOONPC_H
#define ARDUINOONPC_H

#ifdef PC
#include <chrono>
#include <thread>
#include <QCoreApplication>

inline void delay(int msec) {
    std::this_thread::sleep_for(std::chrono::milliseconds(msec));
}

#else
//#include <Arduino.h>
#endif
#endif // ARDUINOONPC_H
