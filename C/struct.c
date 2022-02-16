#include <stdio.h>

struct Gameinfo
{
   char * name;
   int year;
   int price;
   char * company;

   struct Gameinfo * friendGame; //연관업체게임
};

int main()
{
   //[게임 출시]
   //이름 : 커비게임
   //발매년도 : 2022년
   //가격 : 100원
   //제작사 : 커비회사

   /*char * name = "커비게임";
   int year = 2022;
   int price = 100;
   char * company = "커비회사";

   //[또다른 게임 출시]
   //이름 : 쿠파게임
   //발매년도 : 2022년
   //가격 : 50원
   //제작사 : 쿠파회사

   char * name = "쿠파게임";
   int year = 2022;
   int price = 50;
   char * company = "쿠파회사";*/
   
   //구조체 사용
   struct Gameinfo gameinfo1;
   gameinfo1.name = "커비게임";
   gameinfo1.year = 2022;
   gameinfo1.price = 100;
   gameinfo1.company = "커비회사";

   //구조체 출력
   printf("~~ 게임 출시 정보 ~~\n");
   printf("게임명    : %s\n", gameinfo1.name);
   printf("출시년도  : %d\n", gameinfo1.year);
   printf("가격      : %d\n", gameinfo1.price);
   printf("제작사    : %s\n", gameinfo1.company);

   //구조체를 배열처럼 초기화
   struct Gameinfo gameinfo2 = {"디디디게임", 2022, 50, "디디디회사"};
   printf("~~ 또 다른 게임 출시 정보 ~~\n");
   printf("게임명    : %s\n", gameinfo2.name);
   printf("출시년도  : %d\n", gameinfo2.year);
   printf("가격      : %d\n", gameinfo2.price);
   printf("제작사    : %s\n", gameinfo2.company);

   //구조체 배열
   struct Gameinfo gameArray[2] = {
      {"커비게임", 2022, 100, "커비회사"},
      {"디디디게임", 2022, 50, "디디디회사"}
   };
   printf("\n~~ 게임 출시 정보 ~~\n");
   printf("게임명    : %s\n", gameArray[0].name);
   printf("출시년도  : %d\n", gameArray[0].year);
   printf("가격      : %d\n", gameArray[0].price);
   printf("제작사    : %s\n", gameArray[0].company);
   printf("\n~~ 또 다른 게임 출시 정보 ~~\n");
   printf("게임명    : %s\n", gameArray[1].name);
   printf("출시년도  : %d\n", gameArray[1].year);
   printf("가격      : %d\n", gameArray[1].price);
   printf("제작사    : %s\n", gameArray[1].company);

   //구조체 포인터
   struct Gameinfo * gamePtr; //미션맨
   gamePtr = &gameinfo1;
   printf("\n\n~~ 미션맨의 게임 출시 정보 ~~\n");
   printf("게임명    : %s\n", (*gamePtr).name);
   printf("출시년도  : %d\n", (*gamePtr).year);
   printf("가격      : %d\n", (*gamePtr).price);
   printf("제작사    : %s\n", (*gamePtr).company);
   printf("\n\n~~ 미션맨의 게임 출시 정보 ~~\n");
   printf("게임명    : %s\n", gamePtr->name);
   printf("출시년도  : %d\n", gamePtr->year);
   printf("가격      : %d\n", gamePtr->price);
   printf("제작사    : %s\n", gamePtr->company);

   //연관 업체 게임 소개
   gameinfo1.friendGame = &gameinfo2;
   printf("\n\n~~ 연관 업체의 게임 출시 정보 ~~\n");
   printf("게임명    : %s\n", gameinfo1.friendGame->name);
   printf("출시년도  : %d\n", gameinfo1.friendGame->year);
   printf("가격      : %d\n", gameinfo1.friendGame->price);
   printf("제작사    : %s\n", gameinfo1.friendGame->company);


   return 0;
}