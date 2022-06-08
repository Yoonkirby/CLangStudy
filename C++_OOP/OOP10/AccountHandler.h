/*
 * 파일이름 : AccountHandler.h
 * 작성자 : 윤성준
 * 업데이트 정보 : [2022, 06, 07] 파일버전 0.10
 */

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler
{
    private:
        BoundCheckArray<Account *> acc;
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
#endif