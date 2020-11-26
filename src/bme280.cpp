#include "bme280.h"

#ifndef PC
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;
const uint8_t powerPin = 2;

BME280Temperature::BME280Temperature(uint8_t address)
{
    pinMode(powerPin, OUTPUT);
    bme.begin(address);
}

double BME280Temperature::value()
{
    digitalWrite(powerPin, HIGH);
    delay(1);
    bme.init();

    double value = bme.readTemperature();

    digitalWrite(powerPin, LOW);
    return value;
}


BME280Humidity::BME280Humidity(uint8_t address)
{
    pinMode(powerPin, OUTPUT);
    bme.begin(address);
}

double BME280Humidity::value()
{
    digitalWrite(powerPin, HIGH);
    delay(1);
    bme.init();

    double value = bme.readHumidity();

    digitalWrite(powerPin, LOW);
    return value;
}

#else
#include <random>
#include <time.h>

double randomDouble()
{
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    srand(now.tv_nsec);
    return (std::rand() % 1000) / 10.;
}


#define UNUSED(x) (void)x;

BME280Temperature::BME280Temperature(uint8_t address) {UNUSED(address)}

double BME280Temperature::value()
{
    return randomDouble();
}

BME280Humidity::BME280Humidity(uint8_t address) {UNUSED(address)}

double BME280Humidity::value()
{
    return randomDouble();
}

#endif
