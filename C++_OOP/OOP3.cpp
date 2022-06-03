/*
 * Banking System Ver 0.3
 * 작성자 : 윤성준
 * 내용 : 깊은 복사를 원칙으로 복사 생성자 추가
 */
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);        // 메뉴출력
void MakeAccount(void);     // 계좌개설
void DepositMoney(void);    // 입   금
void WithdrawalMoney(void);   // 출   금
void ShowAllAccInfo(void);  // 잔액조회

enum {Make = 1, Deposit, Withdrawal, ShowAll, Exit};

class Account
{
    private:
        int accID;      // 계좌번호
        int balance;    // 잔액
        char * cusName; // 고객이름
    public:
        Account(int ID, int money, char * name)
            : accID(ID), balance(money)
        {
            cusName = new char[strlen(name)+1];
            strcpy(cusName, name);
        }
        Account(const Account & copy)
            : accID(copy.accID), balance(copy.balance)
        {
            cusName = new char[strlen(copy.cusName)+1];
            strcpy(cusName, copy.cusName);
        }
        int ShowID()
        {return accID;}
        void Deposit(int money)
        {balance += money;}
        int Withdrawal(int money)
        {
            if(balance < money)
                return 0;

            balance -= money;
            return money;
        }
        const void ShowAccInfo()
        {
            cout<<"Account ID : "<<accID<<endl;
            cout<<"Name : "<<cusName<<endl;
            cout<<"Current Balance : "<<balance<<endl<<endl;
        }
        ~Account()
        {delete []cusName;}
};

Account * acc[100];
int accNum = 0;

int main(void)
{
    int enter = 0;
    while(1)
    {
        ShowMenu();
        cout<<"Enter(1~5) : "; cin>>enter;
        cout<<endl;
        switch(enter)
        {
            case Make:
                MakeAccount();
                break;
            case Deposit:
                DepositMoney();
                break;
            case Withdrawal:
                WithdrawalMoney();
                break;
            case ShowAll:
                ShowAllAccInfo();
                break;
            case Exit:
                delete []acc;
                exit(0);
            default:
                cout<<"Invalid Enter"<<endl<<endl;
        }
    }
    return 0;
}

void ShowMenu(void)
{
    cout<<"-----------MENU-----------"<<endl;
    cout<<"1. Make a Account"<<endl;
    cout<<"2. Deposit Money"<<endl;
    cout<<"3. Withdrawal Money"<<endl;
    cout<<"4. Print All Account Info"<<endl;
    cout<<"5. Program Exit"<<endl;
}

void MakeAccount(void)
{
    int id;
    char name[NAME_LEN];
    cout<<"Enter ID : "; cin>>id;
    cout<<"Enter Name : "; cin>>name;
    cout<<endl;

    acc[accNum++] = new Account(id, 0, name);
}

void DepositMoney(void)
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

void WithdrawalMoney(void)
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

void ShowAllAccInfo(void)
{
    for(int i = 0; i < accNum; i++)
    {
        acc[i]->ShowAccInfo();
    }
}