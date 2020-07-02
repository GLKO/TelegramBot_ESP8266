#include "arduinoonpc.h"
#include "config.h"
#include "internet.h"
#include "telegrambot.h"
#include "mainlogic.h"


int main()
{
#ifdef PC
    InternetPc internet;
#else
    InternetWifiArduino inretnet(ssid, password);
#endif

    internet.connect();

    TelegramBot bot(&internet, token);

    MainLogic logic;
    
    while (true)
    {
        //check sensors
        bot.update();
        logic.update(); //post results to bot

        delay(3000);
    }
}
