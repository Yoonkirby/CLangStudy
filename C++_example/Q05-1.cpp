#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum {CLERK, SENIOR, ASSIST, MANAGER};

    void ShowPositionInfo(int pos)
    {
        switch(pos)
        {
            case CLERK:
                cout<<"사원"<<endl;
                break;
            case SENIOR:
                cout<<"주임"<<endl;
                break;
            case ASSIST:
                cout<<"대리"<<endl;
                break;
            case MANAGER:
                cout<<"과장"<<endl;
        }
    }
}

class NameCard
{
    private:
        char * name;
        char * company;
        char * phone;
        int position;
    public:
        NameCard(const char * _name,const char * _company,const char * _phone, int pos)
            : position(pos)
        {
            name = new char[strlen(_name)+1];
            company = new char[strlen(_company)+1];
            phone = new char[strlen(_phone)+1];
            strcpy(name,_name);
            strcpy(company,_company);
            strcpy(phone,_phone);
        }
        NameCard(const NameCard & copy)
            : position(copy.position)
        {
            name = new char[strlen(copy.name)+1];
            strcpy(name,copy.name);
            company = new char[strlen(copy.company)+1];
            strcpy(company,copy.company);
            phone = new char[strlen(copy.phone)+1];
            strcpy(phone,copy.phone);
        }
        void ShowNameCardInfo()
        {
            cout<<"이름 : "<<name<<endl;
            cout<<"회사 : "<<company<<endl;
            cout<<"전화번호 : "<<phone<<endl;
            cout<<"직급 : "; COMP_POS::ShowPositionInfo(position);
            cout<<endl;
        }
        ~NameCard()
        {
            delete []name;
            delete []company;
            delete []phone;
        }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::MANAGER);
    NameCard copy1 = manClerk;
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::ASSIST);
    NameCard copy2 = manSENIOR;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    return 0;
}