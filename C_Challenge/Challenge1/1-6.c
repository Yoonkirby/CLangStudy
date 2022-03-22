// 초(second)를 입력 받은 후, 이를 [시, 분, 초]의 형태로 출력하는 프로그램 작성
#include <stdio.h>

int main(void)
{
    int enter, sec, min, hour;
    printf("Enter the second : ");
    scanf_s("%d",&enter);
    hour = enter / 3600;
    enter -= 3600*hour;
    min = enter / 60;
    sec = enter % 60;
    printf("[h : %d, m: %d, s : %d]\n",hour, min, sec);
    return 0;
}