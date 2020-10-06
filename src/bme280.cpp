#include "bme280.h"

BME280Temperature::BME280Temperature()
{}

double BME280Temperature::value()
{
    return 22.8;
}




BME280Humidity::BME280Humidity()
{}

double BME280Humidity::value()
{
    static double temper = 31.4;
    temper += 0.1;
    return temper;
}
