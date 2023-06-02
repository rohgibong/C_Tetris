#include "block.h"	//block.h ��� ������ ���α׷��� ���Խ�Ű�� ���� �ڵ�

int XSize = 18;			//x���� �����ϴ� ���� XSize�� 18���� ����
int YSize = 7;			//y���� �����ϴ� ���� YSize�� 7���� ����
int exx = 0;		//�̸������� ���� x��ǥ
int exy = 0;		//�̸������� y��ǥ
int exPlayBlock[4][4];
int currentNum = 0;		//������� ��µ� ���� ���� ǥ��
int excurrent;
int score;

int yset() {	//y��ǥ ���
	if (YSize >= 7) {	//y��ǥ�� ����� ��
		return YSize - 7;	//����� �������� ��ġ�� YSize���� 7�� �� ������ ����
	}
	else {			//y��ǥ�� ������ �� 
		return 0;	//0���� ����
	}
}

int block[7][4][4] = { // block�̸��� [7][4][4]ũ�� �迭 ���� ([���][���� ǥ��][����ǥ��])
	{				//�׸� ���
		{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}
	},
	{				//���� ���
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0},
		{0,0,0,0}
	},
	{				//S ���
		{0,0,0,0},
		{0,0,1,1},
		{0,1,1,0},
		{0,0,0,0},
	},
	{				//Z ���
		{0,0,0,0},
		{0,1,1,0},
		{0,0,1,1},
		{0,0,0,0}
	},
	{				//L ���
		{0,0,0,0},
		{0,1,1,1},
		{0,1,0,0},
		{0,0,0,0}
	},
	{				//J ���
		{0,0,0,0},
		{0,1,1,1},
		{0,0,0,1},
		{0,0,0,0}
	},
	{				//T ���
		{0,0,0,0},
		{0,1,1,1},
		{0,0,1,0},
		{0,0,0,0}
	}
};

int blockRand() {		//���� ������ ��ø���� �ʰ� ��������
	int i;			//i���� ����
	
	while (1) {				//�ߺ��� �ƴ� ���� ���� �� ���� �ݺ�
		if (currentNum != 0) {	//ù��° ���̾ƴ� ���
 			blockset[currentNum] = rand() % 7;	//0���� 6������ ������ ���� blockset�� ����
			for (i = 0; i < currentNum; i++) {	//�̹� ��Ʈ���� �ߺ��� �ִ��� Ȯ��
				if (blockset[i] == blockset[currentNum]) {	//���� �ߺ��Ǵ� ���� ������
					break;									//for���� ��������
				}
			}
			if (i == currentNum) {		//i�� currentNum�̶� ������ (�ߺ��� ������)
				break;					//while���� ��������
			}
		}
		else {	//ù��° ���� ���
			blockset[currentNum] = rand() % 7;	//0���� 6������ ������ ���� blockset�� ����
			break;								//while���� ��������
		}
	}

	i = blockset[currentNum];		//blockset[currentNum]���� i�� ����
	currentNum++;					//currentNum�� 1 ����
	if (currentNum == 7) {	//currentNum�� ���� 7�̸�
		currentNum = 0;		//0���� �ʱ�ȭ
	}

	return i;			//i�� ����
}

void printBlock(int arr[4][4]) {	//printBlock �Լ� (playBlock�� ���� ����� ����ϱ� ���� �Լ�)
	for (int i = 0; i < 4; i++) {	//y�� 4ĭ��ŭ �ݺ�
		gotoxy(XSize, YSize + 1);	//Ŀ�� ��ġ�� (XSize, YSize)�� �̵�
		for (int j = 0; j < 4; j++) {	//x�� 4ĭ��ŭ �ݺ�
			if (arr[i][j] == 1) {	//arr[i][j]�� 1�̸� (1�� �κ��� ���� �κ�)
				printf("��");		//�Ḧ ���
			}
			else if (arr[i][j] == 0) {	//arr[i][j]�� 0�̸� (0�� �κ��� ���� �ƴ� �κ�)
				gotoxy(XSize + 2 * (j + 1), YSize + i);	//gotoxy�� �̿��� Ŀ���� ���� ��µ� �κ����� �پ���� (������ �ִ� ���� ��������� ���� ����)
			}
		}
	}
}

void removePrint(int arr[4][4]) {	//removePrint �Լ� (�ܻ��� �����ϱ� ���� �Լ�)
	for (int i = 0; i < 4; i++) {	//y�� 4ĭ��ŭ �ݺ�
		gotoxy(XSize, YSize + 1);	//Ŀ�� ��ġ�� (XSize, YSize)�� �̵�
		for (int j = 0; j < 4; j++) {	//x�� 4ĭ��ŭ �ݺ�
			if (arr[i][j] == 1) {	//arr[i][j]�� 1�̸� (1�� �κ��� ���� �κ�)
				printf("  ");		//������ ��� (���� �κ��� ����)
			}
			else if (arr[i][j] == 0) {	//arr[i][j]�� 0�̸�
				gotoxy(XSize + 2 * (j + 1), YSize + i);	//gotoxy�� �̿��� ��(1�� �κ�)�� �ƴ� �κ��� �ǳʶ�.
			}
		}
	}
}

