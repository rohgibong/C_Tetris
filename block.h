#ifndef BLOCK //BLOCK이 정의되지 않은 경우
#define BLOCK //BLOCK을 정의 (헤더파일이 중복해서 포함되는것을 방지하기 위해 ifndef을 사용)
#include <Windows.h> //Windows API 함수 사용
#include <stdio.h>	//standard input output (printf, scanf_s 등 사용)
#include <stdlib.h>	 //standard library (system, srand 등 사용)
#include <conio.h>	//C 프로그래밍에서 Windows 콘솔(Console) 애플리케이션에서 사용할 수 있는 함수들을 제공하는 헤더 파일
#include <time.h>	 //time함수를 사용하기 위해 사용

void gameBlockSet();	 //gameBlockSet 함수 선언
void changeac(int num);	 //changeac 함수 선언
int blockRand();		 //blockRand 함수 선언
void moveBlock(int speed);		 //moveBlock 함수 선언
void setGameBlock();	 //setGameBlock 함수 선언
void scanGameBlock();	//scanGameBlock 함수 선언
int setColor(int arr[4][4]);	//setColor 함수 선언

int currentBlock;		//활성화 된 블럭에 맞는 색깔 코드를 받아올 변수
int playBlock[4][4];	//playBlock이름의 [4][4]크기 배열 생성 (활성화 되어 플레이 하고 있는 블럭)
int blockset[7];		//현재까지 어떤 블럭이 사용되었는지 저장
int blocksetprint[5][4][4];		//미리 보여 줄 5개의 블럭을 저장하는 배열 (4x4크기)
int gameblock[25][12];		//게임화면에 블록이 있으면 1, 없으면 0을 담는 배열
extern int score;		//점수를 받을 변수 선언

#endif	//조건부 컴파일 블럭의 끝을 나타내는 지시어