#include <stdio.h>

int main(void)
{
    int PN[10];
    int num = 2;
    int i = 0;
    int j = 2;

    while(i < 10)
    {
        for(j = 2; j < num; j++)
        {
            if(num % j == 0)
            {
                break;
            }
        }
        if(num == j)
        {
            PN[i] = num;
            i++;
            num++;
        }
        num++;
    }

    for(i = 0; i < 10; i++)
    {
        printf("%3d",PN[i]);
    }
    printf("\n");
    return 0;
}