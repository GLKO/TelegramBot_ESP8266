#include "arduinoonpc.h"
#include "config.h"
#include "internet.h"
#include "telegrambot.h"
#include "bme280.h"
#include "mainlogic.h"


int main()
{
#ifdef PC
    char *argv[1];
    int argc = 0;
    QCoreApplication a(argc, argv);
    InternetPc internet;
#else
    InternetWifiArduino inretnet(ssid, password);
#endif

    internet.connect();

    TelegramBot bot(&internet, token);
    BME280Temperature temperatureSensor;
    BME280Humidity humiditySensor;

    MainLogic logic(&bot, &temperatureSensor, &humiditySensor);
    
    while (true)
    {
        internet.update();
        bot.update();
        logic.update(); //post results to bot

        delay(10000);
    }
}
