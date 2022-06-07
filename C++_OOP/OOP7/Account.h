/*
 * 파일이름 : Account.h
 * 작성자 : 윤성준
 * 업데이트 정보 : [2022, 06, 07] 파일버전 0.7
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
    private:
        int accID;      // 계좌번호
        int balance;    // 잔액
        char * cusName; // 고객이름
    public:
        Account(int ID, int money, char * name);
        Account(const Account & copy);
        
        int GetID() const;
        int GetBalance() const;
        virtual void Deposit(int money);
        int Withdrawal(int money);
        void ShowAccInfo() const;
        ~Account();
};

#endif