#ifndef INTERNET_H
#define INTERNET_H

#include "mystring.h"


class Internet
{
public:
    virtual void connect() const = 0;
    virtual void loop() = 0;

    virtual void get(MyString url) = 0;
    virtual bool replyReady() const = 0;
    virtual MyString reply() const = 0;

    virtual ~Internet() {}
};

#ifdef PC
#include <QNetworkAccessManager>
#include <QNetworkReply>

class InternetPc : public Internet
{
public:
    InternetPc();

    void connect() const override;
    void loop() override;

    void get(MyString url) override;
    bool replyReady() const override;
    MyString reply() const override;

private:
    MyString _replyStr = "";

    QNetworkAccessManager _internet;
    QNetworkReply *_replyObj;
    bool _replyReady = true;
};

#else
#include <ESP8266WiFi.h>

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
