#include <stdio.h>
#include <time.h>

//5마리의 고양이가 있다
//아무 키나 눌러서 랜덤으로 고양이를 뽑되,
//5마리 모두 다 수집을 해서 열심히 키우면 되는 게임!
//중 복 발 생 가 능 !

//고양이
//이름, 나이, 성격, 키우기 난이도(레벨)

typedef struct{
    char * name; //이름
    int age; //나이
    char * character; //성격
    int level; //키우기 난이도 (1~5, 5가 어려움)
} CAT;

//현재까지 보유한 고양이
int collection[5] = { 0, 0, 0, 0, 0};

//전체 고양이 리스트
CAT cats[5];

void initCats();

int main(void)
{
    srand(time(NULL));

    initCats();
    while(1)
    {
        printf("도키도키! 어느 고양이의 집사가 될까요?\n");
        
    }

    return 0;
}

void initCats()
{
    cats[0].name = "깜냥이";
    cats[0].age = 5;
    cats[0].character = "온순";
    cats[0].level = 1;

    cats[1].name = "귀요미";
    cats[1].age = 3;
    cats[1].character = "도도함";
    cats[1].level = 4;

    cats[2].name = "수줍이";
    cats[2].age = 8;
    cats[2].character = "늘 잠만 잠";
    cats[2].level = 3;

    cats[3].name = "까꿍이";
    cats[3].age = 1;
    cats[3].character = "똥꼬발랄함";
    cats[3].level = 5;

    cats[4].name = "돼냥이";
    cats[4].age = 7;
    cats[4].character = "배고픔";
    cats[4].level = 2;
}