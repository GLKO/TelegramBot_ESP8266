#ifndef IVIEW_H
#define IVIEW_H

#include "mystring.h"

class IView
{
public:
    virtual void modelUpdated() = 0;
    virtual void alarm(String message) {}

    ~IView() {}
};

#endif // IVIEW_H
