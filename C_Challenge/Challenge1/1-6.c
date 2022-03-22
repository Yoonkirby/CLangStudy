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