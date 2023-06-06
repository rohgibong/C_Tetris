#ifndef SCREEN	//SCREEN�� ���ǵ��� ���� ���
#define SCREEN	//SCREEN�� ���� (��������� �ߺ��ؼ� ���ԵǴ°��� �����ϱ� ���� ifndef�� ���)
#include <stdio.h>	//standard input output (printf, scanf_s �� ���)
#include <Windows.h> //Windows API �Լ� ���
#include <stdio.h>	//standard input output (printf, scanf_s �� ���)

enum screenProperty {	//screen.c���� ��� �� ���(ȭ���� ũ��)���� ����
	SCREEN_X_SIZE = 50,	//SCREEN_X_SIZE(ȭ�� ��ü x��)�� 50���� ����
	SCREEN_Y_SIZE = 40,	//SCREEN_Y_SIZE(ȭ�� ��ü y��)�� 40���� ����
	BOARD_X_SIZE = 12,	//BOARD_X_SIZE(���Ӻ��� ��ü x��)�� 12�� ����
	BOARD_Y_SIZE = 21	//BOARD_Y_SIZE(���Ӻ��� ��ü y��)�� 21�� ����
};

void gotoxy(int x, int y);	//gotoxy �Լ� ����
int startPage();		//startPage �Լ� ����
void screenLine();	//screenLine �Լ� ����
void boardLine();	//boardLine �Լ� ����
void blockSetWall();	//blockSetWall �Լ� ����
void guideWall();	//guideWall �Լ� ����
void printGuideMent();	//printGuideMent �Լ� ����
int scanGameOver();	 //scanGameOver �Լ� ����
void gameOverPage();	//gameOverPage �Լ� ����
extern int score;		//������ ���� ���� ����

extern int gameblock[25][12];		//����ȭ�鿡 ����� ������ 1, ������ 0�� ��� �迭

#endif	//���Ǻ� ������ ���� ���� ��Ÿ���� ���þ�
