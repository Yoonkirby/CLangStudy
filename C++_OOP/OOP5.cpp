/*
 * Banking System Ver 0.5
 * 작성자 : 윤성준
 * 내용 : AccountHandler라는 이름의 컨트롤 클래스 정의
 */
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

enum {Make = 1, Deposit, Withdrawal, ShowAll, Exit};


/*
 * 클래스 이름 : Account
 * 클래스 유형 : Entity 클래스
 */
class Account
{
    private:
        int accID;      // 계좌번호
        int balance;    // 잔액
        char * cusName; // 고객이름
    public:
        Account(int ID, int money, char * name);
        Account(const Account & copy);
        int ShowID() const;
        void Deposit(int money);
        int Withdrawal(int money);
        void ShowAccInfo() const;
        ~Account();
};

Account::Account(int ID, int money, char * name)
    : accID(ID), balance(money)
{
    cusName = new char[strlen(name)+1];
    strcpy(cusName, name);
}

Account::Account(const Account & copy)
    : accID(copy.accID), balance(copy.balance)
{
    cusName = new char[strlen(copy.cusName)+1];
    strcpy(cusName, copy.cusName);
}

int Account::ShowID() const
{
    return accID;
}

void Account::Deposit(int money)
{
    balance += money;
}

int Account::Withdrawal(int money)
{
    if(balance < money)
        return 0;

    balance -= money;
    return money;
}

void Account::ShowAccInfo() const
{
    cout<<"Account ID : "<<accID<<endl;
    cout<<"Name : "<<cusName<<endl;
    cout<<"Current Balance : "<<balance<<endl<<endl;
}

Account::~Account()
{
    delete []cusName;
}

/*
 * 클래스 이름 : AccountHandler
 * 클래스 유형 : 컨트롤(Control) 클래스
 */
class AccountHandler
{
    private:
        Account * acc[100];
        int accNum;
    public:
        AccountHandler();
        void ShowMenu(void) const;        // 메뉴출력
        void MakeAccount(void);           // 계좌개설
        void DepositMoney(void);          // 입   금
        void WithdrawalMoney(void);       // 출   금
        void ShowAllAccInfo(void) const;  // 잔액조회
        ~AccountHandler();
};

AccountHandler::AccountHandler() : accNum(0)
{ }

void AccountHandler::ShowMenu(void) const
{
    cout<<"-----------MENU-----------"<<endl;
    cout<<"1. Make a Account"<<endl;
    cout<<"2. Deposit Money"<<endl;
    cout<<"3. Withdrawal Money"<<endl;
    cout<<"4. Print All Account Info"<<endl;
    cout<<"5. Program Exit"<<endl;
}

void AccountHandler::MakeAccount(void)
{
    int id;
    char name[NAME_LEN];
    cout<<"Enter ID : "; cin>>id;
    cout<<"Enter Name : "; cin>>name;
    cout<<endl;

    acc[accNum++] = new Account(id, 0, name);
}

void AccountHandler::DepositMoney(void)
{
    int id, bal;
    cout<<"[Deposit]"<<endl;
    cout<<"Enter Your ID : "; cin>>id;
    for(int i = 0; i < accNum; i++)
    {
        if(acc[i]->ShowID() == id)
        {
            cout<<"Deposit amount : "; cin>>bal;
            acc[i]->Deposit(bal);
            cout<<"Deposit Complete"<<endl<<endl;
            return;
        }
    }
    cout<<"ID Not Found"<<endl<<endl;
}

void AccountHandler::WithdrawalMoney(void)
{
    int id, bal;
    cout<<"[Withdrawal]"<<endl;
    cout<<"Enter Your ID : "; cin>>id;
    for(int i = 0; i < accNum; i++)
    {
        if(acc[i]->ShowID() == id)
        {
            cout<<"Withdrawal amount : "; cin>>bal;
            if(acc[i]->Withdrawal(bal) == 0)
                cout<<"Insufficient Balance"<<endl;
            else
                cout<<"Withdrawal Complete"<<endl<<endl;
            return;
        }
    }
    cout<<"ID Not Found"<<endl<<endl;
}

void AccountHandler::ShowAllAccInfo(void) const
{
    for(int i = 0; i < accNum; i++)
    {
        acc[i]->ShowAccInfo();
    }
}

AccountHandler::~AccountHandler()
{
    for(int i = 0; i < accNum; i++)
        delete acc[i];
}

int main(void)
{
    AccountHandler handler;
    int enter = 0;
    while(1)
    {
        handler.ShowMenu();
        cout<<"Enter(1~5) : "; cin>>enter;
        cout<<endl;
        switch(enter)
        {
            case Make:
                handler.MakeAccount();
                break;
            case Deposit:
                handler.DepositMoney();
                break;
            case Withdrawal:
                handler.WithdrawalMoney();
                break;
            case ShowAll:
                handler.ShowAllAccInfo();
                break;
            case Exit:
                exit(0);
            default:
                cout<<"Invalid Enter"<<endl<<endl;
        }
    }
    return 0;
}