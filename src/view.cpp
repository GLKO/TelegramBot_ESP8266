#include "view.h"

#include "imodel.h"


View::View(Model * const model)
    : _model(model)
{
    _model->connectUpdate(&View::modelUpdated);
}

void View::modelUpdated()
{

}


