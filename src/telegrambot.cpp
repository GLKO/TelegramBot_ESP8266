#include "telegrambot.h"

#include "config.h"
#include "telegramobjects.h"
#include "internet.h"

TelegramBot::TelegramBot(Internet &internet)
    : _internet(internet),
      _token(token)
{}

void TelegramBot::subscribeOnReply(TelegramController *controller)
{
    _controller = controller;
}

void TelegramBot::update()
{
    MyString method = "/getUpdates?timeout=1&offset=" + MyString(_lastUpdateId+1); //allowed_updates=[\"callback_query\"]&
    _internet.get(_botApiUrl + _token + method);

    const auto reply = _internet.reply();

    _lastUpdateId = _controller->acceptReply(reply);
}

void TelegramBot::updateMessage(const TelegramObject &object)
{
    const MyString method = "/editMessageText?";
    _internet.post(_botApiUrl + _token + method + "message_id=57&" + object.json());
}

void TelegramBot::sendMesage(const TelegramObject &object)
{
    const MyString method = "/sendMessage?";
    _internet.post(_botApiUrl + _token + method + object.json());
}

void TelegramBot::answerCallbackQuery(const MyString &callbackQueryId)
{
    const MyString method = "/answerCallbackQuery?callback_query_id=";
    _internet.post(_botApiUrl + _token + method + callbackQueryId);
}
