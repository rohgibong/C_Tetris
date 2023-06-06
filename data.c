#include "data.h"	//data.h 헤더 파일을 프로그램에 포함시키기 위한 코드

#define HOST "127.0.0.1"		// MySQL 서버의 호스트 주소
#define NAME "tetris_rank"		// 연결할 데이터베이스의 이름
#define USER "root"				// MySQL 서버에 연결할 때 사용할 사용자 이름
#define PASS "abc123"			// MySQL 서버에 연결할 때 사용할 비밀번호
#define PORT 3308				// MySQL 서버가 실행 중인 포트 번호

int checkRank(int score) {		//뉴 레코드인지 확인하는 함수 checkRank
	MYSQL connect;		// MySQL 연결 객체 초기화
	MYSQL* connection;  // 실제 데이터베이스 연결 포인터
	MYSQL_RES* result;  // 쿼리 결과를 저장하기 위한 객체
	MYSQL_ROW row;		// 결과에서의 행을 나타내는 객체

	mysql_init(&connect);	// MySQL 연결 초기화

	connection = mysql_real_connect(&connect, HOST, USER, PASS, NAME, PORT, NULL, 0);	// 실제 데이터베이스와 연결 설정
	if (connection == NULL) {		// 연결에 실패한 경우
		fprintf(stderr, "에러 : %s\n", mysql_error(&connect));	//에러 메시지 출력
	}

	mysql_query(&connect, "select * from rank order by score desc limit 10");	// 상위 10개의 점수를 얻기 위한 쿼리 실행

	result = mysql_store_result(connection);	// 쿼리 결과 저장

	int num_rows = mysql_num_rows(result);	// 결과의 행 개수 계산
	
	if (num_rows < 10) {	// 만약 결과의 행 개수가 10개 미만이면
		return 1;	//점수가 상위 10개 안에 든다
	}
	else {
		mysql_query(&connect, "select score FROM rank order by score desc limit 9, 1");		// 10번째 점수를 얻기 위한 쿼리 실행
		result = mysql_store_result(connection);	// 쿼리 결과 저장
		row = mysql_fetch_row(result);	// 결과에서 첫 행 얻기
		if (score > atoi(row[0])) {		// 점수가 10번째 점수보다 높으면
			return 1;		//점수가 상위 10개 안에 든다
		}
		else {		//아니면
			return 0;		//상위 10개 안에 들지 않음
		}
	}
}

void insertRank(char id[], int score) {		//점수 입력하는 함수 insertRank
	MYSQL connect;		// MySQL 연결 객체 초기화
	MYSQL* connection;	// 실제 데이터베이스 연결 포인터

	mysql_init(&connect);	// MySQL 연결 초기화

	connection = mysql_real_connect(&connect, HOST, USER, PASS, NAME, PORT, NULL, 0);	// 실제 데이터베이스와 연결 설정
	if (connection == NULL) {		// 연결에 실패한 경우
		fprintf(stderr, "에러 : %s\n", mysql_error(&connect));	//에러 메시지 출력
	}

	char sql_query[100];	// 삽입할 SQL 쿼리 생성
	sprintf(sql_query, "insert into rank (id, score) values ('%s', %d)", id, score);	//입력한 이니셜, 달성한 점수를 rank테이블에 삽입

	mysql_query(&connect, sql_query);	// 쿼리 실행
}


void showRank() {	// 랭킹 정보를 화면에 표시하는 함수 showRank
	MYSQL connect;		// MySQL 연결 객체 초기화
	MYSQL* connection;  // 실제 데이터베이스 연결 포인터
	MYSQL_RES* result;  // 쿼리 결과를 저장하기 위한 객체
	MYSQL_ROW row;		// 결과에서의 행을 나타내는 객체

	int x = 16;		//x좌표를 지정해줄 x 선언
	int y = 16;		//y좌표를 지정해줄 y 선언
	int num = 1;	//랭킹 번호를 표시해줄 num 선언

	mysql_init(&connect);	// MySQL 연결 초기화

	connection = mysql_real_connect(&connect, HOST, USER, PASS, NAME, PORT, NULL, 0);	// 실제 데이터베이스와 연결 설정
	if (connection == NULL) {		// 연결에 실패한 경우
		fprintf(stderr, "에러 : %s\n", mysql_error(&connect));	//에러 메시지 출력
	}

	mysql_query(&connect, "select * from rank order by score desc limit 10");	// 상위 10개의 점수를 얻기 위한 쿼리 실행

	result = mysql_store_result(connection);	// 쿼리 결과 저장

	// 랭킹 표시에 대한 UI 요소 그리기
	printR(30, 1);
	printA(38, 1);
	printN(50, 1);
	printK(62, 1);

	//상단 줄 생성
	gotoxy(6, 7);
	printf("----------------------------------------------------------------------------------------\n");


	int num_rows = mysql_num_rows(result);	//sql문 결과가 몇줄인지 저장


	if (num_rows == 0) {	//랭킹 정보가 없는 경우
		gotoxy(39, 20);		//랭킹이 없다는 멘트 출력
		printf("현재 랭킹이 없습니다.");
		gotoxy(32, 22);
		printf("게임을 시작해 랭킹에 도전해보세요!");
	}
	else { // 랭킹 정보가 있는 경우
		gotoxy(15, 9);	//상단에 Rank, ID, Score 문구 출력
		printf("Rank");	
		gotoxy(47, 9);
		printf("I D");
		gotoxy(78, 9);
		printf("Score");
		gotoxy(6, 11);
		printf("----------------------------------------------------------------------------------------\n");
		while ((row = mysql_fetch_row(result)) != NULL) {	//모든 랭킹 정보들을 받아옴
			gotoxy(x, y);		//16, 16에
			printf("%-30d %-30s %s\n", num, row[0], row[1]);	//랭킹 정보들을 표시
			num++;		//num 1씩 증가
			y = y + 2;	//y좌표 2씩 증가
		}
	}
	gotoxy(72, 38);		//72, 38 위치에
	printf("Press any key to exit");	//문구 출력
	gotoxy(6, 39);	//아래 줄 출력
	printf("----------------------------------------------------------------------------------------\n");

	mysql_close(&connect);	// MySQL 연결 종료

	while (kbhit()) getch();	//버퍼 초기화
	getch();	//사용자가 키를 입력할때까지 대기
}