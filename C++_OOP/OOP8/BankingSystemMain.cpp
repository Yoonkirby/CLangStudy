/*
 * 소프트웨어 버전 : Banking System Ver 0.7
 *
 * 파일이름 : BankingSystemMain.cpp
 * 작성자 : 윤성준
 * 업데이트 정보 : [2022, 06, 07] 파일버전 0.7
 */

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void)
{
    AccountHandler handler;
    int enter = 0;
    while(1)
    {
        handler.ShowMenu();
        cout<<"Enter(1~5) : "; cin>>enter;
        cout<<endl;
        switch(enter)
        {
            case Make:
                handler.MakeAccount();
                break;
            case Deposit:
                handler.DepositMoney();
                break;
            case Withdrawal:
                handler.WithdrawalMoney();
                break;
            case ShowAll:
                handler.ShowAllAccInfo();
                break;
            case Exit:
                exit(0);
            default:
                cout<<"Invalid Enter"<<endl<<endl;
        }
    }
    return 0;
}