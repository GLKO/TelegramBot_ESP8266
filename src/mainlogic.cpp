#include "mainlogic.h"

#include "isensor.h"
#include <Arduino.h>


MainLogic::MainLogic(Sensor &temperatureSensor, Sensor &humiditySensor)
    : _temperatureSensor(temperatureSensor),
      _humiditySensor(humiditySensor)
{}

void MainLogic::update()
{
    static unsigned long lastTime;
    auto currentTime = millis();

   if (currentTime - lastTime > 600000ul) 
   {
       _view->modelUpdated();
       lastTime = currentTime;
    }

//    if (smthg bad)
//        _view ->alarm("!ALARM!");
}

State MainLogic::currentState()
{
    State result;
    result.message = "=)";
    result.temperature = _temperatureSensor.value();
    result.humidity = _humiditySensor.value();
    return result;
}

void MainLogic::tempOrHumidPressed()
{
    _view->modelUpdated();
}
