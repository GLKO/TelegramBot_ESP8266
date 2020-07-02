#ifndef TELEGRAMBOT_H
#define TELEGRAMBOT_H

#include "arduinoonpc.h"
#include "internet.h"

class TelegramBot
{
public:
    TelegramBot(Internet *const internet, String token);

    void update() const;

    const String _botApiUrl = "https://api.telegram.org/bot";
    const String _token;
    const Internet * _internet = nullptr;
};

#endif // TELEGRAMBOT_H
