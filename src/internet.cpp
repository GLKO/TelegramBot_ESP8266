#include "internet.h"

// #include "mystring.h"
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

void InternetPc::update()
{

}

void InternetPc::post(MyString url)
{
    auto reply = _internet.get(QNetworkRequest(QUrl(url.c_str())));
    qDebug() << "Post request sent" << '\n' << url.c_str();

    waitReply(reply);

    QTextStream str(reply);
    _reply = str.readAll().toStdString().c_str();
    qDebug() << _reply.c_str();
}

void InternetPc::get(MyString url)
{
    auto reply = _internet.get(QNetworkRequest(QUrl(url.c_str())));
    qDebug() << "Get request sent";

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

InternetWifiArduino::InternetWifiArduino()
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

void InternetWifiArduino::post(MyString url)
{

}

void InternetWifiArduino::get(MyString url)
{

}

MyString InternetWifiArduino::reply() const
{
    return MyString();
}
#endif // PC
