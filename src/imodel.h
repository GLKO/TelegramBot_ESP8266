#ifndef MODEL_H
#define MODEL_H

#include "mystring.h"
#include "iview.h"

struct State
{
    String message = "blet";
    double temperature = 101;
    double humidity = 101;
};


class Model
{
public:
    virtual State currentState() = 0;
    ~Model() {}

    void setView(IView *view)
    {
        _view = view;
    }

protected:
    IView *_view = nullptr;

};

#endif // MODEL_H
