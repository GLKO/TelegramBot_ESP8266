#ifndef VIEW_H
#define VIEW_H

#include "iview.h"
#include "telegramobjects.h"

class Model;
class TelegramBot;

class View : public IView, public TelegramController
{
public:
    View(Model &model, TelegramBot &bot);

    void update();
    long acceptReply(const MyString &reply) override;

private:
    Model &_model;
    TelegramBot &_telegramBot;

    TelegramInlineKeyboard<2> _keyboard;

    TelegramInlineButton *const _temperatureButton;
    TelegramInlineButton *const _humidityButton;

    bool _needUpdate = true;

    void modelUpdated() override;

    //CONTROLLER
    static Model *model(TelegramController *instance);
    static void tempOrHumidPressed(TelegramController *instance);
};


#endif // VIEW_H