void removeGuide(int arr[4][4], int a, int b) {
	if (excurrent != currentNum) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		gotoxy(a, b + i);
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 1) {
				printf("  ");
			}
			else if (arr[i][j] == 0) {
				gotoxy(a + 2 * (j + 1), b + i);
			}
		}
	}
}

void printGuide(int arr[4][4], int a) {
	for (int i = 0; i < 4; i++) {
		gotoxy(XSize, a + i);
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 1) {
				printf("��");
			}
			else if (arr[i][j] == 0) {
				gotoxy(XSize + 2 * (j + 1), a + i);
			}
		}
	}
}

int guideCheckDown() {
	for (int i = 3; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (playBlock[i][j] != 0 && gameblock[exy - 7 + 1 + i][(XSize - 10) / 2 + j] != 0) {
				return 1;
			}
		}
	}
	return 0;
}

void guide() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	removeGuide(exPlayBlock, exx, exy);

	exy = YSize;

	while (guideCheckDown() == 0) {
		exy++;
	}

	exx = XSize;
	printGuide(playBlock, exy);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			exPlayBlock[i][j] = playBlock[i][j];
		}
	}
	excurrent = currentNum;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), currentBlock);
}

int blockCheckMoveLeft() {		//�������� �̵��� ���� üũ
	for (int i = 0; i < 4; i++) {	//i 4����ŭ �ݺ�
		for (int j = 0; j < 4; j++) {	//j 4����ŭ �ݺ�
			if (playBlock[j][i] != 0 && gameblock[yset() + j][(XSize - 10) / 2 - 1 + i] != 0) {		//���� �̵� ���� ���� ���� �ǿ����� ���� ���� ��ġ�� �����ϴ����� Ȯ��
				return 1;			//�����ϸ� 1 ����
			}
		}
	}
}

int blockCheckMoveRight() {		//���������� �̵��� ���� üũ
	for (int i = 3; i >= 0; i--) {	//i 4����ŭ �ݺ�
		for (int j = 0; j < 4; j++) {	//j 4����ŭ �ݺ�
			if (playBlock[j][i] != 0 && gameblock[yset() + j][(XSize - 10) / 2 + 1 + i] != 0) {		//���� �̵� ���� ���� ���� �ǿ����� ���� ���� ��ġ�� �����ϴ����� Ȯ��
				return 1;			//�����ϸ� 1 ����
			}
		}
	}
}

int blockCheckDown() {		//�Ʒ��� �̵��� ���� üũ
	for (int i = 3; i >= 0; i--) {	//i 4����ŭ �ݺ�
		for (int j = 0; j < 4; j++) {	//j 4����ŭ �ݺ�
			if (playBlock[i][j] != 0 && gameblock[yset() + 1 + i][(XSize - 10) / 2 + j] != 0) {		//���� �̵� ���� ���� ���� �ǿ����� ���� ���� ��ġ�� �����ϴ����� Ȯ��
				return 1;			//�����ϸ� 1 ����
			}
		}
	}
	return 0;			//�ƴϸ� 0 ���� (�̵��� ����)
}

int blockCheckTurnLeft() {		//ȸ���� ���� ����üũ 
	for (int j = 0; j < 3; j++) {		//j�� 0���� 2���� ����
		if (playBlock[j][1] != 0 && gameblock[yset() + j][(XSize - 10) / 2 + 1] != 0) {		//�� �� �ϳ��� 1�̸� (������ �߻�������)
			return 1;		//1 ���� (ȸ���Ұ�)
		}
	}
	return 0;		//������ �߻����� ���� ��� 0 ����
}

int blockCheckTurnRight() {		//ȸ���� ������ ����üũ 
	for (int j = 0; j < 3; j++) {		//j�� 0���� 2���� ����
		if (playBlock[j][3] != 0 && gameblock[yset() + j][(XSize - 10) / 2 + 3] != 0) {		//�� �� �ϳ��� 1�̸� (������ �߻�������)
			return 2;		//2 ���� (ȸ���Ұ�)
		}
	}
	return 0;		//������ �߻����� ���� ��� 0 ����
}

int blockCheckTurnUp() {		//ȸ���� ���� ����üũ 
	for (int i = 1; i < 4; i++) {		//i�� 1���� 3���� ����
		if (playBlock[0][i] != 0 && gameblock[yset()][(XSize - 10) / 2 + i] != 0) {		//�� �� �ϳ��� 1�̸� (������ �߻�������)
			return 3;		//3 ���� (ȸ���Ұ�)
		}
	}
	return 0;		//������ �߻����� ���� ��� 0 ����
}

int blockCheckTurnDown(void) {		//ȸ���� �Ʒ��� ����üũ 
	for (int i = 1; i < 4; i++) {		//i�� 1���� 3���� ����
		if (playBlock[2][i] != 0 && gameblock[yset() + 2][(XSize - 10) / 2 + i] != 0) {		//�� �� �ϳ��� 1�̸� (������ �߻�������)
			return 4;		//4 ���� (ȸ���Ұ�)
		}
	}
	return 0;		//������ �߻����� ���� ��� 0 ����
}

