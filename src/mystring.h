#ifndef STRING_H
#define STRING_H


class String
{
public:
    String();
    String(const char *str);
    String(const String &str);
    String(String &&str);

    char *c_str() const;
    void clear();

    String operator +(const String &anotherStr) const;
//    String operator +(const char *anotherStr) const;

    void operator =(const char *anotherStr);
    void operator =(const String &anotherStr);

    ~String();

private:
    char *_str = nullptr;
};

String operator +(const char *oneStr, const String &anotherStr);

#endif // STRING_H
