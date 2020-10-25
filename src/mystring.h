#ifndef STRING_H
#define STRING_H

#include <string.h>

class MyString
{
public:
    MyString();
    MyString(const char *str);
    MyString(const char *str, double num);
    MyString(long num);
    MyString(double num);
    MyString(const MyString &str);
    MyString(MyString &&str);

    const char *c_str() const;
    size_t length() const;
    MyString removeBeginTo(const MyString &str, const MyString &defStr = "") const;
    MyString findNum(const MyString &str, const MyString &defStr = "") const;
    long toLong() const;
    void clear();

    MyString operator +(const MyString &anotherStr) const;

    void operator =(const char *anotherStr);
    void operator =(const MyString &anotherStr);

    ~MyString();

private:
    char *_str = nullptr;
};

MyString operator +(const char *oneStr, const MyString &anotherStr);

#endif // STRING_H
