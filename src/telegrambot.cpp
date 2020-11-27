#include "telegrambot.h"

#include "config.h"
#include "telegramobjects.h"
#include "internet.h"

TelegramBot::TelegramBot(Internet &internet)
    : _internet(internet),
      _token(token)
{}

void TelegramBot::subscribeOnReply(TelegramController *controller)
{ _controller = controller; }

void TelegramBot::loop()
{
    _internet.loop();

    if ( importantRequestInProgress() ) return;
    else if ( importantRequestDone() ) _importantRequest = false;
    else if ( updateReceived() )
    {
        const auto reply = _internet.reply();
        _lastUpdateId = _controller->acceptReply(reply);
    }

    if ( _importantRequestsQueue.size() > 0 ) sendImportantRequest();
    else if ( _internet.replyReady() ) sendUpdatesRequest();
}

void TelegramBot::updateMessage(const TelegramObject &object)
{
    const MyString method = "/editMessageText?";
    _importantRequestsQueue.push( _botApiUrl + _token + method + "message_id=57&" + object.json().toUrl() );
}

void TelegramBot::sendMesage(const TelegramObject &object)
{
    const MyString method = "/sendMessage?";
    _importantRequestsQueue.push( _botApiUrl + _token + method + object.json() );
}

void TelegramBot::answerCallbackQuery(const MyString &callbackQueryId)
{
    const MyString method = "/answerCallbackQuery?callback_query_id=";
    _importantRequestsQueue.push( _botApiUrl + _token + method + callbackQueryId );
}

bool TelegramBot::importantRequestInProgress() const
{ return _importantRequest && !_internet.replyReady(); }

bool TelegramBot::importantRequestDone() const
{ return _importantRequest && _internet.replyReady(); }

bool TelegramBot::updateReceived() const
{ return !_importantRequest && _internet.replyReady(); }

void TelegramBot::sendImportantRequest()
{
    _internet.get( _importantRequestsQueue.front() );
    _importantRequestsQueue.pop();
    _importantRequest = true;
}

void TelegramBot::sendUpdatesRequest()
{
    MyString method = "/getUpdates?timeout=500&offset=" + MyString(_lastUpdateId+1); //allowed_updates=[\"callback_query\"]&
    _internet.get(_botApiUrl + _token + method);
}
