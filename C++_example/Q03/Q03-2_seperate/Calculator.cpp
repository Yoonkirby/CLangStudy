#include "Calculator.h"

void Calculator::Init()
{
    Calculator.cntAdd = 0;
    Calculator.cntMin = 0;
    Calculator.cntMul = 0;
    Calculator.cntDiv = 0;
}

double Calculator::Add(double num1, double num2)
{
    double resurt = num1 + num2;
    return resurt;
}

double Calculator::Min(double num1, double num2)
{
    double resurt = num1 - num2;
    return resurt;
}

double Calculator::Mul(double num1, double num2)
{
    double resurt = num1 * num2;
    return resurt;
}

double Calculator::Div(double num1, double num2)
{
    double resurt = num1 / num2;
    return resurt;
}

void Calculator::ShowOpCount()
{
    cout<<"덧셈 : "<<cntAdd<<" 뺄셈 : "<<cntMin<<" 곱셈 : "<<cntMul<<" 나눗셈 : "<<cntDiv<<endl;    
}