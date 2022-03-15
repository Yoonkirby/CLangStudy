#include <stdio.h>

int main(void)
{
    int ent1 = 0, ent2 = 0, temp = 0;
    printf("Enter 1 : ");
    scanf("%d",&ent1);
    printf("Enter 2 : ");
    scanf("%d",&ent2);

    if(ent1 > ent2)
    {
        temp = ent2;
        ent2 = ent1;
        ent1 = temp;
    }

    for(int i = ent1; i <= ent2; i++)
    {
        for(int j = 1; j < 10; j++)
        {
            printf("%d X %d = %d\n", i, j, i*j);
        }
    }
    return 0;
}