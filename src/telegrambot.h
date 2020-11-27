#ifndef TELEGRAMBOT_H
#define TELEGRAMBOT_H

#include "mystring.h"
#include <queue>

class TelegramController;
class TelegramObject;
class Internet;

class TelegramBot
{
public:
    explicit TelegramBot(Internet &internet);
    void subscribeOnReply(TelegramController *controller);

    void loop();

    void sendMesage(const TelegramObject &object);
    void updateMessage(const TelegramObject &object);
    void answerCallbackQuery(const MyString &callbackQueryId);

private:
    Internet &_internet;
    const MyString _botApiUrl = "https://api.telegram.org/bot";
    const MyString _token;

    TelegramController *_controller = nullptr;

    long _lastUpdateId = 0;

    std::queue<MyString> _importantRequestsQueue;
    bool importantRequestInProgress() const;
    bool importantRequestDone() const;
    bool updateReceived() const;
    bool _importantRequest = false;

    void sendImportantRequest();
    void sendUpdatesRequest();
};


#endif // TELEGRAMBOT_H
