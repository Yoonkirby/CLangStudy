// 길이가 10인 배열을 선언 후 총 10개의 정수를 입력받음
// 입력 받은 숫자가 홀수이면 배열의 앞에서부터 채워나가고, 짝수이면 뒤에서부터 채워나가는 형식
#include <stdio.h>

int main(void)
{
    int enter[10];
    int front = 0, back = 9, temp = 0;
    for(int i = 0; i < 10; i++)
    {
        printf("Enter %d : ", i+1);
        scanf("%d", &temp);
        if(temp % 2 == 1)
            enter[front++] = temp;
        else
            enter[back--] = temp;
    }
    for(int i = 0; i < 10; i++)
        printf("%d ", enter[i]);

    return 0;
}