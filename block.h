#ifndef BLOCK //BLOCK�� ���ǵ��� ���� ���
#define BLOCK //BLOCK�� ���� (��������� �ߺ��ؼ� ���ԵǴ°��� �����ϱ� ���� ifndef�� ���)
#include <Windows.h> //Windows API �Լ� ���
#include <stdio.h>	//standard input output (printf, scanf_s �� ���)
#include <stdlib.h>	 //standard library (system, srand �� ���)
#include <conio.h>	//C ���α׷��ֿ��� Windows �ܼ�(Console) ���ø����̼ǿ��� ����� �� �ִ� �Լ����� �����ϴ� ��� ����
#include <time.h>	 //time�Լ��� ����ϱ� ���� ���

void gameBlockSet();	 //gameBlockSet �Լ� ����
void changeac(int num);	 //changeac �Լ� ����
int blockRand();		 //blockRand �Լ� ����
void moveBlock(int speed);		 //moveBlock �Լ� ����
void setGameBlock();	 //setGameBlock �Լ� ����
void scanGameBlock();	//scanGameBlock �Լ� ����
int setColor(int arr[4][4]);	//setColor �Լ� ����

int currentBlock;		//Ȱ��ȭ �� ���� �´� ���� �ڵ带 �޾ƿ� ����
int playBlock[4][4];	//playBlock�̸��� [4][4]ũ�� �迭 ���� (Ȱ��ȭ �Ǿ� �÷��� �ϰ� �ִ� ��)
int blockset[7];		//������� � ���� ���Ǿ����� ����
int blocksetprint[5][4][4];		//�̸� ���� �� 5���� ���� �����ϴ� �迭 (4x4ũ��)
int gameblock[25][12];		//����ȭ�鿡 ����� ������ 1, ������ 0�� ��� �迭
extern int score;		//������ ���� ���� ����

#endif	//���Ǻ� ������ ���� ���� ��Ÿ���� ���þ