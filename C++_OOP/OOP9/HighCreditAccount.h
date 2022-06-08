/*
 * 파일이름 : HighCreditAccount.h
 * 작성자 : 윤성준
 * 업데이트 정보 : [2022, 06, 07] 파일버전 0.7
 */

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
    private:
        int credit;
    public:
        HighCreditAccount(int ID, int money, String name, int inter, int cred)
            : NormalAccount(ID, money, name, inter), credit(cred) { }
        void Deposit(int money)
        {
            int principal;
            principal = GetBalance();
            principal *= (0.01 * (GetInterest() + credit));
            Account::Deposit(money + principal);
        }
};

#endif