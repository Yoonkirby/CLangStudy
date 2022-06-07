/*
 * 파일이름 : BangkingCommonDecl.h
 * 작성자 : 윤성준
 * 업데이트 정보 : [2022, 06, 07] 파일버전 0.7
 */

#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

// 프로그램 사용자의 선택 메뉴
enum {Make = 1, Deposit, Withdrawal, ShowAll, Exit};

//신용등급
enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};

//계좌의 종류
enum {NORMAL = 1, CREDIT = 2};

#endif