#ifndef IVIEW_H
#define IVIEW_H

class IView
{
public:
    ~IView();
private:
    virtual void modelUpdated() = 0;
};

#endif // IVIEW_H
