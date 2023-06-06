#ifndef SCREEN	//SCREEN이 정의되지 않은 경우
#define SCREEN	//SCREEN을 정의 (헤더파일이 중복해서 포함되는것을 방지하기 위해 ifndef을 사용)
#include <stdio.h>	//standard input output (printf, scanf_s 등 사용)
#include <Windows.h> //Windows API 함수 사용
#include <stdio.h>	//standard input output (printf, scanf_s 등 사용)

enum screenProperty {	//screen.c에서 사용 할 상수(화면의 크기)값을 정의
	SCREEN_X_SIZE = 50,	//SCREEN_X_SIZE(화면 전체 x열)를 50으로 정의
	SCREEN_Y_SIZE = 40,	//SCREEN_Y_SIZE(화면 전체 y행)를 40으로 정의
	BOARD_X_SIZE = 12,	//BOARD_X_SIZE(게임보드 전체 x열)를 12로 정의
	BOARD_Y_SIZE = 21	//BOARD_Y_SIZE(게임보드 전체 y행)를 21로 정의
};

void gotoxy(int x, int y);	//gotoxy 함수 선언
int startPage();		//startPage 함수 선언
void screenLine();	//screenLine 함수 선언
void boardLine();	//boardLine 함수 선언
void blockSetWall();	//blockSetWall 함수 선언
void guideWall();	//guideWall 함수 선언
void printGuideMent();	//printGuideMent 함수 선언
int scanGameOver();	 //scanGameOver 함수 선언
void gameOverPage();	//gameOverPage 함수 선언
extern int score;		//점수를 받을 변수 선언

extern int gameblock[25][12];		//게임화면에 블록이 있으면 1, 없으면 0을 담는 배열

#endif	//조건부 컴파일 블럭의 끝을 나타내는 지시어
