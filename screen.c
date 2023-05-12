#include "screen.h"	//screen.h ��� ������ ���α׷��� ���Խ�Ű�� ���� �ڵ�

void gotoxy(int x, int y) {//gotoxy : Ŀ�� ��ġ�� �����Ͽ� ȭ�� �󿡼� ��� ��ġ�� �̵���Ű�� �Լ�
	COORD pos = { x,y };	//gotoxy �Լ� ���ο����� COORD ����ü�� ����Ͽ� Ŀ���� ��ġ�� ����
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);		//SetConsoleCursorPosition �Լ��� ����Ͽ� Ŀ���� ��ġ�� �����ϰ� GetStdHandle �Լ��� ����Ͽ� ǥ�� ��� ��Ʈ�� �ڵ��� ������
}

void printT(int x, int y) {		//���� ȭ�� T ���
	gotoxy(x, y);     printf("������");	//T�� ����� ���� �� ���
	gotoxy(x, y + 1); printf("    ��  ");	//T�� ����� ���� �� ���
	gotoxy(x, y + 2); printf("    ��  ");	//T�� ����� ���� �� ���
	gotoxy(x, y + 3); printf("    ��  ");	//T�� ����� ���� �� ���
	gotoxy(x, y + 4); printf("    ��  ");	//T�� ����� ���� �� ���
}
void printE(int x, int y) {		//���� ȭ�� E ���
	gotoxy(x, y);     printf("�����");	//E�� ����� ���� �� ���
	gotoxy(x, y + 1); printf("��  ");	//E�� ����� ���� �� ���
	gotoxy(x, y + 2); printf("�����");	//E�� ����� ���� �� ���
	gotoxy(x, y + 3); printf("��  ");	//E�� ����� ���� �� ���
	gotoxy(x, y + 4); printf("�����");	//E�� ����� ���� �� ���
}
void printR(int x, int y) {		//���� ȭ�� R ���
	gotoxy(x, y);     printf("����    ");	//R�� ����� ���� �� ���
	gotoxy(x, y + 1); printf("��    ��  ");	//R�� ����� ���� �� ���
	gotoxy(x, y + 2); printf("���� ");	//R�� ����� ���� �� ���
	gotoxy(x, y + 3); printf("��    ��  ");	//R�� ����� ���� �� ���
	gotoxy(x, y + 4); printf("��    ��");	//R�� ����� ���� �� ���

}
void printI(int x, int y) {		//���� ȭ�� I ���
	gotoxy(x, y);     printf("������");	//I�� ����� ���� �� ���
	gotoxy(x, y + 1); printf("    ��");	//I�� ����� ���� �� ���
	gotoxy(x, y + 2); printf("    �� ");	//I�� ����� ���� �� ���
	gotoxy(x, y + 3); printf("    ��");	//I�� ����� ���� �� ���
	gotoxy(x, y + 4); printf("������");	//I�� ����� ���� �� ���

}
void printS(int x, int y) {		//���� ȭ�� S ���
	gotoxy(x, y);     printf("  �����");	//S�� ����� ���� �� ���
	gotoxy(x, y + 1); printf("��");	//S�� ����� ���� �� ���
	gotoxy(x, y + 2); printf("  ����  ");	//S�� ����� ���� �� ���
	gotoxy(x, y + 3); printf("        ��");	//S�� ����� ���� �� ���
	gotoxy(x, y + 4); printf("�����  ");	//S�� ����� ���� �� ���
}

void cursorview() {		//Ŀ���� ������ �ʰ� �ϴ� �Լ�
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };		//Ŀ���� �Ӽ� ������ �����ϴµ� ���Ǵ� ����ü ���� cursorInfo�� �����ϰ� �ʱ�ȭ
	cursorInfo.dwSize = 1;			//Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = FALSE;	//Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);		//SetConsoleCursorInfo �Լ��� ����Ͽ� Ŀ���� ������ ����
}

