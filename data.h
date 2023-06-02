#ifndef DATA	//DATA가 정의되지 않은 경우
#define DATA	//DATA를 정의 (헤더파일이 중복해서 포함되는것을 방지하기 위해 ifndef을 사용)
#include <stdio.h>	//standard input output (printf, scanf_s 등 사용)
#include <stdlib.h>	 //standard library (system, srand 등 사용)
#include <Windows.h> //Windows API 함수 사용
#include <mysql.h>

int checkRank(int score);
void insertRank(char id[], int score);
void showRank();

#endif	//조건부 컴파일 블럭의 끝을 나타내는 지시어
