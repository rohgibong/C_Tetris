#include "data.h"

#define HOST "127.0.0.1"
#define NAME "tetris_rank"
#define USER "root"
#define PASS "abc123"
#define PORT 3308

int checkRank(int score) {
	MYSQL connect;		//connect 변수
	MYSQL* connection;
	MYSQL_RES* result;
	MYSQL_ROW row;

	mysql_init(&connect);

	connection = mysql_real_connect(&connect, HOST, USER, PASS, NAME, PORT, NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "에러 : %s\n", mysql_error(&connect));
	}

	mysql_query(&connect, "select * from rank order by score desc limit 10");

	result = mysql_store_result(connection);

	int num_rows = mysql_num_rows(result);
	
	if (num_rows < 10) {
		return 1;
	}
	else {
		mysql_query(&connect, "select score FROM rank order by score desc limit 9, 1");
		result = mysql_store_result(connection);
		row = mysql_fetch_row(result);
		if (score > atoi(row[0])) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

void insertRank(char id[], int score) {
	MYSQL connect;
	MYSQL* connection;

	mysql_init(&connect);

	connection = mysql_real_connect(&connect, HOST, USER, PASS, NAME, PORT, NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "에러 : %s\n", mysql_error(&connect));
	}

	char sql_query[100];
	sprintf(sql_query, "insert into rank (id, score) values ('%s', %d)", id, score);

	mysql_query(&connect, sql_query);
}


void showRank() {
	MYSQL connect;		//connect 변수
	MYSQL* connection;
	MYSQL_RES* result;
	MYSQL_ROW row;

	int x = 16;
	int y = 16;
	int num = 1;

	mysql_init(&connect);

	connection = mysql_real_connect(&connect, HOST, USER, PASS, NAME, PORT, NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "에러 : %s\n", mysql_error(&connect));
	}

	mysql_query(&connect, "select * from rank order by score desc limit 10");

	result = mysql_store_result(connection);

	printR(30, 1);
	printA(38, 1);
	printN(50, 1);
	printK(62, 1);

	gotoxy(6, 7);
	printf("----------------------------------------------------------------------------------------\n");

	int num_rows = mysql_num_rows(result);

	if (num_rows == 0) {
		gotoxy(39, 20);
		printf("현재 랭킹이 없습니다.");
		gotoxy(32, 22);
		printf("게임을 시작해 랭킹에 도전해보세요!");
	}
	else {
		gotoxy(15, 9);
		printf("Rank");
		gotoxy(47, 9);
		printf("I D");
		gotoxy(78, 9);
		printf("Score");
		gotoxy(6, 11);
		printf("----------------------------------------------------------------------------------------\n");
		while ((row = mysql_fetch_row(result)) != NULL) {
			gotoxy(x, y);
			printf("%-30d %-30s %s\n", num, row[0], row[1]);
			num++;
			y = y + 2;
		}
	}
	gotoxy(72, 38);
	printf("Press any key to exit");
	gotoxy(6, 39);
	printf("----------------------------------------------------------------------------------------\n");

	mysql_close(&connect);

	while (kbhit()) getch();	//버퍼 초기화
	getch();	//사용자가 키를 입력할때까지 대기
}