#ifndef INTERNET_H
#define INTERNET_H

#include "arduinoonpc.h"

#ifdef PC
#include <QNetworkAccessManager>
#else
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#endif


class Internet
{
public:
    virtual void connect() const = 0;

    virtual void update() = 0;
    virtual void post(String url) = 0;
    virtual void get(String url) = 0;
    virtual String reply() const = 0;

    virtual ~Internet() {}
};

#ifdef PC
class InternetPc : public Internet
{
public:
    InternetPc();

    void connect() const override;

    void update() override;
    void post(String url) override;
    void get(String url) override;
    String reply() const override;

private:
    QNetworkAccessManager _internet;
    String _reply;

    void waitReply(QNetworkReply *reply) const;
};

#else

class InternetWifiArduino : public Internet
{
public:
    InternetWifiArduino(String wifiName, String password);

    void connect() const override;

    void update() override;
    void post(String url) override;
    void get(String url) override;
    String reply() const override;
};

#endif // PC

#endif // INTERNET_H
