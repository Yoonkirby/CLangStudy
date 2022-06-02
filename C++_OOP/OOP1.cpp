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

typedef struct
{
    int accID;      // 계좌번호
    int balance;    // 잔액
    char cusName[NAME_LEN]; // 고객이름
}Account;

Account acc[100];
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
    // int id;
    // char name[NAME_LEN];
    // cout<<"Enter ID : "; cin>>id;
    // cout<<"Enter Name : "; cin>>name;
    // cout<<endl;

    // acc[accNum].accID = id;
    // acc[accNum].balance = 0;
    // strcpy(acc[accNum].cusName, name);
    // accNum++;
    cout<<"Enter ID : "; cin>>acc[accNum].accID;
    cout<<"Enter Name : "; cin>>acc[accNum].cusName;
    cout<<endl;
    acc[accNum].balance = 0;
    accNum++;
}

void DepositMoney(void)
{
    int id, bal;
    cout<<"[Deposit]"<<endl;
    cout<<"Enter Your ID"; cin>>id;
    for(int i = 0; i < accNum; i++)
    {
        if(acc[i].accID == id)
        {
            cout<<"Deposit amount : "; cin>>bal;
            acc[i].balance += bal;
            cout<<"Deposit Complete"<<endl<<endl;
        }
        else
            cout<<"ID Not Found"<<endl<<endl;
    }
}

void WithdrawalMoney(void)
{
    int id, bal;
    cout<<"[Withdrawal]"<<endl;
    cout<<"Enter Your ID"; cin>>id;
    for(int i = 0; i < accNum; i++)
    {
        if(acc[i].accID == id)
        {
            cout<<"Withdrawal amount : "; cin>>bal;
            acc[i].balance -= bal;
            cout<<"Withdrawal Complete"<<endl<<endl;
        }
        else
            cout<<"ID Not Found"<<endl<<endl;
    }
}

void ShowAllAccInfo(void)
{
    for(int i = 0; i < accNum; i++)
    {
        cout<<"Account ID : "<<acc[i].accID<<endl;
        cout<<"Name : "<<acc[i].cusName<<endl;
        cout<<"Current Balance : "<<acc[i].balance<<endl;
    }
}