int selectLevel() {
	int CursorS = 18;
	int i = 0;
	int num = 0;
	gotoxy(39, 18);
	printf("Easy");
	gotoxy(39, 20);
	printf("Normal");
	gotoxy(39, 22);
	printf("Hard");
	gotoxy(39, 24);
	printf("Exit");
	gotoxy(36, 18);
	printf(">>");
	while (1) {
		for (i = 0; i < 10; i++) {
			if (kbhit()) {
				int input = getch();
				if (input == 13) {		//����Ű�� �Է� ���� ��
					if (CursorS == 18) {
						//PlaySound(TEXT("start.wav"), 0, SND_ASYNC);		//���� ȿ����

						for (i = 0; i < 5; i++) {		//���ý� ��¦�Ÿ� 
							gotoxy(39, 18);
							printf("        ");
							Sleep(100);
							gotoxy(39, 18);
							printf("Easy");
							Sleep(100);
						}
						system("cls");
						return 1;
					}

					else if (CursorS == 20) {
						/*PlaySound(TEXT("start.wav"), 0, SND_ASYNC);*/

						for (i = 0; i < 5; i++) {		//���ý� ��¦�Ÿ� 
							gotoxy(39, 20);
							printf("       ");
							Sleep(100);
							gotoxy(39, 20);
							printf("Normal");
							Sleep(100);
						}
						system("cls");
						return 2;
					}

					else if (CursorS == 22) {
						/*PlaySound(TEXT("start.wav"), 0, SND_ASYNC);*/

						for (i = 0; i < 5; i++) {		//���ý� ��¦�Ÿ� 
							gotoxy(39, 22);
							printf("      ");
							Sleep(100);
							gotoxy(39, 22);
							printf("Hard");
							Sleep(100);
						}
						system("cls");
						return 3;
					}

					else {
						return 0;
					}
				}

				else if (input == 224) {
					input = getch();

					switch (input) {
						case 72: {		//����Ű ��
							gotoxy(36, CursorS);
							printf("  ");
							if (CursorS != 18)
								CursorS = CursorS - 2;
							else
								CursorS = 24;
							break;
						}

						case 80: {		//����Ű �Ʒ�
							gotoxy(36, CursorS);
							printf("  ");
							if (CursorS != 24)
								CursorS = CursorS + 2;
							else
								CursorS = 18;
							break;
						}
					}
				}
			}
			Sleep(10);
		}

		if (num == 0) {
			gotoxy(36, CursorS);
			printf(">>");
			num = 1;
		}

		else {
			gotoxy(36, CursorS);
			printf("  ");
			num = 0;
		}
	}
}

int startPage() {		//startPage �Լ� (���� ù ȭ���� ���� ���� �Լ�)
	srand(time(NULL));	//srand�� ����Ͽ� ���� �߻����� �ʱ� �õ� ���� �����ϴ� �ڵ�, �õ� ���� �Ź� �ٸ��� ���������ν� �پ��� ������ ������
	system("mode con cols=100 lines=41");	//Windows �ü������ �ܼ� â�� ũ�⸦ �����ϴ� ���, ���� 100ĭ, ���� 41ĭ���� ����
	cursorview();	//Ŀ���� ������ �ʰ� �ϴ� �Լ� ȣ��
	SetConsoleTitle(TEXT("Tetris (1906125 ����)"));	//�ܼ�â �̸��� Tetris (1906125 ����) ���� ����
	
	system("cls");		//ȭ�� �ʱ�ȭ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);		//������ ���������� ����
	printT(11, 8);		//T ���
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);		//������ ��Ȳ������ ����
	printE(25, 8);		//E ���
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);		//������ ��������� ����
	printT(38, 8);		//T ���
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);		//������ �ʷϻ����� ����
	printR(52, 8);		//R ���
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);		//������ �ϴû����� ����
	printI(65, 8);		//I ���
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);		//������ ��������� ����
	printS(80, 8);		//S ���
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);		//������ ������� ���� (�ʱ�ȭ)

	gotoxy(39, 25);		//39, 25 ��ǥ�̵�
	printf("Press any key to start");	//���� ���
	gotoxy(80, 32);		//80, 32 ��ǥ�̵�
	printf("c���� ������Ʈ");		//���� ���
	gotoxy(68, 33);		//68, 33 ��ǥ�̵�
	printf("����Ʈ���������� 2�г� 2��");
	gotoxy(80, 34);		//80, 34 ��ǥ�̵�
	printf("1906125 ����");	//���� ���
	gotoxy(29, 38);		//29, 38 ��ǥ�̵�
	printf("�����̰����б� Yeungnam University College");	//���� ���

	getch();	//����ڰ� Ű�� �Է��ϴ°��� �ޱ� ����, Ű�� �Է¹����� �� �ݺ��� ����

	for (int i = 0; i < 5; i++) { 		//Ű���� �Է½� ��¦�Ÿ��� ���� ��� ��¦�Ÿ��� �ݺ� (5��)
		gotoxy(39, 25);		//39, 25 ��ǥ�̵�
		printf("                      ");	//���� ��� (���� Press any key to start �� ������ ����)
		Sleep(100);		//0.1�ʵ��� ����
		gotoxy(39, 25);		//39, 25 ��ǥ�̵�
		printf("Press any key to start");	//���� ���
		Sleep(100);		//0.1�ʵ��� ����
	}
	system("cls");		//ȭ�� �ʱ�ȭ 
	return(selectLevel());
}

