#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    int len;
    char * str;
public:
    String()
    {
        len = 0;
        str = NULL;
    }
    String(const char * ref) : len(strlen(ref) + 1)
    {
        str = new char(len);
        strcpy(str, ref);
    }
    String(const String& ref)
    {
        len = ref.len;
        str = new char[len];
        strcpy(str, ref.str);
    }
    ~String()
    {
        if(str != NULL)
            delete []str;
    }
    String operator+(const String& ref)
    {
        char * tmpstr = new char[len + ref.len - 1];
        strcpy(tmpstr, str);
        strcat(tmpstr, ref.str);
        String tmp(tmpstr);
        delete []tmpstr;
        return tmp;
    }
    String& operator=(const String& ref)
    {
        if(str != NULL)
            delete []str;
        len = ref.len;
        str = new char[len];
        strcpy(str, ref.str);
        return *this;
    }
    String& operator+=(const String& ref)
    {
        /*len += (ref.len - 1);
        char * tmpstr = new char[len];
        strcpy(tmpstr, str);
        strcat(tmpstr, ref.str);
        if(str != NULL)
            delete []str;
        str = tmpstr;*/
        *this = *this + ref;
        return *this;
    }
    bool operator==(const String& ref)
    {
        if(str == ref.str)
            return true;
        else
            return false;
    }
    friend ostream& operator<<(ostream& op, String& ref);
    friend istream& operator>>(istream& ip, String& ref);
};
ostream& operator<<(ostream& os, String& ref)
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

int main(void)
{
    String str1 = "I like ";
    String str2 = "string class";
    String str3 = str1 + str2;

    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;

    str1+=str2;
    if(str1 == str3)
        cout<<"Same string"<<endl;
    else
        cout<<"Different string"<<endl;
    
    string str4;
    cout<<"Enter the string : ";
    cin>>str4;
    cout<<"Input string data : "<<str4<<endl;

    return 0;
}