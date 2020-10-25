#include "mystring.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

MyString::MyString()
{}

MyString::MyString(const char *str)
{
    *this = str;
}

MyString::MyString(const char *str, double num)
{
    _str = new char[strlen(str) + sizeof (num) * 8 + 1];
    sprintf(_str, str, num);
}

MyString::MyString(long num)
{
    _str = new char[sizeof (num) * 8 + 1];
    sprintf(_str, "%li", num);
}

MyString::MyString(const MyString &str)
{
    *this = str;
}

MyString::MyString(MyString &&str)
{
    _str = str._str;
    str._str = nullptr;
}


const char *MyString::c_str() const
{
    return _str;
}

size_t MyString::length() const
{
    return strlen(_str);
}

MyString MyString::removeBeginTo(const MyString &str , const MyString &defStr) const
{
    const char *begin = strstr(_str, str.c_str());

    if ( begin == nullptr ) return defStr;

    begin += strlen(str.c_str());

    return MyString(begin);
}

MyString MyString::findNum(const MyString &str, const MyString &defStr) const
{
    char *begin = strstr(_str, str.c_str());

    if ( begin == nullptr ) return defStr;

    begin += strlen(str.c_str());
    auto end = begin + 1;

    while ( isdigit(*end) )
    {
        ++end;
    }
    char temp = *end;
    *end = '\0'; //CRUNCH!!!!!!!!!!!!
    MyString result(begin);
    *end = temp;

    return result;
}

long MyString::toLong() const
{
    return atol(_str);
}

MyString MyString::operator +(const MyString &anotherStr) const
{
    auto length = strlen(anotherStr._str) + strlen(this->_str) + 1;
    auto res = new char[length];
    res[0] = '\0';
    strcat_s(res, length, _str);
    strcat_s(res, length, anotherStr._str);
    MyString result;
    result._str = res;
    return result;
}

void MyString::operator =(const char *anotherStr)
{
    auto length = strlen( anotherStr ) + 1;
    clear();
    _str = new char[length+1];
    strcpy_s( _str, length, anotherStr );
}

void MyString::operator =(const MyString &anotherStr)
{
    *this = anotherStr._str;
}

void MyString::clear()
{
    if ( _str != nullptr )
    {
        delete _str;
        _str = nullptr;
    }
}

MyString::~MyString()
{
    clear();
}

MyString operator +(const char *oneStr, const MyString &anotherStr)
{
    return MyString(oneStr) + anotherStr;
}
