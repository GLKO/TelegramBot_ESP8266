#include "mystring.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

String::String()
{}

String::String(const char *str)
{
    *this = str;
}

String::String(const char *str, double num)
{
    _str = new char[strlen(str) + sizeof (num) * 8 + 1];
    sprintf(_str, str, num);
}

String::String(long num)
{
    _str = new char[sizeof (num) * 8 + 1];
    sprintf(_str, "%li", num);
}

String::String(const String &str)
{
    *this = str;
}

String::String(String &&str)
{
    _str = str._str;
    str._str = nullptr;
}


const char *String::c_str() const
{
    return _str;
}

size_t String::length() const
{
    return strlen(_str);
}

String String::removeBeginTo(const String &str , const String &defStr) const
{
    const char *begin = strstr(_str, str.c_str());

    if ( begin == nullptr ) return defStr;

    begin += strlen(str.c_str());

    return String(begin);
}

String String::findNum(const String &str, const String &defStr) const
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
    String result(begin);
    *end = temp;

    return result;
}

long String::toLong() const
{
    return atol(_str);
}

String String::operator +(const String &anotherStr) const
{
    auto length = strlen(anotherStr._str) + strlen(this->_str) + 1;
    auto res = new char[length];
    res[0] = '\0';
    strcat_s(res, length, _str);
    strcat_s(res, length, anotherStr._str);
    String result;
    result._str = res;
    return result;
}

void String::operator =(const char *anotherStr)
{
    auto length = strlen( anotherStr ) + 1;
    clear();
    _str = new char[length+1];
    strcpy_s( _str, length, anotherStr );
}

void String::operator =(const String &anotherStr)
{
    *this = anotherStr._str;
}

void String::clear()
{
    if ( _str != nullptr )
    {
        delete _str;
        _str = nullptr;
    }
}

String::~String()
{
    clear();
}

String operator +(const char *oneStr, const String &anotherStr)
{
    return String(oneStr) + anotherStr;
}
