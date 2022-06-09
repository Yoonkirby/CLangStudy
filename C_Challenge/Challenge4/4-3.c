// 복소수(Complex Number)를 나타내는 구조체를 정의
// 복소수의 덧셈과 곱셈을 위한 함수를 각각 정의
// 이를 기반으로 사용자로부터 두 개의 복소수 정보를 입력 받아서 두 복소수의 덧셈과 곱셈의 결과를 출력
// 복소수의 덧셈공식 : (a+bi) + (c+di) = (a+c) + (b+d)i
// 복소수의 곱셈공식 : (a+bi) * (c+di) = ac - bd + bci + adi
#include <stdio.h>

typedef struct Complex
{
    double actual;
    double imaginary;
}ComplexNum;

ComplexNum ComplexAdd(ComplexNum num1, ComplexNum num2)
{
    ComplexNum result;
    result.actual = num1.actual + num2.actual;
    result.imaginary =  num1.imaginary + num2.imaginary;
    return result;
}

ComplexNum ComplexMulti(ComplexNum num1, ComplexNum num2)
{
    ComplexNum result;
    result.actual = num1.actual * num2.actual - num1.imaginary * num2.imaginary;
    result.imaginary = num1.imaginary * num2.actual + num1.actual * num2.imaginary;
    return result;
}

int main(void)
{
    ComplexNum num1, num2, add, multi;

    printf("Enter Complex Number 1[Actual Imaginary] : ");
    scanf("%lf %lf", &num1.actual, &num1.imaginary);
    printf("Enter Complex Number 2[Actual Imaginary] : ");
    scanf("%lf %lf", &num2.actual, &num2.imaginary);

    add = ComplexAdd(num1, num2);
    printf("Add Result] Actual : %f, Imaginary : %f\n", add.actual, add.imaginary);
    multi = ComplexMulti(num1, num2);
    printf("Multiplication Result] Actual : %f, Imaginary : %f\n", multi.actual, multi.imaginary);
    return 0;
}