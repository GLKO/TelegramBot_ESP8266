#include "mainlogic.h"

#include "isensor.h"


MainLogic::MainLogic(Sensor &temperatureSensor, Sensor &humiditySensor)
    : _temperatureSensor(temperatureSensor),
      _humiditySensor(humiditySensor)
{}

void MainLogic::update()
{
//    if (timeout(600sec)
//    _view->modelUpdated();

//    if (smthg bad)
//        _view ->alarm("!ALARM!");
}

State MainLogic::currentState()
{
    State result;
    result.message = "Last update: ??.??.?? ??:??";
    result.temperature = _temperatureSensor.value();
    result.humidity = _humiditySensor.value();
    return result;
}

void MainLogic::tempOrHumidPressed()
{
    _view->modelUpdated();
}
