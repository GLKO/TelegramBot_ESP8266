#include "mainlogic.h"

#include "isensor.h"


MainLogic::MainLogic(Sensor &temperatureSensor, Sensor &humiditySensor)
    : _temperatureSensor(temperatureSensor),
      _humiditySensor(humiditySensor),
      _updateTimer(600000)
{
    _updateTimer.start();
}

void MainLogic::loop()
{
   if ( _updateTimer.timeout() ) _view->modelUpdated();

//    if (smthg bad)
//        _view ->alarm("!ALARM!");
}

State MainLogic::currentState()
{
    _updateTimer.start();

    State result;
    result.temperature = _temperatureSensor.value();
    result.humidity = _humiditySensor.value();
    return result;
}

void MainLogic::tempOrHumidPressed()
{
    _view->modelUpdated();
}