int blockCheckTurn() {			//ȸ���� �Ҷ� ������ üũ�ϱ� ���� �Լ�

	if (playBlock[3][2] != 0 && gameblock[yset() + 3][(XSize - 10) / 2 + 2] != 0) {		// ���� ����� �� ������ (2, 3)���� �Ͼ�� ��
		YSize -= 1;		//y���� 1 ����
		if (blockCheckTurnUp() == 3) {		//�̵��� ��ǥ�� ���� ���� ��
			YSize += 1;			//�̵��� ��ǥ �ʱ�ȭ
			return 1;			//1 ���� (ȸ�� �Ұ�)
		}
		else {
			if (blockCheckTurnDown() == 4) {		//�̵��� ��ǥ�� �Ʒ��� ���� ��
				YSize -= 1;		//��ĭ �� �̵�
				if (blockCheckTurnUp() == 3) {		//�ٽ� �̵��� ��ǥ�� ���� ���� ��
					YSize += 2;			//�̵��� ��ǥ �ʱ�ȭ
					return 1;			//1 ���� (ȸ�� �Ұ�)
				}
				else {				//���� ���� ���� ��
					return 0;		//0 ����
				}
			}
			else {					//���� ���� ���� ��
				return 0;			//0 ����
			}
		}
	}
	else if ((playBlock[1][0] != 0 && gameblock[yset()+1][(XSize-10)/2]!=0)&& XSize >= 10){	//���� ����� �� ������ (0, 1)���� �Ͼ�� ��
		XSize += 2;				//x���� 2 ����
		if (blockCheckTurnRight() == 2) {		//�̵��� ��ǥ�� ������ ������
			XSize -= 2;				//�̵��� ��ǥ �ʱ�ȭ
			return 1;				//1 ���� (ȸ�� �Ұ�)
		}
		else {				//���� ���� ���� ��
			return 0;		//0 ����
		}
	}
	else if (blockCheckTurnDown() == 4) {		//�ϴ� ���� üũ
		if (playBlock[3][2] == 1) {		//���� �� ���� ��
			YSize -= 2;			//y�� 2 ����
			if (blockCheckTurnUp() == 3 || (playBlock[1][2] == 1 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] == 1)) {	//����, �߾� ���� üũ, ������ �߻�������
				YSize += 2;		//�̵��� ��ǥ �ʱ�ȭ
				return 1;		//1 ����(ȸ�� �Ұ�)
			}
			else {			//������ �߻����� �ʾ�����
				return 0;	//0 ����
			}
		}
		YSize -= 1;		//���� ���� �ƴ� ��� y��ǥ�� 1ĭ ���� �ű�
		if (blockCheckTurnUp() != 3) {		//�̵��� ��ǥ�� ��� ���� �� �Ҷ�
			if (blockCheckTurnLeft() == 1) {	//���� ���� üũ, ������ �߻�������
				XSize += 2;		//x�� 2 ����
				if (blockCheckTurnDown() == 4) {	//�̵��� ��ǥ �ϴ� ���� üũ, ������ �߻�������
					XSize -= 2;		//x�� 2 ����
					YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ����(ȸ�� �Ұ�)
				}
				else if (blockCheckTurnLeft() == 1) {	//�̵��� ��ǥ ���� ���� üũ, ������ �߻�������
					XSize -= 2;		//x�� 2 ����
					YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ����(ȸ�� �Ұ�)
				}
				else if (blockCheckTurnRight() == 2) {	//�̵��� ��ǥ ������ ���� üũ, ������ �߻�������
					XSize -= 2;		//x�� 2 ����
					YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ����(ȸ�� �Ұ�)
				}
				else if (blockCheckTurnUp() == 4) {	//�̵��� ��ǥ ���� ���� üũ, ������ �߻�������
					XSize -= 2;		//x�� 2 ����
					YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ����(ȸ�� �Ұ�)
				}
				else if (playBlock[1][2] == 1 && gameblock[yset()+1][(XSize-10)/2+2]==1) {	//�̵��� ��ǥ �߾� ���� üũ, ������ �߻�������
					XSize -= 2;		//x�� 2 ����
					YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ����(ȸ�� �Ұ�)
				}
				else {		//��� ������ �ش���� ������
					return 0;		//0 ����
				}
			}
			else if (blockCheckTurnRight() == 2) {	//���� ���� üũ, ������ �߻�������
				XSize -= 2;		//x�� 2 ����
				if (blockCheckTurnDown() == 4) {	//�̵��� ��ǥ �ϴ� ���� üũ, ������ �߻�������
					XSize += 2;		//x�� 2 ����
					YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ����(ȸ�� �Ұ�)
				}
				else if (blockCheckTurnLeft() == 1) {	//�̵��� ��ǥ ���� ���� üũ, ������ �߻�������
					XSize += 2;		//x�� 2 ����
					YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ����(ȸ�� �Ұ�)
				}
				else if (blockCheckTurnRight() == 2) {	//�̵��� ��ǥ ������ ���� üũ, ������ �߻�������
					XSize += 2;		//x�� 2 ����
					YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ����(ȸ�� �Ұ�)
				}
				else if (blockCheckTurnUp() == 4) {	//�̵��� ��ǥ ���� ���� üũ, ������ �߻�������
					XSize += 2;		//x�� 2 ����
					YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ����(ȸ�� �Ұ�)
				}
				else if (playBlock[1][2] == 1 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] == 1) {	//�̵��� ��ǥ �߾� ���� üũ, ������ �߻�������
					XSize += 2;		//x�� 2 ����
					YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ����(ȸ�� �Ұ�)
				}
				else {		//��� ������ �ش���� ������
					return 0;		//0 ����
				}
			}
		}
		else {		//��� ���� ��
			YSize += 1;	//y�� 1 ���� (��ǥ �ʱ�ȭ) 
			return 1;	//1 ���� (ȸ�� �Ұ�)
		}
	}
	else if (blockCheckTurnLeft() == 1) {		//���� ���� üũ
		if (playBlock[1][0] == 1) {		//���� ���� ������ �߻�������
			XSize += 4;		//x�� 4 ����
			if (blockCheckTurnRight() == 2 || (playBlock[1][2] == 1 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] == 1)) {		//�̵��� ��ǥ ������ ���� üũ, �߾� ���� üũ, ������ �߻�������
				XSize -= 4;		//x�� 4 ���� (��ǥ �ʱ�ȭ)
				return 1;		//1 ���� (ȸ�� �Ұ�)
			}
			else {		//���� ���� �ʾ��� ��
				return 0;	//0 ����
			}
		}
		XSize += 2;		//x�� 2 ����
		if (blockCheckTurnRight() == 2) {		//�̵��� ��ǥ ������ ���� üũ
			XSize -= 2;		//x�� 2 ����
			YSize -= 1;		//y�� 1 ����
			if (blockCheckTurnDown() == 4) {	//�̵��� ��ǥ �ϴ� ���� üũ
				YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
				return 1;		//1 ���� (ȸ�� �Ұ�)
			}
			else if (blockCheckTurnLeft() == 1) {	//�̵��� ��ǥ ���� ���� üũ
				YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
				return 1;		//1 ���� (ȸ�� �Ұ�)
			}
			else if (blockCheckTurnRight() == 2) {	//�̵��� ��ǥ ������ ���� üũ
				YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
				return 1;		//1 ���� (ȸ�� �Ұ�)
			}
			else if (blockCheckTurnUp() == 3) {	//�̵��� ��ǥ ���� ���� üũ
				YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
				return 1;		//1 ���� (ȸ�� �Ұ�)
			}
			else if (playBlock[1][2] == 1 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] == 1) {	//�̵��� ��ǥ �߾� ���� üũ
				YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
				return 1;		//1 ���� (ȸ�� �Ұ�)
			}
			else {		//��� ������ �ش���� ������
				return 0;	//0 ����
			}
		}
		else if (playBlock[1][2] == 1 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] == 1) {
			YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
			return 1;		//1 ���� (ȸ�� �Ұ�)
		}
		else {		//��� ������ �ش���� ������
			return 0;	//0 ����
		}
	}
	else if (blockCheckTurnRight() == 2) {		//������ ���� üũ
		XSize -= 2;		//x�� 2 ����
		if (blockCheckTurnLeft() == 1) {	//�̵��� ��ǥ ���� ����üũ
			XSize += 2;		//x�� 2 ����
			YSize -= 1;		//y�� 1 ����
			if (blockCheckTurnDown() == 4) {	//�̵��� ��ǥ �ϴ� ���� üũ
				YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
				return 1;		//1 ���� (ȸ�� �Ұ�)
			} else if (blockCheckTurnLeft() == 1) {	//�̵��� ��ǥ ���� ���� üũ
				YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
				return 1;		//1 ���� (ȸ�� �Ұ�)
			}
			else if (blockCheckTurnRight() == 2) {	//�̵��� ��ǥ ������ ���� üũ
				YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
				return 1;		//1 ���� (ȸ�� �Ұ�)
			}
			else if (blockCheckTurnUp() == 3) {	//�̵��� ��ǥ ���� ���� üũ
				YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
				return 1;		//1 ���� (ȸ�� �Ұ�)
			}
			else if (playBlock[1][2] == 1 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] == 1) {	//�̵��� ��ǥ �߾� ���� üũ
				YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
				return 1;		//1 ���� (ȸ�� �Ұ�)
			}
			else {		//��� ������ �ش���� ������
				return 0;	//0 ����
			}
		}
		else if (playBlock[1][2] != 0 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] != 0) {	//�̵��� ��ǥ �߾� ���� üũ
			YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
			return 1;		//1 ���� (ȸ�� �Ұ�)
		}
		else {		//��� ������ �ش���� ������
			return 0;	//0 ����
		}
	}
	else if (blockCheckTurnLeft() == 3) {	//��� ���� üũ
		YSize += 1;		//y�� 1 ����
		if (blockCheckTurnDown() != 4) {	//�̵��� ��ǥ �ϴ� ���� �� �� �� 
			if (blockCheckTurnLeft() == 1) {	//�̵��� ��ǥ ���� ����üũ
				XSize += 2;		//x�� 2 ����
				if (blockCheckTurnDown() == 4) {	//�̵��� ��ǥ �ϴ� ���� üũ
					XSize -= 2;		//x�� 2 ����
					YSize -= 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ���� (ȸ�� �Ұ�)
				}
				else if (blockCheckTurnLeft() == 1) {	//�̵��� ��ǥ ���� ���� üũ
					XSize -= 2;		//x�� 2 ����
					YSize -= 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ���� (ȸ�� �Ұ�)
				}
				else if (blockCheckTurnRight() == 2) {	//�̵��� ��ǥ ������ ���� üũ
					XSize -= 2;		//x�� 2 ����
					YSize -= 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ���� (ȸ�� �Ұ�)
				}
				else if (blockCheckTurnUp() == 3) {	//�̵��� ��ǥ ���� ���� üũ
					XSize -= 2;		//x�� 2 ����
					YSize -= 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ���� (ȸ�� �Ұ�)
				}
				else if (playBlock[1][2] != 0 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] != 0) {	//�̵��� ��ǥ �߾� ���� üũ
					YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ���� (ȸ�� �Ұ�)
				}
				else {		//��� ������ �ش���� ������
					return 0;	//0 ����
				}
			}
			if (blockCheckTurnRight()==2) {	//�̵��� ��ǥ ������ ����üũ
				XSize -= 2;		//x�� 2 ����
				if (blockCheckTurnDown() == 4) {	//�̵��� ��ǥ �ϴ� ���� üũ
					XSize += 2;		//x�� 2 ����
					YSize -= 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ���� (ȸ�� �Ұ�)
				}
				else if (blockCheckTurnLeft() == 1) {	//�̵��� ��ǥ ���� ���� üũ
					XSize += 2;		//x�� 2 ����
					YSize -= 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ���� (ȸ�� �Ұ�)
				}
				else if (blockCheckTurnRight() == 1) {	//�̵��� ��ǥ ������ ���� üũ
					XSize += 2;		//x�� 2 ����
					YSize -= 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ���� (ȸ�� �Ұ�)
				}
				else if (blockCheckTurnUp() == 1) {	//�̵��� ��ǥ ���� ���� üũ
					XSize += 2;		//x�� 2 ����
					YSize -= 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ���� (ȸ�� �Ұ�)
				}
				else if (playBlock[1][2] != 0 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] != 0) {	//�̵��� ��ǥ �߾� ���� üũ
					YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
					return 1;		//1 ���� (ȸ�� �Ұ�)
				}
				else {		//��� ������ �ش���� ������
					return 0;	//0 ����
				}
			}
			else {		//ȸ���� �� ���� ��
				YSize -= 1;		//y�� 1 ����
				return 1;		//1 ����
			}
		}
		else if (playBlock[1][2] != 0 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] != 0) {	//�̵��� ��ǥ �߾� ���� üũ
			YSize += 1;		//y�� 1 ���� (��ǥ �ʱ�ȭ)
			return 1;		//1 ���� (ȸ�� �Ұ�)
		}
		else {		//��� ������ �ش���� ������
			return 0;	//0 ����
		}
	}
}

