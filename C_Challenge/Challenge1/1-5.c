#include <stdio.h>

int main(void)
{
    int num = 2;
    int PN[10];
    int i = 0;
    int j = 2;
        
    while(i < 10)
    {
        while(j < num)
        {
            if(num % j != 0)
            {
                j++;
            }
            
        }
        PN[i] = num;
        num++;
        i++;
    }

    for(i = 0; i < 10; i++)
    {
        printf("%3d",PN[i]);
    }
    printf("\n");
    return 0;
}