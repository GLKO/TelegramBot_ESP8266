#include "telegrambot.h"


TelegramBot::TelegramBot(Internet * const internet, String token)
    : _token(token),
      _internet(internet)
{}

void TelegramBot::update()
{
    auto reply = _internet->reply();

    String method = "/getUpdates";

    TelegramTextMessage message("420638906", "It's working!");
    send(message);
}

void TelegramBot::send(TelegramObject &object)
{
    String method = "/sendMessage?";
    _internet->post(_botApiUrl+_token+method + object.json());
}
