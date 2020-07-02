#include "telegrambot.h"


TelegramBot::TelegramBot(Internet * const internet, String token)
    : _token(token),
      _internet(internet)
{

}

void TelegramBot::update() const
{

}
