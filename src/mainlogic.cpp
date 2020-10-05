#include "mainlogic.h"

#include "telegramobjects.h"
#include "isensor.h"
#include "telegrambot.h"

#include <iostream>

MainLogic::MainLogic(TelegramBot &telegramBot, Sensor &temperatureSensor, Sensor &humiditySensor)
    : _telegramBot(telegramBot),
      _temperatureSensor(temperatureSensor),
      _humiditySensor(humiditySensor)
{}

void MainLogic::update()
{
    _telegramBot.update();

    auto temperature = _temperatureSensor.value();
    auto humidity = _humiditySensor.value();

    TelegramMessage textMessage("Hi");

    TelegramInlineButton temperatureButton("   Temperature:    nice!   ", "1");
    TelegramInlineButton humidityButton   ("   Humidity:          OK   ","2");

    TelegramInlineKeyboard<2> keyboard;
    keyboard.addButton( &temperatureButton );
    keyboard.addButton( &humidityButton );

    TelegramComplexMessage message( textMessage, keyboard );
    _telegramBot.updateMessage(message);
}
