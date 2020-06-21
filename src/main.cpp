#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>



void setup() {
    #include "wifiAuthentication.h"
    WiFi.begin(ssid, password);

    while ( WiFi.status() != WL_CONNECTED )
        delay(1000);
}

void loop() {

    

    //check sensors

    //post results to bot

    delay(100);
}