void calcTurnLeft() {	//�������� �� �� ȸ�� �����ϴ� �Լ�
	int temp = 0;			//���� temp ����

	temp = playBlock[2][3];		//ȸ���� ���� ������ ȸ�� 
	playBlock[2][3] = playBlock[2][1];
	playBlock[2][1] = playBlock[0][1];
	playBlock[0][1] = playBlock[0][3];
	playBlock[0][3] = temp;

	temp = playBlock[1][3];		//ȸ���� ���� �𼭸� ȸ�� 
	playBlock[1][3] = playBlock[2][2];
	playBlock[2][2] = playBlock[1][1];
	playBlock[1][1] = playBlock[0][2];
	playBlock[0][2] = temp;

	temp = playBlock[1][0];		//���ں��� ���ԵǴ� �κ� ȸ�� 
	playBlock[1][0] = playBlock[3][2];
	playBlock[3][2] = temp;
}

void calcTurnRight() {	//���������� �� �� ȸ�� �����ϴ� �Լ�
	int temp = 0;			//���� temp ����

	temp = playBlock[0][3];		//ȸ���� ���� ������ ȸ�� 
	playBlock[0][3] = playBlock[0][1];
	playBlock[0][1] = playBlock[2][1];
	playBlock[2][1] = playBlock[2][3];
	playBlock[2][3] = temp;

	temp = playBlock[0][2];		//ȸ���� ���� �𼭸� ȸ�� 
	playBlock[0][2] = playBlock[1][1];
	playBlock[1][1] = playBlock[2][2];
	playBlock[2][2] = playBlock[1][3];
	playBlock[1][3] = temp;

	temp = playBlock[1][0];		//���ں��� ���ԵǴ� �κ� ȸ�� 
	playBlock[1][0] = playBlock[3][2];
	playBlock[3][2] = temp;
}

