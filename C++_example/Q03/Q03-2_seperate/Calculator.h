#ifndef __Calculator_h__
#define __Calculator_h__

#include <iostream>
using namespace std;

class Calculator
{
    private:
    int cntAdd;
    int cntMin;
    int cntMul;
    int cntDiv;

    public:
        void Init();
        double Add(double num1, double num2);
        double Min(double num1, double num2);
        double Mul(double num1, double num2);
        double Div(double num1, double num2);
        void ShowOpCount();
};
#endif