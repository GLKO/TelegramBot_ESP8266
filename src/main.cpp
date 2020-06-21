#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>



void setup() {
    #include "wifiAuthentication.h"
    WiFi.begin(ssid, password);
}

void loop() {

}