#ifndef VIEW_H
#define VIEW_H

#include "iview.h"

class Model;
class TelegramBot;

class View : public IView
{
public:
    View(Model &model, TelegramBot &bot);

private:
    Model &_model;
    TelegramBot &_telegramBot;

    void modelUpdated() override;
};


#endif // VIEW_H