void turnLeft() {		//turnLeft �Լ� (�������� ȸ���ϴ� �Լ�)
	if (playBlock[1][2] == 1 && playBlock[2][1] == 1 && playBlock[2][2] == 1 && playBlock[1][1] == 1) {		//���簢�� ���Ͻ� 
		return;			//ȸ���� ���� �ʰ� ����
	}

	removePrint(playBlock);	//�ܻ� ����

	calcTurnLeft();		//ȸ�� ����

	if (blockCheckTurn() == 1) {	//�� ���� üũ�ؼ� 1�� ���ϵǸ�
		calcTurnRight();		//���󺹱�
	}
	guide();
	printBlock(playBlock);		//ȸ���� ��� ���
}

void turnRight() {		//turnRight �Լ� (���������� ȸ���ϴ� �Լ�)
	if (playBlock[1][2] == 1 && playBlock[2][1] == 1 && playBlock[2][2] == 1 && playBlock[1][1] == 1) {		//���簢�� ���Ͻ�
		return;			//ȸ���� ���� �ʰ� ����
	}

	removePrint(playBlock);	//�ܻ� ����

	calcTurnRight();	//ȸ�� ����

	if (blockCheckTurn() == 1) {	//�� ���� üũ�ؼ� 1�� ���ϵǸ�
		calcTurnLeft();		//���󺹱�
	}
	guide();
	printBlock(playBlock);		//ȸ���� ��� ���
}

