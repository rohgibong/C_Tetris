#pragma warning(disable:4996)	//getch & kbhit ���� ����
#include "block.h"	 //block ������� �ҷ�����
#include "screen.h"	 //screen ������� �ҷ�����
						
int main() {
	int speed;
	int num = 0;
	while (1) {
		num = startPage();
		if (num == 1) {
			speed = 30;
		}
		else if (num == 2) {
			speed = 20;
		}
		else if (num == 3) {
			speed = 10;
		}
		else {
			continue;
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

		while (1) {		//������ ����Ǵ� ���� �������� �ݺ�. ���� ���� ���� ���� �� ������ ��
			currentBlock = setColor(playBlock);	//playBlock(Ȱ��ȭ �� ��)�� setColor�Լ��� �ְԵǸ� �� ��翡 �´� ���� �ڵ�(����)�� �����ϰԵ�. �� ���� currentBlock�� ����
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), currentBlock);		//������ ���� ���� �ڵ带 ���� �� ����
			moveBlock(speed);			//1�ʰ������� ���� �ϰ��ϴ� �Լ� ȣ��
			setGameBlock();			//���� �������� �ִ� ��Ʈ���� ����� ���� ȭ�鿡 �߰��ϴ� �Լ� ȣ��
			scanGameBlock();		//���� �ϼ��Ǿ����� Ȯ���ϱ� ���� �Լ� ȣ��
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	//������ �ٽ� ������� �ǵ���

			if (scanGameOver() == 1) {	//���ӿ����ƴ��� Ȯ���ϱ� ���� �Լ� ȣ��
				break;		//���ӿ����� ������ while���� ��������
			}

			changeac(blockRand());	//������� �� ��ĭ�� ������ ���� �Լ� ȣ��
		}
		gameOverPage();		//���ӿ��� ȭ���� ���� �Լ�
	}

	return 0;	//main�Լ� ���ϰ��� 0�� �����ν�, ���α׷��� ���������� ����Ǿ����� �ǹ�
}

