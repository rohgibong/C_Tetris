#pragma warning(disable:4996)	//getch & kbhit ���� ����
#include "block.h"	 //block ������� �ҷ�����
#include "screen.h"	 //screen ������� �ҷ�����
#include "data.h"	 //data ������� �ҷ�����
						
int main() {
	int speed;				//���̵��� �ӵ��� ���ϱ� ���� ���� speed ����
	int num = 0;			//���̵��� ���ùޱ� ���� ���� num ����
	extern int score;		//�ܺο��� ������ �޾ƿ��� ���� extern���� score ���� ����
	while (1) {				//���̵��� ���ù������� �ݺ�
		clock_t starttime = 0;	//���α׷� ���� �ð� ������� starttime ����
		clock_t endtime = 0;	//���α׷� ���� �ð� ������� endtime ����
		int speednum = 0;		//���ǵ尡 �ö��� Ȯ���ϱ� ���� ���� speednum ����
		num = startPage();		//startPage���� ���̵��� ���ù���
		if (num == 1) {			//num(���̵�)�� 1�� ��
			speed = 30;			//speed�� 30�� ��
		}
		else if (num == 2) {	//num(���̵�)�� 2�� ��
			speed = 20;			//speed�� 20�� ��
		}
		else if (num == 3) {	//num(���̵�)�� 3�� ��
			speed = 10;			//speed�� 10�� ��
		}
		else if (num == 4) {	//��ŷ ���⸦ �������� ��
			showRank();			//��ũ�� ������
			continue;			//��� �ݺ�
		}
		else if (num == 5) {	//���� ���Ḧ �������� ��
			return 0;			//0 ����
		}
		else {					//�� �ܿ���
			continue;			//��� �ݺ�
		}
		screenLine();	//ȭ�� ��ü ������ ����ϴ� �Լ� ȣ��
		boardLine();	//���Ӻ��� ������ ����ϴ� �Լ� ȣ��
		gameBlockSet();	//��輱�� �����ϴ� �Լ� ȣ��
		blockSetWall();	//���� ���� ������ �����ִ� �� UI�� ����ϴ� �Լ� ȣ��
		guideWall();	//����Ű UI ������ ����ϴ� �Լ� ȣ��
		printGuideMent();	//����Ű UI ������ ����ϴ� �Լ� ȣ��

		changeac(blockRand());		//ù Ȱ��ȭ �� �� ����		(���ʿ� ���� �Ҽ��� ��� �� 5��°���� 4��° 3��° .. ���� ������ �������
		changeac(blockRand());		//ó�� ��� �� 5�� ����		 �� 6���� ����� ù Ȱ��ȭ �� ���� ��� �� 5���� ����� �� �� ����)
		changeac(blockRand());		//ó�� ��� �� 5�� ���� 
		changeac(blockRand());		//ó�� ��� �� 5�� ���� 
		changeac(blockRand());		//ó�� ��� �� 5�� ���� 
		changeac(blockRand());		//ó�� ��� �� 5�� ����
		gotoxy(10, 7);				//10, 7 ������
		printf("SCORE : %d", score);	//score�� ���

		starttime = clock();	//������ �������� �� �ð��� ����
		while (1) {		//������ ����Ǵ� ���� �������� �ݺ�. ���� ���� ���� ���� �� ������ ��
			currentBlock = setColor(playBlock);	//playBlock(Ȱ��ȭ �� ��)�� setColor�Լ��� �ְԵǸ� �� ��翡 �´� ���� �ڵ�(����)�� �����ϰԵ�. �� ���� currentBlock�� ����
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), currentBlock);		//������ ���� ���� �ڵ带 ���� �� ����
			moveBlock(speed);			//1�ʰ������� ���� �ϰ��ϴ� �Լ� ȣ��
			setGameBlock();			//���� �������� �ִ� ��Ʈ���� ����� ���� ȭ�鿡 �߰��ϴ� �Լ� ȣ��
			scanGameBlock();		//���� �ϼ��Ǿ����� Ȯ���ϱ� ���� �Լ� ȣ��
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	//������ �ٽ� ������� �ǵ���
			gotoxy(10, 7);				//10, 7 ������
			printf("SCORE : %d", score);	//score�� ��� (������Ʈ)

			endtime = clock();		//������ ����� �ð��� endtime�� ����
			if (endtime - starttime >= 60000 && speednum == 0) {	//���� ���� �ð� 1���� ����ư�, �ӵ��� �ѹ��� ������ �ʾ��� ��
				if (num == 1) {		//���̵��� easy�̸�,
					speed -= 5;		//�ӵ��� 10ms * 5 ��ŭ �� ������ ����
				}
				else if (num == 2) {		//���̵��� normal�̸�,
					speed -= 5;		//�ӵ��� 10ms * 5 ��ŭ �� ������ ����
				}
				else if (num == 3) {		//���̵��� hard�̸�,
					speed -= 2;		//�ӵ��� 10ms * 2 ��ŭ �� ������ ����
				}
				speednum++;		//�ӵ��� �����ߴٴ� ǥ��
				gotoxy(25, 7);	//25, 7 ������
				printf("Speed UP!");	//Speed Up! ���� ���
			}
			else if (endtime - starttime >= 120000 && speednum == 1) {	//���� ���� �ð� 2���� ����ư�, �ӵ��� �ѹ� �ö��� ��
				if (num == 1) {		//���̵��� easy�̸�,
					speed -= 5;		//�ӵ��� 10ms * 5 ��ŭ �� ������ ����
				}
				else if (num == 2) {		//���̵��� normal�̸�,
					speed -= 5;		//�ӵ��� 10ms * 5 ��ŭ �� ������ ����
				}
				else if (num == 3) {		//���̵��� hard�̸�,
					speed -= 2;		//�ӵ��� 10ms * 2 ��ŭ �� ������ ����
				}
				speednum++;		//�ӵ��� �����ߴٴ� ǥ��
				gotoxy(25, 7);	//25, 7 ������
				printf("Speed UP!!");	//Speed Up!! ���� ���
			}
			else if (endtime - starttime >= 180000 && speednum == 2) {	//���� ���� �ð� 3���� ����ư�, �ӵ��� �ι� �ö��� ��
				if (num == 1) {		//���̵��� easy�̸�,
					speed -= 3;		//�ӵ��� 10ms * 3 ��ŭ �� ������ ����
				}
				else if (num == 2) {		//���̵��� normal�̸�,
					speed -= 3;		//�ӵ��� 10ms * 3 ��ŭ �� ������ ����
				}
				else if (num == 3) {		//���̵��� hard�̸�,
					speed -= 2;		//�ӵ��� 10ms * 2 ��ŭ �� ������ ����
				}
				speednum++;		//�ӵ��� �����ߴٴ� ǥ��
				gotoxy(25, 7);	//25, 7 ������
				printf("Speed UP!!!");	//Speed Up!!! ���� ���
			}
			if (scanGameOver() == 1) {	//���ӿ����ƴ��� Ȯ���ϱ� ���� �Լ� ȣ��
				break;		//���ӿ����� ������ while���� ��������
			}

			changeac(blockRand());	//������� �� ��ĭ�� ������ ���� �Լ� ȣ��
		}
		gameOverPage();		//���ӿ��� ȭ���� ���� �Լ�
	}

	return 0;	//main�Լ� ���ϰ��� 0�� �����ν�, ���α׷��� ���������� ����Ǿ����� �ǹ�
}

