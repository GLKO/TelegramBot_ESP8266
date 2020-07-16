#ifndef MAINLOGIC_H
#define MAINLOGIC_H

class TelegramBot;
class Sensor;

class MainLogic
{
public:
    MainLogic(TelegramBot *bot, Sensor *temperatureSensor,Sensor *humiditySensor);

    void update();

private:
    TelegramBot *const _telegramBot = nullptr;
    Sensor *const _temperatureSensor = nullptr;
    Sensor *const _humiditySensor = nullptr;
};

#endif // MAINLOGIC_H
