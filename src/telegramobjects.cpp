#include "telegramobjects.h"


TelegramMessage::TelegramMessage(String text)
    : _text(text)
{}

TelegramMessage::TelegramMessage(String text, String chatId)
    : _text(text),
      _chat_id(chatId)
{}

String TelegramMessage::json() const
{
    return "chat_id=" + _chat_id + "&text=" + _text;
}


TelegramComplexMessage::TelegramComplexMessage(const TelegramMessage &textMessage, const TelegramObject &optionalParameter)
    : _textMessage(textMessage),
      _optionalParameter(optionalParameter)
{}

String TelegramComplexMessage::json() const
{
    return _textMessage.json() + "&" + _optionalParameter.json();
}



TelegramInlineButton::TelegramInlineButton(TelegramCallback callback, TelegramController *controller, String callbackData)
    : _callBack(callback),
      _controller(controller),
      _callbackData(callbackData)
{}

void TelegramInlineButton::updateText(String text)
{
    _text = text;
}

void TelegramInlineButton::doCallback() const
{
    _callBack(_controller);
}

String TelegramInlineButton::json() const
{
    return "{\"text\":\"" + _text + "\",\"callback_data\":" + _callbackData + "}";
}




TelegramReplyButton::TelegramReplyButton(String text)
    : _text(text)
{}

String TelegramReplyButton::json() const
{
    return "{\"text\":\"" + _text + "\",\"request_poll\":{\"type\":\"regular\"}}"; //fix optional data
}
