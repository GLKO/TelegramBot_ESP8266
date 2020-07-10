#ifndef TELEGRAMOBJECTS_H
#define TELEGRAMOBJECTS_H

#include "arduinoonpc.h"

class TelegramObject
{
public:
    virtual String json() const = 0;
};


class TelegramTextMessage : public TelegramObject
{
public:
    TelegramTextMessage(String chat_id, String text);
    String json() const override;

private:
    const String _chat_id;
    const String _text;
};


class TelegramInlineKeyboard : public TelegramObject
{
public:
    TelegramInlineKeyboard();
    String json() const override;

private:

};


class TelegramInlineKeyboardMessage : public TelegramObject
{
public:
    TelegramInlineKeyboardMessage(const TelegramTextMessage &textMessage, String reply_markup);
    String json() const override;

private:
    const TelegramTextMessage _textMessage;
    const TelegramInlineKeyboard _inlineKeyboard;
};


#endif // TELEGRAMOBJECTS_H
