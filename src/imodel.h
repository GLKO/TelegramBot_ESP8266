#ifndef MODEL_H
#define MODEL_H

#include "mystring.h"

struct State
{
    String message = "blet";
    double temperature = 101;
    double humidity = 101;
};

class IView;
typedef  void (IView::*UpdateCallback)();

class Model
{
public:
    virtual State currentState() = 0;
    void connectUpdate(UpdateCallback update)
    {
        _updated = update;
    }

    ~Model() {}

private:
    UpdateCallback _updated = nullptr;
};

#endif // MODEL_H
