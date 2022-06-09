/*
 * 파일이름 : Account.cpp
 * 작성자 : 윤성준
 * 업데이트 정보 : [2022, 06, 08] 파일버전 0.11
 */

#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountExeption.h"

Account::Account(int ID, int money, String name)
    : accID(ID), balance(money), cusName(name) { }

int Account::GetID() const
{
    return accID;
}

int Account::GetBalance() const
{
    return balance;
}

void Account::Deposit(int money)
{
    if(money < 0)
    {
        MinusException expn(money);
        throw expn;
    }
    balance += money;
}

void Account::Withdrawal(int money)
{
    if(balance < money)
    {
        InsuffException expn(balance, money);
        throw expn;
    }
    balance -= money;
}

void Account::ShowAccInfo() const
{
    cout<<"Account ID : "<<accID<<endl;
    cout<<"Name : "<<cusName<<endl;
    cout<<"Current Balance : "<<balance<<endl<<endl;
}