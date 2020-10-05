#include "internet.h"

#include "mystring.h"

#ifdef PC
#include <QNetworkReply>
#include <QCoreApplication>

InternetPc::InternetPc()
{

}

void InternetPc::connect() const
{

}

void InternetPc::update()
{

}

void InternetPc::post(String url)
{
    auto reply = _internet.get(QNetworkRequest(QUrl(url.c_str())));
    qDebug() << "Post request sent" << '\n' << url.c_str();

    waitReply(reply);

    QTextStream str(reply);
    _reply = str.readAll().toStdString().c_str();
    qDebug() << _reply.c_str();
}

void InternetPc::get(String url)
{
    auto reply = _internet.get(QNetworkRequest(QUrl(url.c_str())));
    qDebug() << "Get request sent";

    waitReply(reply);

    QTextStream str(reply);
    _reply = str.readAll().toStdString().c_str();
    qDebug() << _reply.c_str();
}

String InternetPc::reply() const
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

InternetWifiArduino::InternetWifiArduino(String wifiName, String password)
{

}

void InternetWifiArduino::connect() const
{
    //    WiFi.begin(ssid, password);

    //    while ( WiFi.status() != WL_CONNECTED )
    //        delay(1000);
}

void InternetWifiArduino::update()
{

}

void InternetWifiArduino::post(String url)
{

}

void InternetWifiArduino::get(String url)
{

}

String InternetWifiArduino::reply() const
{
    return String();
}
#endif // PC
