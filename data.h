#ifndef DATA	//DATA�� ���ǵ��� ���� ���
#define DATA	//DATA�� ���� (��������� �ߺ��ؼ� ���ԵǴ°��� �����ϱ� ���� ifndef�� ���)
#include <stdio.h>	//standard input output (printf, scanf_s �� ���)
#include <stdlib.h>	 //standard library (system, srand �� ���)
#include <Windows.h> //Windows API �Լ� ���
#include <mysql.h>

int checkRank(int score);
void insertRank(char id[], int score);
void showRank();

#endif	//���Ǻ� ������ ���� ���� ��Ÿ���� ���þ�
