#include "internet.h"

#ifdef PC


#else
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#endif


InternetPc::InternetPc()
{

}

void InternetPc::connect() const
{

}

void InternetPc::post(String url) const
{

}

String InternetPc::get(String url) const
{
    return String();
}


// ----------- ARDUINO --------------- //

InternetWifiArduino::InternetWifiArduino(String wifiName, String password)
{

}

void InternetWifiArduino::connect() const
{
    //    WiFi.begin(ssid, password);

    //    while ( WiFi.status() != WL_CONNECTED )
    //        delay(1000);
}

void InternetWifiArduino::post(String url) const
{

}

String InternetWifiArduino::get(String url) const
{
    return String();
}
