/*
 * Banking System Ver 0.6
 * 작성자 : 윤성준
 * 내용 : 이자관련 계좌 클래스의 추가
 */
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

// 프로그램 사용자의 선택 메뉴
enum {Make = 1, Deposit, Withdrawal, ShowAll, Exit};

//신용등급
enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};

//계좌의 종류
enum {NORMAL = 1, CREDIT = 2};

/*
 * 클래스 이름 : Account
 * 클래스 유형 : Entity 클래스
 */
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

/*
 * 클래스 이름 : NormalAccount
 * 클래스 유형 : Entity 클래스
 */
class NormalAccount : public Account
{
    private:
        int interest;    // 이자율
    public:
        NormalAccount(int ID, int money, char * name, int inter)
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

/*
 * 클래스 이름 : HighCreditAccount
 * 클래스 유형 : Entity 클래스
 */
class HighCreditAccount : public NormalAccount
{
    private:
        int credit;
    public:
        HighCreditAccount(int ID, int money, char * name, int inter, int cred)
            : NormalAccount(ID, money, name, inter), credit(cred) { }
        void Deposit(int money)
        {
            int principal;
            principal = GetBalance();
            principal *= (0.01 * (GetInterest() + credit));
            Account::Deposit(money + principal);
        }
};

/*
 * 클래스 이름 : AccountHandler
 * 클래스 유형 : 컨트롤(Control) 클래스
 */
class AccountHandler
{
    private:
        Account * acc[100];
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
    char name[NAME_LEN];
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
    for(int i = 0; i < accNum; i++)
    {
        if(acc[i]->GetID() == id)
        {
            cout<<"Deposit amount : "; cin>>money;
            acc[i]->Deposit(money);
            cout<<"Deposit Complete"<<endl<<endl;
            return;
        }
    }
    cout<<"ID Not Found"<<endl<<endl;
}

void AccountHandler::WithdrawalMoney(void)
{
    int id, money;
    cout<<"[Withdrawal]"<<endl;
    cout<<"Enter Your ID : "; cin>>id;
    for(int i = 0; i < accNum; i++)
    {
        if(acc[i]->GetID() == id)
        {
            cout<<"Withdrawal amount : "; cin>>money;
            if(acc[i]->Withdrawal(money) == 0)
                cout<<"Insufficient Balance"<<endl;
            else
                cout<<"Withdrawal Complete"<<endl<<endl;
            return;
        }
    }
    cout<<"ID Not Found"<<endl<<endl;
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