#include "bme280.h"

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
