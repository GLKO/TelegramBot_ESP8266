#ifndef TELEGRAMBOT_H
#define TELEGRAMBOT_H

#include "mystring.h"

class TelegramController;
class TelegramObject;
class Internet;

class TelegramBot
{
public:
    TelegramBot(Internet &internet);
    void subscribeOnReply(TelegramController *controller);

    void update();

    void sendMesage(const TelegramObject &object);
    void updateMessage(const TelegramObject &object);
    void answerCallbackQuery(const String &callbackQueryId);

private:
    Internet &_internet;
    const String _botApiUrl = "https://api.telegram.org/bot";
    const String _token;

    TelegramController *_controller = nullptr;

    long _lastUpdateId = 0;
};


#endif // TELEGRAMBOT_H
