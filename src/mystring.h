#ifndef STRING_H
#define STRING_H

#include <string.h>

class String
{
public:
    String();
    String(const char *str);
    String(const char *str, double num);
    String(long num);
    String(double num);
    String(const String &str);
    String(String &&str);

    const char *c_str() const;
    size_t length() const;
    String removeBeginTo(const String &str, const String &defStr = "") const;
    String findNum(const String &str, const String &defStr = "") const;
    long toLong() const;
    void clear();

    String operator +(const String &anotherStr) const;

    void operator =(const char *anotherStr);
    void operator =(const String &anotherStr);

    ~String();

private:
    char *_str = nullptr;
};

String operator +(const char *oneStr, const String &anotherStr);

#endif // STRING_H
