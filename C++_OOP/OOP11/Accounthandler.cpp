/*
 * 파일이름 : AccountHandler.cpp
 * 작성자 : 윤성준
 * 업데이트 정보 : [2022, 06, 07] 파일버전 0.11
 */

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountExeption.h"

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
    int enter, id, money, interest;
    String name;
    while(1)
    {
        cout<<"[Select Account Type]"<<endl;
        cout<<"1. Normal Account  2. High Credit Account"<<endl;
        cout<<"Enter(1 ~ 2) : "; cin>>enter;
        cout<<"Enter ID : "; cin>>id;
        cout<<"Enter Name : "; cin>>name;
        cout<<"Deposit amount : "; cin>>money;
        cout<<"Interest Rate : "; cin>>interest;
        if(enter == 1)
        {
            cout<<endl;
            acc[accNum++] = new NormalAccount(id, money, name, interest);
            break;
        }
        else if(enter == 2)
        {
            int credit;
            while(1)
            {
                cout<<"Credit Rate(A = 1, B = 2, C = 3) : "; cin>>credit;
                cout<<endl;
                if(credit >= 1 && credit <= 3)
                    break;
                cout<<"Invalid Enter"<<endl<<endl;
            }
            switch(credit)
            {
                case 1:
                    credit = LEVEL_A;
                    break;
                case 2:
                    credit = LEVEL_B;
                    break;
                case 3:
                    credit = LEVEL_C;
            }
            acc[accNum++] = new HighCreditAccount(id, money, name, interest, credit);
            break;
        }
        cout<<"Invalid Enter"<<endl<<endl;
    }
}

void AccountHandler::DepositMoney(void)
{
    int id, money;
    cout<<"[Deposit]"<<endl;
    cout<<"Enter Your ID : "; cin>>id;
    while(1)
    {
        cout<<"Deposit amount : "; cin>>money;
        try
        {
            for(int i = 0; i < accNum; i++)
            {
                if(acc[i]->GetID() == id)
                {
                    acc[i]->Deposit(money);
                    cout<<"Deposit Complete"<<endl<<endl;
                    return;
                }
            }
            cout<<"ID Not Found"<<endl<<endl;
            return;
        }
        catch(MinusException &ex)
        {
            ex.ShowExceptionReason();
            cout<<"Re-enter Deposit"<<endl;
        }
    }
}

void AccountHandler::WithdrawalMoney(void)
{
    int id, money;
    cout<<"[Withdrawal]"<<endl;
    cout<<"Enter Your ID : "; cin>>id;
    while(true)
    {
        cout<<"Withdrawal amount : "; cin>>money;
        try
        {
            for(int i = 0; i < accNum; i++)
            {
                if(acc[i]->GetID() == id)
                {
                    acc[i]->Withdrawal(money);
                    cout<<"Withdrawal Complete"<<endl<<endl;
                    return;
                }
            }
            cout<<"ID Not Found"<<endl<<endl;
            return;
        }
        catch(InsuffException &ex)
        {
            ex.ShowExceptionReason();
            cout<<"Re-enter Withdrawal"<<endl;
        }
    }
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