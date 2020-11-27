#include "arduinoonpc.h"
#include "internet.h"
#include "telegrambot.h"
#include "bme280.h"
#include "mainlogic.h"
#include "view.h"



#ifdef PC
int main()
{
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

    const uint8_t address = 0x76;
    BME280Temperature temperatureSensor(address);
    BME280Humidity humiditySensor(address);

    internet.connect();
    
    TelegramBot bot(internet);

    MainLogic logic(temperatureSensor, humiditySensor);
    View view(logic, bot);
    
    while (true)
    {
        logic.loop();
        view.loop();
        delay(12);
    }
}

