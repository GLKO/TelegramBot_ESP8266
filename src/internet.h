#ifndef INTERNET_H
#define INTERNET_H

#include "arduinoonpc.h"

class Internet
{
public:
    virtual void connect() const = 0;

    virtual void post(String url) const = 0;
    virtual String get(String url) const = 0;

    virtual ~Internet() {}
};


class InternetPc : public Internet
{
public:
    InternetPc();

    void connect() const override;
    void post(String url) const override;
    String get(String url) const override;
};


class InternetWifiArduino : public Internet
{
public:
    InternetWifiArduino(String wifiName, String password);

    void connect() const override;
    void post(String url) const override;
    String get(String url) const override;
};


#endif // INTERNET_H
