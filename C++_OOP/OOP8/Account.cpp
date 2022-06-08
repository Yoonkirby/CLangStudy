/*
 * 파일이름 : Account.cpp
 * 작성자 : 윤성준
 * 업데이트 정보 : [2022, 06, 08] 파일버전 0.8
 */

#include "BankingCommonDecl.h"
#include "Account.h"

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

Account& Account::operator=(const Account & copy)   // 추가된 정의
{
    accID = copy.accID;
    balance = copy.balance;

    delete []cusName;
    cusName = new char[strlen(copy.cusName)+1];
    strcpy(cusName, copy.cusName);
    return *this;
}

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