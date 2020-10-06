#include "view.h"

#include "imodel.h"
#include "telegrambot.h"
#include "telegramobjects.h"

View::View(Model &model, TelegramBot &bot)
    : _model(model),
      _telegramBot(bot),
      _temperatureButton( _keyboard.createButton(&View::tempOrHumidPressed, this) ),
      _humidityButton( _keyboard.createButton(&View::tempOrHumidPressed, this) )
{
    _model.setView(this);
    _telegramBot.subscribeOnReply(this);
}

void View::update()
{
    _telegramBot.update();

    if ( !_needUpdate ) return;

    auto state = _model.currentState();

    TelegramMessage textMessage(state.message);

    _temperatureButton->updateText( String("   Temperature:       %.1f   ", state.temperature) );
    _humidityButton->updateText(    String("   Humidity:             %.1f   ", state.humidity) );

    TelegramComplexMessage message( textMessage, _keyboard );
    _telegramBot.updateMessage(message);

    _needUpdate = false;
}

long View::acceptReply(const String &reply)
{
    long lastUpdateId = 0;
    auto nextReply = reply;
    while (true)
    {
        nextReply = nextReply.removeBeginTo("\"update_id\":", 0l);
        auto update_id = nextReply.toLong();

        if ( update_id == 0 )
            return lastUpdateId;

        _keyboard.checkReply(nextReply);

         auto callbackQueryId = nextReply.findNum("callback_query\":{\"id\":\"");
         if ( callbackQueryId.length() > 0 ) _telegramBot.answerCallbackQuery(callbackQueryId);
         lastUpdateId = update_id;
    }
}

void View::modelUpdated()
{
    _needUpdate = true;
}


//------------- CONTROLLER --------------//
Model *View::model(TelegramController *instance)
{
    return &(static_cast<View *>(instance)->_model);
}

void View::tempOrHumidPressed(TelegramController *instance)
{
    model(instance)->tempOrHumidPressed();
}


