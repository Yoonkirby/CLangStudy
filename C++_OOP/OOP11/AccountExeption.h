/*
 * 파일이름 : AccountException.h
 * 작성자 : 윤성준
 * 업데이트 정보 : [2022, 06, 07] 파일버전 0.11
 */

#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

class MinusException
{
    private:
        int exval;  // 예외의 원인이 되는 금액
    public:
        MinusException(int val) :exval(val) { }
        void ShowExceptionReason() const
        {
            cout<<exval<<" cannot be deposited!"<<endl;
        }
};

class InsuffException
{
    private:
        int balance;    // 현재 잔액
        int reqval;     // 출금 요구액
    public:
        InsuffException(int val, int req) :balance(val), reqval(req) { }
        void ShowExceptionReason() const
        {
            cout<<reqval-balance<<"is insufficient from the balance"<<endl;
        }
};
#endif