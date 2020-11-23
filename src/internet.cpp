#include "internet.h"

#include "config.h"

#ifdef PC
#include <QNetworkReply>
#include <QCoreApplication>

InternetPc::InternetPc()
{

}

void InternetPc::connect() const
{

}

void InternetPc::get(MyString url)
{
    auto encodedUrl = QUrl(url.c_str(), QUrl::StrictMode);
    if (!encodedUrl.isValid())
    {
        qDebug() << "Url is incorrect: \n" << encodedUrl.errorString() << "\n\n";
        _reply.clear();
        return;
    }

    auto reply = _internet.get(QNetworkRequest(encodedUrl));
    qDebug() << "Get request sent:\n" << url.c_str();

    waitReply(reply);

    QTextStream str(reply);
    _reply = str.readAll().toStdString().c_str();
    qDebug() << _reply.c_str();
}

MyString InternetPc::reply() const
{
    return _reply;
}

void InternetPc::waitReply(QNetworkReply *reply) const
{
    while ( !reply->isFinished() )
    {
        QCoreApplication::processEvents();
    }
}

#else
// ----------- ARDUINO --------------- //
#include <ESP8266HTTPClient.h>

// until 23 may 2022
const char telegramBotApiFP[] PROGMEM = "f2ad299c3448dd8df4cf5232f65733682e81c190";
// const char howsmysslFP[] PROGMEM = "E2 C7 E8 6D 53 D2 9E 9E C1 D2 06 4C C0 86 63 13 75 46 D8 95";

InternetWifiArduino::InternetWifiArduino()
{
    // Serial.begin(115200);
    WiFi.mode(WIFI_STA);

    configTime(0,0, "pool.ntp.org");

    _client.setFingerprint(telegramBotApiFP);
}

void InternetWifiArduino::connect() const
{
    WiFi.begin(ssid, password);

    while ( WiFi.status() != WL_CONNECTED )
       delay(1000);

    // Serial.println();
    // Serial.println("WiFi connected!");

    // Serial.print("Retrieving time: ");
    auto now = time(nullptr);
    while (now < 24*3600)
    {
        delay(100);
        now = time(nullptr);
    }
    // Serial.println(now);
}

void InternetWifiArduino::get(MyString url)
{
    HTTPClient https;
    https.begin(_client, url.c_str());

    int httpCode = https.GET();
    // Serial.print("Get: ");
    // Serial.println(url.c_str());
    // Serial.println();

    // httpCode will be negative on error
    if (httpCode > 0) 
    {
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
        {
            _reply = https.getString().c_str();
            // Serial.print("Answer: ");
            // Serial.println( _reply.c_str() );
        } else {
            // Serial.print("Http code: ");
            // Serial.println( httpCode );
        }
        // Serial.println();
        // Serial.println();
    }
    else 
    {
        // Serial.printf("Get request failed, error: %s\n", https.errorToString(httpCode).c_str());
    }

      https.end();
}

MyString InternetWifiArduino::reply() const
{
    return _reply;
}
#endif // PC


