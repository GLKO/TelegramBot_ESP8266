#ifndef VIEW_H
#define VIEW_H

#include "iview.h"

class Model;


class View : public IView
{
public:
    View(Model *const model);

private:
    Model *const _model;

    void modelUpdated() override;
};


#endif // VIEW_H
