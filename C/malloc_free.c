#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //동적 메모리로 알파벳 출력
    /*char *pc = NULL;
    int i = 0;
    pc = (char *)malloc(100*sizeof(char));
    if(pc==NULL)
    {
        printf("동적 메모리 할당에 실패했습니다.\n");
        exit(1);
    }
    //pc가 가르키는 포인터를 1씩 증가시키며 알파벳 소문자를 삽입합니다.
    for(i=0; i<26; i++)
    {
        *(pc+i) = 'a' + i;
        
    }
    //아스키 코드에서 0은 NULL을 의미합니다.
    *(pc+i) = 0;
    printf("%s\n", pc);
    free(pc);*/

    //동적 메모리로 정수 5개를 처리
    int *pi, i;
    pi = (int *) malloc(5 * sizeof(int));
    if(pi == NULL)
    {
        printf("동적 메모리 할당 실패\n");
        exit(1);
    }
    pi[0] = 100;
    pi[1] = 200;
    pi[2] = 300;
    pi[3] = 400;
    pi[4] = 500;
    for(i=0; i<5; i++)
    {
        printf("%d\n",*(pi+i));
    }
    free(pi);
    
    return 0;
}