void screenLine() {		//screenLine �Լ� (ȭ�� ��ü�� ������ ����ϱ� ���� �Լ�)
	for (int i = 0; i < SCREEN_X_SIZE; i++) { //SCREEN_X_SIZE(40) ��ŭ �ݺ� (�ܼ�â ���� ���� ����ϱ� ����)
		printf("��");	//�ݺ� ���鼭 �� ���
	}
	for (int i = 0; i < SCREEN_Y_SIZE; i++) { //SCREEN_Y_SIZE(40) ��ŭ �ݺ� (�ܼ�â ���� ���� ����ϱ� ����)
		gotoxy(0, i + 1);	//Ŀ�� ��ġ�� (0, i+1)�� �̵�
		printf("��");		//�ݺ� ���鼭 �� ���
		gotoxy((SCREEN_X_SIZE*2)-2, i);		//Ŀ�� ��ġ�� (98, i)�� �̵�
		printf("��");		//�ݺ� ���鼭 �� ���
	}

	gotoxy(0, SCREEN_Y_SIZE);	//Ŀ�� ��ġ�� (0, 40)���� �̵�

	for (int i = 0; i < SCREEN_X_SIZE; i++) {	//SCREEN_X_SIZE(50) ��ŭ �ݺ� (�ܼ�â �Ʒ��� ���� ����ϱ� ����)
		printf("��");	//�ݺ� ���鼭 �� ���
	}
}

void boardLine() {	//boardLine �Լ�	(���� �������� ������ ����ϱ� ���� �Լ�)
	for (int i = 0; i < BOARD_Y_SIZE; i++) {	//BOARD_Y_SIZE(24) ��ŭ �ݺ� (���� ������ ���� ���� ����ϱ� ����)
		gotoxy(10, i + 10);	//Ŀ�� ��ġ�� (10, i+7)���� �̵�
		printf("��");		//�ݺ� ���鼭 �� ���
		gotoxy(10+(BOARD_X_SIZE*2)-2, i + 10);	//Ŀ�� ��ġ�� (32, i+7)���� �̵�
		printf("��");		//�ݺ� ���鼭 �� ���
	}

	gotoxy(10, 31);		//Ŀ�� ��ġ�� (10, 31)�� �̵�	
	for (int i = 0; i < BOARD_X_SIZE; i++) {	//BOARD_X_SIZE(12) ��ŭ �ݺ� (���� ������ �Ʒ��� ���� ����ϱ� ����)
		printf("��");	//�ݺ� ���鼭 �� ���
	}
}

