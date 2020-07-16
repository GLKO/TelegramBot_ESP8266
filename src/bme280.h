#ifndef BME280_H
#define BME280_H

#include "sensor.h"


class BME280Temperature : public Sensor
{
public:
    BME280Temperature();

    double value() override;
};



class BME280Humidity : public Sensor
{
public:
    BME280Humidity();

    double value() override;
};

#endif // BME280_H
