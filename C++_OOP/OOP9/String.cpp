/*
 * 파일이름 : String.cpp
 * 작성자 : 윤성준
 * 업데이트 정보 : [2022, 06, 08] 파일버전 0.9
 */

#include "BankingCommonDecl.h"
#include "String.h"

String::String()
{
    len = 0;
    str = NULL;
}

String::String(const char * ref) : len(strlen(ref)+1)
{
    str = new char(len);
    strcpy(str, ref);
}

String::String(const String& ref)
{
    len = ref.len; 
    str = new char[len];
    strcpy(str, ref.str);
}

String::~String()
{
    if(str != NULL)
        delete []str;
}

String& String::operator=(const String& ref)
{
    if(str != NULL)
        delete []str;
    len = ref.len;
    str = new char[len];
    strcpy(str, ref.str);
    return *this;
}

String& String::operator+=(const String& ref)
{
    len += (ref.len-1);
    char * tmpstr = new char[len];
    strcpy(tmpstr, str);
    strcat(tmpstr, ref.str);
    if(str != NULL)
        delete []str;
    str = tmpstr;
    //*this = *this + ref;
    return *this;
}

bool String::operator==(const String& ref)
{
    return strcmp(str, ref.str) ? false : true;
}

String String::operator+(const String& ref)
{
    char * tmpstr = new char[len + ref.len - 1];
    strcpy(tmpstr, str);
    strcat(tmpstr, ref.str);
    String tmp(tmpstr);
    delete []tmpstr;
    return tmp;
}

ostream& operator<<(ostream& os, const String& ref)
{
    os<<ref.str;
    return os;
}

istream& operator>>(istream& is, String& ref)
{
    char str[100];
    is>>str;
    ref = String(str);
    return is;
}