#include <iostream>
#include <cstring>
using namespace std;

class printer
{
    private:
        char str[30];
    public:
        void SetString(const char * st)
        {
            strcpy(str,st);
        }
        void ShowString()
        {
            cout<<str<<endl;
        }
};

int main(void) {
    printer pnt;
    pnt.SetString("Hello world!");
    pnt.ShowString();
    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}