void moveLeft() {		//moveLeft �Լ� (�������� �̵��ϴ� �Լ�)
	if (blockCheckMoveLeft() != 1) {	//���� ���� ������ ���� ������
		removePrint(playBlock);	//�ܻ� ����
		XSize -= 2;				//x�� ���� �������� 2��ŭ �̵�
		guide();
		printBlock(playBlock);	//�̵��� �ڸ��� ���
	}
}

void moveRight() {		//moveRight �Լ� (���������� �̵��ϴ� �Լ�)
	if (blockCheckMoveRight() != 1) {	//������ ���� ������ ���� ������
		removePrint(playBlock);	//�ܻ� ����
		XSize += 2;				//x�� ������ �������� 2��ŭ �̵�
		guide();
		printBlock(playBlock);	//�̵��� �ڸ��� ���
	}
}

int moveDown() {		//moveDown �Լ� (������ �̵��ϴ� �Լ�)
	if (blockCheckDown() != 1) {	//���� ���� �� (������ �� ������)
		removePrint(playBlock);	//�ܻ� ����
		YSize+=1;				//y�� �������� 1��ŭ �̵�
		printBlock(playBlock);	//�̵��� �ڸ��� ���
		score += 1;				//���� 1�� �߰�
		return 0;	//0 ����
	}
	else {	//���� �� (���̻� �� ������ ��)
		return 1;	//1 ����
	}
}

void goDown(int a) {
	removePrint(playBlock);
	while (blockCheckDown() == 0) {
		YSize++;
		if (a == 0) {
			score += 2;
		}
	}
	printBlock(playBlock);
	return;
}

int keyBoard() {		//keyBoard �Լ� (Ű���� �Է��� �޴� �Լ�)
	if (_kbhit()) {		//Ű���� �Է��� �޾��� ��
		int key = _getch();	//�Է¹��� ���� key�� ����
		if (key == 224) {	//key���� 224(����Ű) �̸�
			key = _getch();	//�ѹ��� ���� (����Ű�� 224�� ���� �ϳ��� �� ����)
			switch (key) {	//�޾ƿ� key�� ���� �ְ�
			case 72:		//key�� 72(���� ����Ű) �̸�
				turnLeft();	//�������� ����
				break;
			case 75:		//key�� 75(���� ����Ű) �̸�
				moveLeft();	//�������� �̵�
				break;
			case 77:		//key�� 77(������ ����Ű) �̸�
				moveRight();//���������� �̵�
				break;
			case 80:		//key�� 80(�Ʒ��� ����Ű) �̸�
				moveDown();	//�Ʒ��� �̵�
				return 1;	//1 ����(�����ð��� �ʱ�ȭ�ϱ�����)
				break;
			}
		}
		else if (key == 115) { //key�� 115(sŰ) �̸�
			turnLeft();		   //�������� ����
		}
		else if (key == 100) { //key 100(dŰ) �̸�
			turnRight();	   //���������� ����
		}
		else if (key == 32) {
			goDown(0);
			gotoxy(10, 32);
			return 1;
		}
		else {
			return 0;
		}
	}
}

void topgameline() {	//��� ��輱�� �����ϴ� �Լ�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);		//��� ��輱�� ������� ���� 
	gotoxy(10, 9);	//10, 9 ��ǥ �̵�
	for (int j = 0; j < 12; j++) {	//12�� �ݺ��ϸ鼭
		printf("����");		//���� ���
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), currentBlock);		//�ؽ�Ʈ �� �ٽ� ���� ��� ������ ���� 
}

void moveBlock(int speed) {		//moveBlock �Լ� (1�ʰ������� ���� �ϰ���)
	XSize = 18;			//x�� ��ǥ�� 18�� ����
	YSize = 8;			//y�� ��ǥ�� 8���� ����

	moveDown();			//ó�� ���� �����ɶ� �� ��ġ�� �����ϱ� ����
	moveDown();			//�ι� �Ʒ��� ����
	guide();
	while (1) {			//��� �ݺ�
		for (int i = 0; i < speed; i++) {	//10ms�� speed�� �ݺ� = (10*speed) / 1000�� �������� �ϰ�
			if (_kbhit()) {				//Ű���� �Է��� ���� ��
				if (keyBoard() == 1) {	//������ �̵��ϴ� ����Ű �Է� �޾��� �� (1�� ���Ϲ޾��� ��)
					continue;			//�����ð� �ʱ�ȭ(�ٽ� n�ʵ��� ��ٷ��� ���� �Ʒ��� ������)
				}
			}
			topgameline();			//�� ���� ��輱 ���	
			Sleep(10);				//10ms ���
		}
		if (blockCheckDown() == 1) {		//�Ʒ��� �� �̻� �̵��� �Ұ����ϸ�
			return;					//�Լ��� ����
		}
		moveDown();		//�Ʒ��� �ϰ�
	}
}

