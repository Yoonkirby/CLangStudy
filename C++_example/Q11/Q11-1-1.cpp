#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet;
public:
    Gun(int bnum) : bullet(bnum)
    { }
    Gun(const Gun & copy) : bullet(copy.bullet)
    { }
    void Shot()
    {
        if(bullet > 0)
        {
            cout<<"BBANG!"<<endl;
            bullet--;
        }
        else
            cout<<"TIK!"<<endl;
    }
};

class Police
{
private:
    int handcuffs;
    Gun * pistol;
public:
    Police(int bnum, int bcuff)
        : handcuffs(bcuff)
    {
        if(bnum>0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }
    Police(const Police & copy)
        : handcuffs(copy.handcuffs)
    {
        if(copy.pistol != NULL)
            pistol = new Gun(*(copy.pistol));
        else
            pistol = NULL;
    }
    Police & operator=(const Police & copy)
    {
        handcuffs = copy.handcuffs;
         if(copy.pistol != NULL)
            pistol = new Gun(*(copy.pistol));
        else
            pistol = NULL;
        return *this;
    }
    void PutHandcuff()
    {
        cout<<"SNAP!"<<endl;
        handcuffs--;
    }
    void Shot()
    {
        if(pistol == NULL)
            cout<<"TIK!"<<endl;
        else
            pistol->Shot();
    }
    ~Police()
    {
        if(pistol != NULL)
            delete pistol;
    }
};

int main(void)
{
    Police pman1(5, 3);
    pman1.Shot();
    pman1.PutHandcuff();
    cout<<endl;

    Police pman2 = pman1;   // (4, 2)
    pman2.Shot();           // (3, 2)
    pman2.PutHandcuff();    // (3, 1)
    cout<<endl;

    pman1 = pman2;  // (3, 1)
    pman1.Shot();
    pman1.Shot();
    pman1.Shot();
    pman1.Shot();
    cout<<endl;
    
    pman2.Shot();

    return 0;
}