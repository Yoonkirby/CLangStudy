#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
    private:
        char * name;
        int age;
    public:
        MyFriendInfo(const char * fname, int fage)
            :age(fage)
        {
            name = new char[strlen(fname)+1];
            strcpy(name,fname);
        }
        void ShowMyFriendInfo()
        {
            cout<<"Name : "<<name<<endl;
            cout<<"Age : "<<age<<endl;
        }
        ~MyFriendInfo()
        {
            delete []name;
        }
};

class MyFriendDetailInfo :public MyFriendInfo
{
    private:
        char * addr;
        char * phone;
    public:
        MyFriendDetailInfo(const char * fname, int age,const char * faddr,const char * fphone)
            :MyFriendInfo(fname,age)
        {
            addr = new char[strlen(faddr)+1];
            strcpy(addr,faddr);
            phone = new char[strlen(fphone)+1];
            strcpy(phone,fphone);
        }
        void ShowMyFriendDetailInfo()
        {
            ShowMyFriendInfo();
            cout<<"Address : "<<addr<<endl;
            cout<<"Phone Number : "<<phone<<endl;
        }
        ~MyFriendDetailInfo()
        {
            delete []addr;
            delete []phone;
        }
};

int main(void)
{
    MyFriendDetailInfo yoon("yoon seongjune",30,"incheon","010-9983-7066");
    yoon.ShowMyFriendDetailInfo();
    return 0;
}