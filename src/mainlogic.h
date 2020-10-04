#ifndef MAINLOGIC_H
#define MAINLOGIC_H

class TelegramBot;
class Sensor;

class MainLogic
{
public:
    MainLogic(TelegramBot &telegramBot, Sensor &temperatureSensor,Sensor &humiditySensor);

    void update();

private:
    TelegramBot &_telegramBot;
    Sensor &_temperatureSensor;
    Sensor &_humiditySensor;
};

#endif // MAINLOGIC_H
