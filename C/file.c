#incldue <stdio.h>

#define MAX 10000

int main(void)
{
    //파일 입출력
    //파일에 어떤 데이터를 저장.
    //파일에 저장된 데이터를 불러오기

    //fputs, fgets 쌍
    char line[MAX]; //char line[10000]
    FILE *file = fopen("c:\test1.txt","wb");

    return 0;
}