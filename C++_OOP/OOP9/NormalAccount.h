/*
 * 파일이름 : NormalAccount.h
 * 작성자 : 윤성준
 * 업데이트 정보 : [2022, 06, 07] 파일버전 0.9
 */
#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account
{
    private:
        int interest;    // 이자율
    public:
        NormalAccount(int ID, int money, String name, int inter)
            : Account(ID, money, name), interest(inter) { }
        int GetInterest() const
        {
            return interest;
        }
        void Deposit(int money)
        {
            int principal;
            principal = GetBalance();
            principal *= (0.01 * interest);
            Account::Deposit(money + principal);
        }
};
#endif