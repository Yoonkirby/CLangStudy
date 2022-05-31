// 회문(Palindrome)은 앞으로 읽으나 뒤로 읽으나 차이가 없는 단어들을 뜻한다
// ex)level, bob
// 인자로 전달되는 영단어가 회문인지 아닌지를 판단해서 그 결과를 출력하는 기능의 함수를 정의, 적절한 main함수도 정의
// 구현의 편의를 위해서 대소문자까지 일치해야 회문으로 인정(이는 어디까지나 구현의 편의를 고려한 제약사항)
#include <stdio.h>
#include <string.h>

void palindrome(char word[])
{
    int len = strlen(word);
    for(int i = 0; i < len / 2; i++)
    {
        len--;
        if(word[i] != word[len])
        {
            printf("It isn't a Palindorme\n");
            exit(0);
        }
    }
    printf("It is a Palindrome\n");
}

int main(void)
{
    char enter[45];

    printf("Enter Word : ");
    scanf_s("%s",enter);
    palindrome(enter);

    return 0;
}