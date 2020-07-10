#ifndef TELEGRAMBOT_H
#define TELEGRAMBOT_H

#include "arduinoonpc.h"
#include "internet.h"

#include "telegramobjects.h"


class TelegramBot
{
public:
    TelegramBot(Internet *const internet, String token);

    void update();
    void send(TelegramObject &object);

private:
    const String _botApiUrl = "https://api.telegram.org/bot";
    const String _token;
    Internet *const _internet = nullptr;
};


#endif // TELEGRAMBOT_H
