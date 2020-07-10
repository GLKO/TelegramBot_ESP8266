#include "telegramobjects.h"


TelegramTextMessage::TelegramTextMessage(String chat_id, String text)
    : _chat_id(chat_id),
      _text(text)
{}

String TelegramTextMessage::json() const
{
    return "chat_id=" + _chat_id + "&text=" + _text;
}
