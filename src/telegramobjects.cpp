#include "telegramobjects.h"


TelegramMessage::TelegramMessage(MyString text)
    : _text(text)
{}

TelegramMessage::TelegramMessage(MyString text, MyString chatId)
    : _text(text),
      _chat_id(chatId)
{}

MyString TelegramMessage::json() const
{
    return "chat_id=" + _chat_id + "&text=" + _text;
}


TelegramComplexMessage::TelegramComplexMessage(const TelegramMessage &textMessage, const TelegramObject &optionalParameter)
    : _textMessage(textMessage),
      _optionalParameter(optionalParameter)
{}

MyString TelegramComplexMessage::json() const
{
    return _textMessage.json() + "&" + _optionalParameter.json();
}



TelegramInlineButton::TelegramInlineButton(TelegramCallback callback, TelegramController *controller, MyString callbackData)
    : _callBack(callback),
      _controller(controller),
      _callbackData(callbackData)
{}

void TelegramInlineButton::updateText(MyString text)
{
    _text = text;
}

void TelegramInlineButton::doCallback() const
{
    _callBack(_controller);
}

MyString TelegramInlineButton::json() const
{
    return "{\"text\":\"" + _text + "\",\"callback_data\":" + _callbackData + "}";
}




TelegramReplyButton::TelegramReplyButton(MyString text)
    : _text(text)
{}

MyString TelegramReplyButton::json() const
{
    return "{\"text\":\"" + _text + "\",\"request_poll\":{\"type\":\"regular\"}}"; //fix optional data
}
