#ifndef MAINLOGIC_H
#define MAINLOGIC_H

#include "imodel.h"

class Sensor;

class MainLogic : public Model
{
public:
    MainLogic(Sensor &temperatureSensor,Sensor &humiditySensor);

    void update();
    State currentState() override;

    void tempOrHumidPressed() override;

private:
    Sensor &_temperatureSensor;
    Sensor &_humiditySensor;
};

#endif // MAINLOGIC_H
