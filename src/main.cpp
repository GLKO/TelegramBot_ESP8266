#include "arduinoonpc.h"
#include "internet.h"
#include "telegrambot.h"
#include "bme280.h"
#include "mainlogic.h"
#include "view.h"



#ifdef PC
int main()
{
    //check without it
    char *argv[1];
    int argc = 0;
    QCoreApplication a(argc, argv);
    InternetPc internet;
#else
void loop() {}

void setup()
{
    InternetWifiArduino internet;
#endif

    BME280Temperature temperatureSensor;
    BME280Humidity humiditySensor;

    TelegramBot bot(internet);

    MainLogic logic(temperatureSensor, humiditySensor);
    View view(logic, bot);
    
    while (true)
    {
        view.update();
        logic.update();

        delay(3000);
    }
}
