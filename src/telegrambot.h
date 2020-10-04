#ifndef TELEGRAMBOT_H
#define TELEGRAMBOT_H

#include "mystring.h"

class TelegramObject;
class Internet;

class TelegramBot
{
public:
    TelegramBot(Internet &internet);

    void update();

    void sendMesage(TelegramObject &object);
    void updateMessage(TelegramObject &object);

private:
    Internet &_internet;
    const String _botApiUrl = "https://api.telegram.org/bot";
    const String _token;

};


#endif // TELEGRAMBOT_H
