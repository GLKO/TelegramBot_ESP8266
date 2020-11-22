#ifndef INTERNET_H
#define INTERNET_H

//#include "arduinoonpc.h"
#include "mystring.h"

#ifdef PC
#include <QNetworkAccessManager>
#else
#include <ESP8266WiFi.h>
#endif


class Internet
{
public:
    virtual void connect() const = 0;

    virtual void get(MyString url) = 0;
    virtual MyString reply() const = 0;

    virtual ~Internet() {}
};

#ifdef PC
class InternetPc : public Internet
{
public:
    InternetPc();

    void connect() const override;

    void get(MyString url) override;
    MyString reply() const override;

private:
    QNetworkAccessManager _internet;
    MyString _reply = "";

    void waitReply(QNetworkReply *reply) const;
};

#else

class InternetWifiArduino : public Internet
{
public:
    InternetWifiArduino();

    void connect() const override;

    void get(MyString url) override;
    MyString reply() const override;

private:
    WiFiClientSecure _client;
    MyString _reply = "";
};

#endif // PC

#endif // INTERNET_H