void gameBlockSet() {			//������ ��輱�� ��� 1�� �����ϴ� �Լ�
	for (int i = 0; i < 12; i++) {		//�� �Ʒ��� �� ����� ���� �ݺ���, 12�� �ݺ�
		gameblock[24][i] = 1;			//25��° �࿡ 1 ����
	}
	for (int i = 0; i < 24; i++) {		//���� �� ����� ���� �ݺ���, 24�� �ݺ�
		gameblock[i][0] = 1;			//���� ���� �� 1 ����
		for (int j = 1; j < 11; j++) {	//���� �� ������ �߰� �κ�
			gameblock[i][j] = 0;	//0 ����
		}
		gameblock[i][11] = 1;			//���� ������ �� 1 ����
	}
}

void blockSetWall() {	//������� ���� �����ִ°� Ʋ�� ����ϱ� ���� �Լ�
	gotoxy(43, 7);	//43, 7 ��ǥ�̵�
	printf("N  E  X  T");	//NEXT �������

	for (int i = 0; i < 6; i++) {	//���μ��� ����ϱ� ���� �ݺ����� ���� 6�� ����
		gotoxy(42, 8 + i * 5);		//42, 8 + i * 5 ��ǥ�̵� (5ĭ�� ���� ���� *5)
		for (int j = 0; j < 11; j++) {	//���μ��� ����ϱ� ���� �� ���̸�ŭ �ݺ�
			if (i == 0 && j == 0) {		//ù��° �� ù��° ĭ�̸�
				printf("��");	//�� ���
			}
			else if (i == 0 && j == 10) {	//ù��° �� ������ ĭ�̸�
				printf("��");	//�� ���
			}
			else if (i == 5 && j == 0) {	//������ �� ù��° ĭ�̸�
				printf("��");	//�� ���
			}
			else if (i == 5 && j == 10) {	//������ �� ������ ĭ�̸�
				printf("��");	//�� ���
			}
			else {				//�� �� ��������
				printf("��");	//�� ���
			}
		}
	}
	for (int i = 0; i < 24; i++) {	//���ʰ� ������ Ʋ�� �׸��� ���� �ݺ�
		gotoxy(42, 9 + i);	//42, 9+i ��ǥ�̵�
		printf("��");		//�� ���
		gotoxy(52, 9 + i);	//52, 9+i ��ǥ�̵�
		printf("��");		//�� ���
	}
}

void guideWall() {		//���۹��� �����ִ� �� Ʋ�� ����ϴ� �Լ�
	for (int i = 0; i < 2; i++) {	//���� ��, ���� �Ʒ��� ����ϱ� ���� �ݺ����� ���� 2�� ����
		gotoxy(58, 10 + i * 20);		//58, 10 + i * 20 ��ǥ�̵�
		for (int j = 0; j < 34; j++) {	//�� ���� Ʋ�� �׸��� ���� �ݺ�
			if (i == 0 && j == 0) {		//ù��° �� ù��° ĭ�̸�
				printf("��");	//�� ���
			}
			else if (i == 0 && j == 33) {	//ù��° �� ������ ĭ�̸�
				printf("��");	//�� ���
			}
			else if (i == 1 && j == 0) {	//������ �� ù��° ĭ�̸�
				printf("��");	//�� ���
			}
			else if (i == 1 && j == 33) {	//������ �� ������ ĭ�̸�
				printf("��");	//�� ���
			}
			else {				//�� �� ��������
				printf("��");	//�� ���
			}
		}
		for (int i = 0; i < 19; i++) {	//���ʰ� ������ Ʋ�� �׸��� ���� �ݺ�
			gotoxy(58, 11 + i);	//58, 11+i ��ǥ�̵�
			printf("��");		//�� ���
			gotoxy(91, 11 + i);	//91, 11+i ��ǥ�̵�
			printf("��");		//�� ���
		}
	}
}

