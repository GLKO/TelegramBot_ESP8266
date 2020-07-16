#include "mainlogic.h"

#include "telegramobjects.h"
#include "sensor.h"

MainLogic::MainLogic(TelegramBot *bot, Sensor *temperatureSensor,Sensor *humiditySensor)
    : _telegramBot(bot),
      _temperatureSensor(temperatureSensor),
      _humiditySensor(humiditySensor)
{}

void MainLogic::update()
{
    auto temperature = _temperatureSensor->value();
    auto humidity = _humiditySensor->value();

//    TelegramTextMessage message;
}
