#include <stdio.h>

int main(void)
{
    int n, k = 0, max = 2;
    printf("Enter : ");
    scanf_s("%d",&n);
    while(1)
    {
        if(max > n)
            break;
        max *= 2;
        k++;
    }
    printf("K's Maximum is %d",k);
    return 0;
}