#include "arduinoonpc.h"
#include "internet.h"
#include "telegrambot.h"
#include "bme280.h"
#include "mainlogic.h"
#include "view.h"


int main()
{
#ifdef PC
    //check without it
    char *argv[1];
    int argc = 0;
    QCoreApplication a(argc, argv);
    InternetPc internet;
#else
    InternetWifiArduino internet;
#endif

    BME280Temperature temperatureSensor;
    BME280Humidity humiditySensor;

    TelegramBot bot(internet);

    MainLogic logic(bot, temperatureSensor, humiditySensor);
//    View view(&logic);
    
    while (true)
    {
        logic.update();

        delay(3000);
    }
}