int checkXsize(int arr[4]) {			//������� �� X��ǥ�� �����ϱ� ���� �Լ�
	if (setColor(arr) == 14 || setColor(arr) == 11) {		//������� ���� �׸� ���� ����̸�
		return 44;			//X��ǥ���� 44�� ��
	}
	else {					//������� ���� �׸� ���� ����� �ƴϸ�
		return 43;			//X��ǥ���� 43���� ��
	}
}

void blockPrint() {			//������� �� ���
	XSize = checkXsize(blocksetprint[0]);		//checkXsize�Լ��� ���� X��ǥ���� ����
	YSize = 9;				//y�� 9 ��ġ��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), setColor(blocksetprint[0]));	//��� ��翡 �´� ���� ����
	printBlock(blocksetprint[0]);	//blocksetprint�� ���� ù��° ���� ���

	XSize = checkXsize(blocksetprint[1]);		//checkXsize�Լ��� ���� X��ǥ���� ����
	YSize = 14;				//y�� 14 ��ġ��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), setColor(blocksetprint[1]));	//��� ��翡 �´� ���� ����
	printBlock(blocksetprint[1]);	//blocksetprint�� ���� �ι�° ���� ���

	XSize = checkXsize(blocksetprint[2]);		//checkXsize�Լ��� ���� X��ǥ���� ����
	YSize = 19;				//y�� 19 ��ġ��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), setColor(blocksetprint[2]));	//��� ��翡 �´� ���� ����
	printBlock(blocksetprint[2]);	//blocksetprint�� ���� ����° ���� ���

	XSize = checkXsize(blocksetprint[3]);		//checkXsize�Լ��� ���� X��ǥ���� ����
	YSize = 24;				//y�� 24 ��ġ��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), setColor(blocksetprint[3]));	//��� ��翡 �´� ���� ����
	printBlock(blocksetprint[3]);	//blocksetprint�� ���� �׹�° ���� ���

	XSize = checkXsize(blocksetprint[4]);		//checkXsize�Լ��� ���� X��ǥ���� ����
	YSize = 29;				//y�� 29 ��ġ��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), setColor(blocksetprint[4]));	//��� ��翡 �´� ���� ����
	printBlock(blocksetprint[4]);	//blocksetprint�� ���� �ټ���° ���� ���

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void removeBlockPrint() {			//������� �� �ܻ� �����
	XSize = checkXsize(blocksetprint[0]);		//checkXsize�Լ��� ���� X��ǥ���� ����
	YSize = 9;				//y�� 9 ��ġ��
	removePrint(blocksetprint[0]);	//blocksetprint�� ���� ù��° �� �ܻ��� ����

	XSize = checkXsize(blocksetprint[1]);		//checkXsize�Լ��� ���� X��ǥ���� ����
	YSize = 14;				//y�� 14 ��ġ��
	removePrint(blocksetprint[1]);	//blocksetprint�� ���� �ι�° �� �ܻ��� ����

	XSize = checkXsize(blocksetprint[2]);		//checkXsize�Լ��� ���� X��ǥ���� ����
	YSize = 19;				//y�� 19 ��ġ��
	removePrint(blocksetprint[2]);	//blocksetprint�� ���� ����° �� �ܻ��� ����

	XSize = checkXsize(blocksetprint[3]);		//checkXsize�Լ��� ���� X��ǥ���� ����
	YSize = 24;				//y�� 24 ��ġ��
	removePrint(blocksetprint[3]);	//blocksetprint�� ���� �׹�° �� �ܻ��� ����

	XSize = checkXsize(blocksetprint[4]);		//checkXsize�Լ��� ���� X��ǥ���� ����
	YSize = 29;				//y�� 29 ��ġ��
	removePrint(blocksetprint[4]);	//blocksetprint�� ���� �ټ���° �� �ܻ��� ����
}

void changeac(int num) {		//������� �� ��ĭ�� ������ ����
	removeBlockPrint();			//������� �� �ܻ� �����
	for (int i = 0; i < 4; i++) {	//i 0~3���� �ݺ�
		for (int j = 0; j < 4; j++) {	//j 0~3���� �ݺ�
			playBlock[i][j] = blocksetprint[0][i][j];		//������� ù��° ���� playBlock�� ����
			blocksetprint[0][i][j] = blocksetprint[1][i][j];	//������� �ι�° ���� ������� ù��° ���� ����
			blocksetprint[1][i][j] = blocksetprint[2][i][j];	//������� ����° ���� ������� �ι�° ���� ����
			blocksetprint[2][i][j] = blocksetprint[3][i][j];	//������� �׹�° ���� ������� ����° ���� ����
			blocksetprint[3][i][j] = blocksetprint[4][i][j];	//������� �ټ���° ���� ������� �׹�° ���� ����
			blocksetprint[4][i][j] = block[num][i][j];			//������ �� �ϳ��� ������� �ټ���° ���� ����
		}
	}
	blockPrint();		//�� ���
}

void setGameBlock() {			//���� �������� �ִ� ��Ʈ���� ���� ���� ȭ�鿡 �߰��ϴ� �Լ�
	for (int i = 0; i < 4; i++) {	//i 0~3���� �ݺ�
		for(int j=0; j<4; j++){		////j 0~3���� �ݺ�
			if (playBlock[i][j] == 1) {	//���� 1�� �κп� ����	(�÷��� �ϰ��ִ� ���� �κ�)
				gameblock[yset() + i][(XSize - 10) / 2 + j] = currentBlock;	//���� ȭ�鿡 �ش� ���� �߰�
			}
		}
	}
}

void printGameBlock() {		//���� �ϼ��Ǿ����� ���� ���� ������ ������ ����ϱ� ���� �Լ�
	for (int i = 4; i < 24; i++) {	//i�� 4����, 20�� �ݺ�
		gotoxy(12, 7 + i);		//12, 7+i ��ǥ �̵�
		for (int j = 1; j < 11; j++)	//j�� 1���� 10�� �ݺ�
		{
			if (gameblock[i][j] == 0) {		//gameblock[i][j]�� 0�̸� (���� ������)
				printf("  ");		//���� ���
			}
			else {	//���� ������
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), gameblock[i][j]);	//�� ���� ����
				printf("��");		//�� ���
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	//���� �ٽ� ������� ����
}

void finishedGameBlock(int a) {		//���� �ϼ��Ǿ��� �� ȣ���ϴ� �Լ�
	int k = 0;
	for (int i = a; i > 0; i--) {	//�޾ƿ� a���� i�� �ְ� i�� 0���� Ŭ ���� �ݺ��ϰ� i�� 1�� ����
		for (int j = 1; j < 11; j++){	//j�� 1���� 10�� �ݺ�
			gameblock[i][j] = gameblock[i - 1][j];		//�ϼ��� ���� ���ٺ��� �ϳ��� �Ʒ��ٷ� �̵� 
			k++;
		}
		printGameBlock();		//���� ȭ�� ����
	}
	if (k == 0) {
		return;
	}
	else if (k == 1) {
		score += 100;
	}
	else if (k == 2) {
		score += 300;
	}
	else if (k == 3) {
		score += 500;
	}
	else {
		score += 800;
	}
}

void scanGameBlock() {		//���� ���� �ϼ��Ǿ����� Ȯ���ϱ� ���� �Լ�
	int j;		//j���� ����
	for (int i = 23; i > 3; i--){		//i�� 23���� 20�� �ݺ�
		for (j = 1; j < 11; j++){	//j�� 1���� 10�� �ݺ�
			if (gameblock[i][j] == 0) {		//�ϼ��� ���� ���� �κ��� �ִٸ�
				break;		//�ݺ� ���� (���� �ٷ�)
			}
		}
		if (j == 11) {		//�ϼ��� �Ǿ��ٸ�
			finishedGameBlock(i++);		// �� �پ� ���� 
		}
	}
}

int compareBlock(int arr[4][4], int a) {	//arr�迭�� ��� ���� block�迭�� a��° ���� ������ ���ϴ� �Լ�
	for (int i = 0; i < 4; i++) {	//4�� �ݺ�
		for (int j = 0; j < 4; j++) {	//4�� �ݺ�
			if (arr[i][j] != block[a][i][j]) {	//arr�迭�� ���� block�迭�� a��° ���� ���� ������
				return 1;		//1 ���� (���� �ʴٴ� ��ȣ)
			}
		}
	}
	return 0;	//������ 0 ����
}

int setColor(int arr[4][4]) {	//���� �޾ƿͼ� �� ���� ������ ������ ���� ���� �ڵ带 �������ִ� �Լ�
	int i;		//i ���� ����

	for (i = 0; i < 7; i++) {	//7�� �ݺ�
		if (compareBlock(arr, i) == 0) {	//arr�迭�� �޾ƿ� ���� � ������ ã������ compareBlock�� ����
			break;		//���� ã������(0�� ���� �޾�����) break
		}
	}

	if (i == 0) {		//0��° ���̸� (�׸� ����̸�)
		return 14;		//����� �ڵ��� 14�� ����
	}
	if (i == 1) {		//1��° ���̸� (���� ����̸�)
		return 11;		//�ϴû� �ڵ��� 11�� ����
	}
	if (i == 2) {		//2��° ���̸� (S ����̸�)
		return 10;		//���λ� �ڵ��� 10�� ����
	}
	if (i == 3) {		//3��° ���̸� (Z ����̸�)
		return 12;		//������ �ڵ��� 12�� ����
	}
	if (i == 4) {		//4��° ���̸� (L ����̸�)
		return 4;		//��Ȳ�� �ڵ��� 4�� ����
	}
	if (i == 5) {		//5��° ���̸� (J ����̸�)
		return 9;		//�Ķ��� �ڵ��� 9�� ����
	}
	if (i == 6) {		//6��° ���̸� (T ����̸�)
		return 13;		//����� �ڵ��� 13�� ����
	}
}

