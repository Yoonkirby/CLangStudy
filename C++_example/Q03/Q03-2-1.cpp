#include <iostream>
using namespace std;

class Calculator{
    private:
        int cntAdd;
        int cntMin;
        int cntMul;
        int cntDiv;
    public:
        void Init();
        double Add(double num1,double num2);
        double Min(double num1,double num2);
        double Mul(double num1,double num2);
        double Div(double num1,double num2);
        void ShowOpCount();
};

void Calculator::Init(){
    cntAdd = 0;
    cntMin = 0;
    cntMul = 0;
    cntDiv = 0;
}
double Calculator::Add(double num1, double num2){
    cntAdd++;
    return num1 + num2;
}
double Calculator::Min(double num1, double num2){
    cntMin++;
    return num1 - num2;
}
double Calculator::Mul(double num1, double num2){
    cntMul++;
    return num1 * num2;
}
double Calculator::Div(double num1, double num2){
    cntDiv++;
    return num1 / num2;
}
void Calculator::ShowOpCount(){
    cout<<"덧셈 : "<<cntAdd<<" 뺄셈 : "<<cntMin<<" 곱셈 : "<<cntMul<<" 나눗셈 : "<<cntDiv<<endl;
}

int main(void) {
    Calculator cal;
    cal.Init();
    cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
    cout<<"3.5 * 1.7 = "<<cal.Mul(3.5, 1.7)<<endl;
    cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
    cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
    cal.ShowOpCount();
    return 0;
}