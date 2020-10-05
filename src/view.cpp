#include "view.h"

#include "imodel.h"
#include "telegrambot.h"
#include "telegramobjects.h"

View::View(Model &model, TelegramBot &bot)
    : _model(model),
      _telegramBot(bot)
{
    _model.connectUpdate(&IView::modelUpdated);
}


void View::modelUpdated()
{
    _telegramBot.update();

    auto state = _model.currentState();

    TelegramMessage textMessage(state.message);

    TelegramInlineButton temperatureButton("   Temperature:    nice!   ", "1");
    TelegramInlineButton humidityButton   ("   Humidity:          OK   ", "2");

    constexpr int buttonsCount = 2;
    TelegramInlineKeyboard<buttonsCount> keyboard;
    keyboard.addButton( &temperatureButton );
    keyboard.addButton( &humidityButton );

    TelegramComplexMessage message( textMessage, keyboard );
    _telegramBot.updateMessage(message);
}


