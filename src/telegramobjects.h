#ifndef TELEGRAMOBJECTS_H
#define TELEGRAMOBJECTS_H

#include "mystring.h"

typedef long LastUpdateId;

class TelegramController
{
public:
    virtual LastUpdateId acceptReply(const MyString &reply) = 0;
//    {
//        long lastUpdateId = 0;
//        return lastUpdateId;
//    }
    virtual ~TelegramController() {}
};

typedef void(*TelegramCallback)(TelegramController *instance);



class TelegramObject
{
public:
    virtual MyString json() const = 0;
};


class TelegramMessage : public TelegramObject
{
public:
    TelegramMessage(MyString text); //CRUTCH
    TelegramMessage(MyString text, MyString chatId);
    MyString json() const override;

private:
    const MyString _text;
    const MyString _chat_id = "420638906"; //CRUTCH
};



class TelegramComplexMessage : public TelegramObject
{
public:
    TelegramComplexMessage(const TelegramMessage &textMessage, const TelegramObject &optionalParameter);
    MyString json() const override;

private:
    const TelegramMessage &_textMessage;
    const TelegramObject &_optionalParameter;
};



class TelegramInlineButton : public TelegramObject
{
public:
    TelegramInlineButton(TelegramCallback callback, TelegramController *controller, MyString callbackData);

    void updateText(MyString text);
    void doCallback() const;
    MyString json() const override;

private:
    MyString _text;
    TelegramCallback const _callBack;
    TelegramController *const _controller;
    const MyString _callbackData;
};



//template used instead dynamic array
template<int size>
class TelegramInlineKeyboard : public TelegramObject
{
public:
    TelegramInlineKeyboard() {}
    TelegramInlineButton *createButton(TelegramCallback callback, TelegramController *controller)
    {
        for (long i = 0; i < size; ++i)
        {
            if ( _buttons[i] != nullptr ) continue;

            _buttons[i] = new TelegramInlineButton(callback, controller, MyString(i));
            return _buttons[i];
        }
    }

    MyString json() const override
    {
        MyString result = "reply_markup={\"inline_keyboard\":[";

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

    void checkReply(const MyString &reply)
    {
        int callBackData = reply.removeBeginTo("\"data\":\"", -1l).toLong();
        if ( callBackData < 0 || callBackData > size - 1 ) return;
        _buttons[callBackData]->doCallback();
    }

    ~TelegramInlineKeyboard()
    {
        for (auto &button : _buttons)
        {
            if ( button != nullptr ) delete button;
        }
    }

private:
    TelegramInlineButton *_buttons[size] = {nullptr};
};



class TelegramReplyButton : public TelegramObject
{
public:
    TelegramReplyButton(MyString text);
    MyString json() const override;

private:
    const MyString _text;
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

    MyString json() const override
    {
        MyString result = "reply_markup={\"keyboard\":[";

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
