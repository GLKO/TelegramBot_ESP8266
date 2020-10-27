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

const char TELEGRAM_CERTIFICATE_ROOT[] = R"=EOF=(
-----BEGIN CERTIFICATE-----
MIIDxTCCAq2gAwIBAgIBADANBgkqhkiG9w0BAQsFADCBgzELMAkGA1UEBhMCVVMx
EDAOBgNVBAgTB0FyaXpvbmExEzARBgNVBAcTClNjb3R0c2RhbGUxGjAYBgNVBAoT
EUdvRGFkZHkuY29tLCBJbmMuMTEwLwYDVQQDEyhHbyBEYWRkeSBSb290IENlcnRp
ZmljYXRlIEF1dGhvcml0eSAtIEcyMB4XDTA5MDkwMTAwMDAwMFoXDTM3MTIzMTIz
NTk1OVowgYMxCzAJBgNVBAYTAlVTMRAwDgYDVQQIEwdBcml6b25hMRMwEQYDVQQH
EwpTY290dHNkYWxlMRowGAYDVQQKExFHb0RhZGR5LmNvbSwgSW5jLjExMC8GA1UE
AxMoR28gRGFkZHkgUm9vdCBDZXJ0aWZpY2F0ZSBBdXRob3JpdHkgLSBHMjCCASIw
DQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAL9xYgjx+lk09xvJGKP3gElY6SKD
E6bFIEMBO4Tx5oVJnyfq9oQbTqC023CYxzIBsQU+B07u9PpPL1kwIuerGVZr4oAH
/PMWdYA5UXvl+TW2dE6pjYIT5LY/qQOD+qK+ihVqf94Lw7YZFAXK6sOoBJQ7Rnwy
DfMAZiLIjWltNowRGLfTshxgtDj6AozO091GB94KPutdfMh8+7ArU6SSYmlRJQVh
GkSBjCypQ5Yj36w6gZoOKcUcqeldHraenjAKOc7xiID7S13MMuyFYkMlNAJWJwGR
tDtwKj9useiciAF9n9T521NtYJ2/LOdYq7hfRvzOxBsDPAnrSTFcaUaz4EcCAwEA
AaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMCAQYwHQYDVR0OBBYE
FDqahQcQZyi27/a9BUFuIMGU2g/eMA0GCSqGSIb3DQEBCwUAA4IBAQCZ21151fmX
WWcDYfF+OwYxdS2hII5PZYe096acvNjpL9DbWu7PdIxztDhC2gV7+AJ1uP2lsdeu
9tfeE8tTEH6KRtGX+rcuKxGrkLAngPnon1rpN5+r5N9ss4UXnT3ZJE95kTXWXwTr
gIOrmgIttRD02JDHBHNA7XIloKmf7J6raBKZV8aPEjoJpL1E/QYVN8Gb5DKj7Tjo
2GTzLH4U/ALqn83/B2gX2yKQOC16jdFU8WnjXzPKej17CuPKf1855eJ1usV2GDPO
LPAvTK33sefOT6jEm0pUBsV/fdUID+Ic/n4XuKxe9tQWskMJDE32p2u0mYRlynqI
4uJEvlz36hz1
-----END CERTIFICATE-----
)=EOF=";


InternetWifiArduino::InternetWifiArduino()
    : _sertificate(TELEGRAM_CERTIFICATE_ROOT)
{
    Serial.begin(9600);

    configTime(0,0, "pool.ntp.org");
    _client.setTrustAnchors(&_sertificate);
}

void InternetWifiArduino::connect() const
{
    WiFi.begin(ssid, password);

    while ( WiFi.status() != WL_CONNECTED )
       delay(1000);

    Serial.println();
    Serial.println("WiFi connected!");

    Serial.print("Retrieving time: ");
    auto now = time(nullptr);
    while (now < 24*3600)
    {
        delay(100);
        now = time(nullptr);
    }
    Serial.println(now);
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
    return _reply;
}
#endif // PC
