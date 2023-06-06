#include "data.h"	//data.h ��� ������ ���α׷��� ���Խ�Ű�� ���� �ڵ�

#define HOST "127.0.0.1"		// MySQL ������ ȣ��Ʈ �ּ�
#define NAME "tetris_rank"		// ������ �����ͺ��̽��� �̸�
#define USER "root"				// MySQL ������ ������ �� ����� ����� �̸�
#define PASS "abc123"			// MySQL ������ ������ �� ����� ��й�ȣ
#define PORT 3308				// MySQL ������ ���� ���� ��Ʈ ��ȣ

int checkRank(int score) {		//�� ���ڵ����� Ȯ���ϴ� �Լ� checkRank
	MYSQL connect;		// MySQL ���� ��ü �ʱ�ȭ
	MYSQL* connection;  // ���� �����ͺ��̽� ���� ������
	MYSQL_RES* result;  // ���� ����� �����ϱ� ���� ��ü
	MYSQL_ROW row;		// ��������� ���� ��Ÿ���� ��ü

	mysql_init(&connect);	// MySQL ���� �ʱ�ȭ

	connection = mysql_real_connect(&connect, HOST, USER, PASS, NAME, PORT, NULL, 0);	// ���� �����ͺ��̽��� ���� ����
	if (connection == NULL) {		// ���ῡ ������ ���
		fprintf(stderr, "���� : %s\n", mysql_error(&connect));	//���� �޽��� ���
	}

	mysql_query(&connect, "select * from rank order by score desc limit 10");	// ���� 10���� ������ ��� ���� ���� ����

	result = mysql_store_result(connection);	// ���� ��� ����

	int num_rows = mysql_num_rows(result);	// ����� �� ���� ���
	
	if (num_rows < 10) {	// ���� ����� �� ������ 10�� �̸��̸�
		return 1;	//������ ���� 10�� �ȿ� ���
	}
	else {
		mysql_query(&connect, "select score FROM rank order by score desc limit 9, 1");		// 10��° ������ ��� ���� ���� ����
		result = mysql_store_result(connection);	// ���� ��� ����
		row = mysql_fetch_row(result);	// ������� ù �� ���
		if (score > atoi(row[0])) {		// ������ 10��° �������� ������
			return 1;		//������ ���� 10�� �ȿ� ���
		}
		else {		//�ƴϸ�
			return 0;		//���� 10�� �ȿ� ���� ����
		}
	}
}

void insertRank(char id[], int score) {		//���� �Է��ϴ� �Լ� insertRank
	MYSQL connect;		// MySQL ���� ��ü �ʱ�ȭ
	MYSQL* connection;	// ���� �����ͺ��̽� ���� ������

	mysql_init(&connect);	// MySQL ���� �ʱ�ȭ

	connection = mysql_real_connect(&connect, HOST, USER, PASS, NAME, PORT, NULL, 0);	// ���� �����ͺ��̽��� ���� ����
	if (connection == NULL) {		// ���ῡ ������ ���
		fprintf(stderr, "���� : %s\n", mysql_error(&connect));	//���� �޽��� ���
	}

	char sql_query[100];	// ������ SQL ���� ����
	sprintf(sql_query, "insert into rank (id, score) values ('%s', %d)", id, score);	//�Է��� �̴ϼ�, �޼��� ������ rank���̺� ����

	mysql_query(&connect, sql_query);	// ���� ����
}


void showRank() {	// ��ŷ ������ ȭ�鿡 ǥ���ϴ� �Լ� showRank
	MYSQL connect;		// MySQL ���� ��ü �ʱ�ȭ
	MYSQL* connection;  // ���� �����ͺ��̽� ���� ������
	MYSQL_RES* result;  // ���� ����� �����ϱ� ���� ��ü
	MYSQL_ROW row;		// ��������� ���� ��Ÿ���� ��ü

	int x = 16;		//x��ǥ�� �������� x ����
	int y = 16;		//y��ǥ�� �������� y ����
	int num = 1;	//��ŷ ��ȣ�� ǥ������ num ����

	mysql_init(&connect);	// MySQL ���� �ʱ�ȭ

	connection = mysql_real_connect(&connect, HOST, USER, PASS, NAME, PORT, NULL, 0);	// ���� �����ͺ��̽��� ���� ����
	if (connection == NULL) {		// ���ῡ ������ ���
		fprintf(stderr, "���� : %s\n", mysql_error(&connect));	//���� �޽��� ���
	}

	mysql_query(&connect, "select * from rank order by score desc limit 10");	// ���� 10���� ������ ��� ���� ���� ����

	result = mysql_store_result(connection);	// ���� ��� ����

	// ��ŷ ǥ�ÿ� ���� UI ��� �׸���
	printR(30, 1);
	printA(38, 1);
	printN(50, 1);
	printK(62, 1);

	//��� �� ����
	gotoxy(6, 7);
	printf("----------------------------------------------------------------------------------------\n");


	int num_rows = mysql_num_rows(result);	//sql�� ����� �������� ����


	if (num_rows == 0) {	//��ŷ ������ ���� ���
		gotoxy(39, 20);		//��ŷ�� ���ٴ� ��Ʈ ���
		printf("���� ��ŷ�� �����ϴ�.");
		gotoxy(32, 22);
		printf("������ ������ ��ŷ�� �����غ�����!");
	}
	else { // ��ŷ ������ �ִ� ���
		gotoxy(15, 9);	//��ܿ� Rank, ID, Score ���� ���
		printf("Rank");	
		gotoxy(47, 9);
		printf("I D");
		gotoxy(78, 9);
		printf("Score");
		gotoxy(6, 11);
		printf("----------------------------------------------------------------------------------------\n");
		while ((row = mysql_fetch_row(result)) != NULL) {	//��� ��ŷ �������� �޾ƿ�
			gotoxy(x, y);		//16, 16��
			printf("%-30d %-30s %s\n", num, row[0], row[1]);	//��ŷ �������� ǥ��
			num++;		//num 1�� ����
			y = y + 2;	//y��ǥ 2�� ����
		}
	}
	gotoxy(72, 38);		//72, 38 ��ġ��
	printf("Press any key to exit");	//���� ���
	gotoxy(6, 39);	//�Ʒ� �� ���
	printf("----------------------------------------------------------------------------------------\n");

	mysql_close(&connect);	// MySQL ���� ����

	while (kbhit()) getch();	//���� �ʱ�ȭ
	getch();	//����ڰ� Ű�� �Է��Ҷ����� ���
}