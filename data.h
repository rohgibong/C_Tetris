#ifndef DATA	//DATA�� ���ǵ��� ���� ���
#define DATA	//DATA�� ���� (��������� �ߺ��ؼ� ���ԵǴ°��� �����ϱ� ���� ifndef�� ���)
#include <stdio.h>	//standard input output (printf, scanf_s �� ���)
#include <stdlib.h>	 //standard library (system, srand �� ���)
#include <Windows.h> //Windows API �Լ� ���
#include <mysql.h>

int checkRank(int score);					//��ŷ�� Ȯ���ϴ� �Լ� checkRank ����
void insertRank(char id[], int score);		//��ŷ ����ϴ� �Լ� insertRank ����
void showRank();							//10�������� ��ŷ�� �����ִ� showRank ����

#endif	//���Ǻ� ������ ���� ���� ��Ÿ���� ���þ�
