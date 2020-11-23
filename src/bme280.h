#ifndef BME280_H
#define BME280_H

#include "isensor.h"


class BME280Temperature : public Sensor
{
public:
    BME280Temperature(uint8_t address);

    double value() override;
};



class BME280Humidity : public Sensor
{
public:
    BME280Humidity(uint8_t address);

    double value() override;
};

#endif // BME280_H
