#ifndef TELEGRAMOBJECTS_H
#define TELEGRAMOBJECTS_H

#include "mystring.h"

class TelegramObject
{
public:
    virtual String json() const = 0;
};


class TelegramMessage : public TelegramObject
{
public:
    TelegramMessage(String text); //CRUTCH
    TelegramMessage(String text, String chatId);
    String json() const override;

private:
    const String _text;
    const String _chat_id = "420638906"; //CRUTCH
};

class TelegramComplexMessage : public TelegramObject
{
public:
    TelegramComplexMessage(const TelegramMessage &textMessage, const TelegramObject &optionalParameter);
    String json() const override;

private:
    const TelegramMessage &_textMessage;
    const TelegramObject &_optionalParameter;
};



class TelegramInlineButton : public TelegramObject
{
public:
    TelegramInlineButton(String text, String callbackData);
    String json() const override;

private:
    const String _text;
    const String _callbackData;
};

//template used instead dynamic array
template<int size>
class TelegramInlineKeyboard : public TelegramObject
{
public:
    TelegramInlineKeyboard() {}
    void addButton(TelegramInlineButton *button)
    {
        for (int i = 0; i < size; ++i)
        {
            if ( _buttons[i] != nullptr ) continue;

            _buttons[i] = button;
            break;
        }
    }

    String json() const override
    {
        String result = "reply_markup={\"inline_keyboard\":[";

        for (int i = 0; i < size; ++i)
        {
            result = result + "[" + _buttons[i]->json() + "]";

            if ( i != size-1 )
            {
                result = result + ",";
            }
        }
        result = result + "]}";
        return result;
    }

private:
    TelegramInlineButton *_buttons[size] = {nullptr};
};



class TelegramReplyButton : public TelegramObject
{
public:
    TelegramReplyButton(String text);
    String json() const override;

private:
    const String _text;
};

//template used instead dynamic array
template<int size>
class TelegramReplyKeyboard : public TelegramObject
{
public:
    TelegramReplyKeyboard() {}
    void addButton(TelegramReplyButton *button)
    {
        for (int i = 0; i < size; ++i)
        {
            if ( _buttons[i] != nullptr ) continue;

            _buttons[i] = button;
            break;
        }
    }

    String json() const override
    {
        String result = "reply_markup={\"keyboard\":[";

        for (int i = 0; i < size; ++i)
        {
            result = result + "[" + _buttons[i]->json() + "]";

            if ( i != size-1 )
            {
                result = result + ",";
            }
        }
        result = result + "]}";
        return result;
    }

private:
    TelegramReplyButton *_buttons[size] = {nullptr};
};

#endif // TELEGRAMOBJECTS_H
