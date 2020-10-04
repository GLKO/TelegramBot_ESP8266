#include "telegrambot.h"

#include "config.h"
#include "telegramobjects.h"
#include "internet.h"

TelegramBot::TelegramBot(Internet &internet)
    : _internet(internet),
      _token(token)
{}

void TelegramBot::update()
{
    String method = "/getUpdates";
    _internet.get(_botApiUrl + _token + method);

    const auto reply = _internet.reply();


    //auto data = reply.value("data");
    //run callback function depends on callback_data
}

void TelegramBot::updateMessage(TelegramObject &object)
{
    const String method = "/editMessageText?";
    _internet.post(_botApiUrl + _token + method + "message_id=57&" + object.json());
}

void TelegramBot::sendMesage(TelegramObject &object)
{
    const String method = "/sendMessage?";
    _internet.post(_botApiUrl + _token + method + object.json());
}
