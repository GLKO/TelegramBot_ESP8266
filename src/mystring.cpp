#include "mystring.h"

#include <string.h>


String::String()
{}

String::String(const char *str)
{
    *this = str;
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


char *String::c_str() const
{
    return _str;
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