void printGuideMent() {	//���۹��� �����ִ� �Լ�
	gotoxy(67, 12);		//67, 12 ��ǥ�̵�
	printf("Tetris ���۹�");	//���� ���
	gotoxy(65, 16);		//65, 16 ��ǥ�̵�
	printf("��");	//���� ���
	gotoxy(72, 16);		//72, 16 ��ǥ�̵�
	printf(": �� ȸ��");	//���� ���
	gotoxy(61, 18);		//61, 18 ��ǥ�̵�
	printf("��");	//���� ���
	gotoxy(69, 18);		//69, 18 ��ǥ�̵�
	printf("��");	//���� ���
	gotoxy(72, 18);		//72, 18 ��ǥ�̵�
	printf(": ��/�� �̵�");	//���� ���
	gotoxy(65, 20);		//65, 20 ��ǥ�̵�
	printf("��");	//���� ���
	gotoxy(72, 20);		//72, 20 ��ǥ�̵�
	printf(": �Ʒ��� �̵�");	//���� ���
	gotoxy(65, 23);		//65, 23 ��ǥ�̵�
	printf("S");	//���� ���
	gotoxy(72, 23);		//72, 23 ��ǥ�̵�
	printf(": �������� ȸ��");	//���� ���
	gotoxy(65, 25);		//65, 25 ��ǥ�̵�
	printf("D");	//���� ���
	gotoxy(72, 25);		//72, 25 ��ǥ�̵�
	printf(": ���������� ȸ��");	//���� ���
	/*gotoxy(63, 27);
	printf("SPACE");
	gotoxy(72, 27);
	printf(": �ϵ���");*/
}

int scanGameOver() {		//���ӿ����ƴ��� üũ�ϴ� �Լ�
	for (int i = 1; i < 11; i++) {	//���� ���κ��� �ݺ��� ���鼭 Ȯ��
		if (gameblock[4][i] != 0)		//0�� �ƴѺκ��� ������
			return 1;		//1 ���� (���ӿ�����)
	}
}

void gameOverPage() {	//���ӿ��� ���� �� ����ϴ� ȭ��
	system("cls");		//ȭ�� �ʱ�ȭ

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);		//������ ���������� ����

	gotoxy(26, 6);
	printf("  ����      ����    ���      ���  �����");		//���� ���� ���� ���
	gotoxy(26, 7);
	printf("��      ��  ��      ��  ��  ��  ��  ��  ��      ");
	gotoxy(26, 8);
	printf("��          ��      ��  ��    ��    ��  ��      ");
	gotoxy(26, 9);
	printf("��      ��  ������  ��          ��  �����  ");
	gotoxy(26, 10);
	printf("��    ���  ��      ��  ��          ��  ��      ");
	gotoxy(26, 11);
	printf("��      ��  ��      ��  ��          ��  ��      ");
	gotoxy(26, 12);
	printf("  ����    ��      ��  ��          ��  �����");
	gotoxy(26, 13);
	printf("                                                ");
	gotoxy(26, 14);
	printf("    ����    ��      ��  �����  �����  ");
	gotoxy(26, 15);
	printf("  ��      ��  ��      ��  ��        ��      ��");
	gotoxy(26, 16);
	printf("  ��      ��  ��      ��  ��        ��      ��");
	gotoxy(26, 17);
	printf("  ��      ��  ��      ��  ����    �����  ");
	gotoxy(26, 18);
	printf("  ��      ��  ��      ��  ��        ��      ��");
	gotoxy(26, 19);
	printf("  ��      ��    ��  ��    ��        ��      ��");
	gotoxy(26, 20);
	printf("    ����        ��      �����  ��      ��");
	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);		//������ ������� ���� (�ʱ�ȭ)
	gotoxy(42, 27);		//39, 25 ��ǥ�̵�
	printf("Your Score : 0");	//���� ���	(�������� �� ����)

	Sleep(2000);		//3�ʵ��� ����

	gotoxy(36, 30);		//39, 25 ��ǥ�̵�
	printf("Press any key to go to menu");	//���� ���

	while (kbhit()) getch();	//���� �ʱ�ȭ
	getch();	//����ڰ� Ű�� �Է��Ҷ����� ���

}
