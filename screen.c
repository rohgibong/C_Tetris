#include "screen.h"	//screen.h 헤더 파일을 프로그램에 포함시키기 위한 코드
int score;

void gotoxy(int x, int y) {//gotoxy : 커서 위치를 변경하여 화면 상에서 출력 위치를 이동시키는 함수
	COORD pos = { x,y };	//gotoxy 함수 내부에서는 COORD 구조체를 사용하여 커서의 위치를 지정
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);		//SetConsoleCursorPosition 함수를 사용하여 커서의 위치를 지정하고 GetStdHandle 함수를 사용하여 표준 출력 스트림 핸들을 가져옴
}

void printT(int x, int y) {		//메인 화면 T 출력
	gotoxy(x, y);     printf("■■■■■");	//T를 만들기 위한 ■ 출력
	gotoxy(x, y + 1); printf("    ■  ");	//T를 만들기 위한 ■ 출력
	gotoxy(x, y + 2); printf("    ■  ");	//T를 만들기 위한 ■ 출력
	gotoxy(x, y + 3); printf("    ■  ");	//T를 만들기 위한 ■ 출력
	gotoxy(x, y + 4); printf("    ■  ");	//T를 만들기 위한 ■ 출력
}
void printE(int x, int y) {		//메인 화면 E 출력
	gotoxy(x, y);     printf("■■■■");	//E를 만들기 위한 ■ 출력
	gotoxy(x, y + 1); printf("■  ");	//E를 만들기 위한 ■ 출력
	gotoxy(x, y + 2); printf("■■■■");	//E를 만들기 위한 ■ 출력
	gotoxy(x, y + 3); printf("■  ");	//E를 만들기 위한 ■ 출력
	gotoxy(x, y + 4); printf("■■■■");	//E를 만들기 위한 ■ 출력
}
void printR(int x, int y) {		//메인,랭킹 화면 R 출력
	gotoxy(x, y);     printf("■■■    ");	//R을 만들기 위한 ■ 출력
	gotoxy(x, y + 1); printf("■    ■  ");	//R을 만들기 위한 ■ 출력
	gotoxy(x, y + 2); printf("■■■ ");	//R을 만들기 위한 ■ 출력
	gotoxy(x, y + 3); printf("■    ■  ");	//R을 만들기 위한 ■ 출력
	gotoxy(x, y + 4); printf("■    ■");	//R을 만들기 위한 ■ 출력

}
void printI(int x, int y) {		//메인 화면 I 출력
	gotoxy(x, y);     printf("■■■■■");	//I를 만들기 위한 ■ 출력
	gotoxy(x, y + 1); printf("    ■");	//I를 만들기 위한 ■ 출력
	gotoxy(x, y + 2); printf("    ■ ");	//I를 만들기 위한 ■ 출력
	gotoxy(x, y + 3); printf("    ■");	//I를 만들기 위한 ■ 출력
	gotoxy(x, y + 4); printf("■■■■■");	//I를 만들기 위한 ■ 출력

}
void printS(int x, int y) {		//메인 화면 S 출력
	gotoxy(x, y);     printf("  ■■■■");	//S를 만들기 위한 ■ 출력
	gotoxy(x, y + 1); printf("■");	//S를 만들기 위한 ■ 출력
	gotoxy(x, y + 2); printf("  ■■■  ");	//S를 만들기 위한 ■ 출력
	gotoxy(x, y + 3); printf("        ■");	//S를 만들기 위한 ■ 출력
	gotoxy(x, y + 4); printf("■■■■  ");	//S를 만들기 위한 ■ 출력
}
void printA(int x, int y) {		//랭킹 화면 A 출력
	gotoxy(x, y);     printf("    ■■   ");	//A를 만들기 위한 ■ 출력
	gotoxy(x, y + 1); printf("  ■    ■");	//A를 만들기 위한 ■ 출력
	gotoxy(x, y + 2); printf("  ■■■■");	//A를 만들기 위한 ■ 출력
	gotoxy(x, y + 3); printf("  ■    ■");	//A를 만들기 위한 ■ 출력
	gotoxy(x, y + 4); printf("  ■    ■");	//A를 만들기 위한 ■ 출력
}
void printN(int x, int y) {		//메인 화면 N 출력
	gotoxy(x, y);     printf("■      ■");	//N를 만들기 위한 ■ 출력
	gotoxy(x, y + 1); printf("■■    ■");	//N를 만들기 위한 ■ 출력
	gotoxy(x, y + 2); printf("■  ■  ■");	//N를 만들기 위한 ■ 출력
	gotoxy(x, y + 3); printf("■    ■■");	//N를 만들기 위한 ■ 출력
	gotoxy(x, y + 4); printf("■      ■");	//N를 만들기 위한 ■ 출력
}
void printK(int x, int y) {		//메인 화면 K 출력
	gotoxy(x, y);     printf("■    ■ ");	//K를 만들기 위한 ■ 출력
	gotoxy(x, y + 1); printf("■  ■");	//K를 만들기 위한 ■ 출력
	gotoxy(x, y + 2); printf("■■");	//K를 만들기 위한 ■ 출력
	gotoxy(x, y + 3); printf("■  ■");	//K를 만들기 위한 ■ 출력
	gotoxy(x, y + 4); printf("■    ■");	//K를 만들기 위한 ■ 출력
}

void cursorview() {		//커서를 보이지 않게 하는 함수
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };		//커서의 속성 정보를 저장하는데 사용되는 구조체 변수 cursorInfo를 선언하고 초기화
	cursorInfo.dwSize = 1;			//커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE;	//커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);		//SetConsoleCursorInfo 함수를 사용하여 커서의 정보를 설정
}

int selectLevel() {			//난이도 선택 함수 selectLevel
	int CursorS = 18;		//커서의 y좌표 위치 18로 선언
	int i = 0;				//반복문을 돌기 위한 정수 i 선언
	int num = 0;			//'>>'를 찍기 위한 정수 num 선언
	gotoxy(39, 18);			//39, 18 지점에
	printf("Easy");			//Easy 문구 출력
	gotoxy(39, 20);			//39, 18 지점에
	printf("Normal");		//Normal 문구 출력
	gotoxy(39, 22);			//39, 22 지점에
	printf("Hard");			//Hard 문구 출력
	gotoxy(39, 24);			//39, 24 지점에
	printf("Exit");			//Exit 문구 출력
	gotoxy(36, 18);			//36, 18 지점에
	printf(">>");			//>> 문구 출력
	while (1) {			//계속 반복
		for (i = 0; i < 10; i++) {	//반짝이는걸 반복하기 위해 반복문을 추가
			if (kbhit()) {		//키보드 입력을 받았을 때
				int input = getch();	//input에 입력받은 키보드를 저장
				if (input == 13 || input == 32) {		//엔터키, 스페이스바를 입력 했을 때
					if (CursorS == 18) {	//커서의 y위치가 18일 경우
						for (i = 0; i < 5; i++) {		//선택시 문구가 반짝거림
							gotoxy(39, 18);			//39, 18 지점에
							printf("        ");		//공백 출력
							Sleep(100);				//100ms 대기 후
							gotoxy(39, 18);			//39, 18 지점에
							printf("Easy");			//Easy 문구 출력
							Sleep(100);				//100ms 대기
						}
						system("cls");			//화면 초기화
						return 1;				//1 리턴
					}

					else if (CursorS == 20) {	//커서의 y위치가 20일 경우
						for (i = 0; i < 5; i++) {		//선택시 반짝거림 
							gotoxy(39, 20);			//39, 20 지점에
							printf("       ");		//공백 출력
							Sleep(100);				//100ms 대기 후
							gotoxy(39, 20);			//39, 20 지점에
							printf("Normal");			//Normal 문구 출력
							Sleep(100);				//100ms 대기
						}
						system("cls");			//화면 초기화
						return 2;				//1 리턴
					}

					else if (CursorS == 22) {	//커서의 y위치가 22일 경우
						for (i = 0; i < 5; i++) {		//선택시 반짝거림 
							gotoxy(39, 22);			//39, 22 지점에
							printf("      ");		//공백 출력
							Sleep(100);				//100ms 대기
							gotoxy(39, 22);			//39, 22 지점에
							printf("Hard");			//Hard 문구 출력
							Sleep(100);				//100ms 대기
						}
						system("cls");			//화면 초기화
						return 3;				//3 리턴
					}

					else {		//그 외에
						return 0;	//0 리턴
					}
				}

				else if (input == 224) {	//방향키를 입력 받았을 때
					input = getch();	// 다시 getch()를 호출하여 실제 방향키의 값을 받아옴

					switch (input) {
						case 72: {		//방향키 위 입력받았을 때
							gotoxy(36, CursorS);    // 커서를 현재 위치로 이동
							printf("  ");		//공백 출력
							if (CursorS != 18)	// 현재 위치가 최상단이 아니라면
								CursorS = CursorS - 2;	// 커서를 위로 2칸 이동
							else	// 현재 위치가 최상단 이라면
								CursorS = 24;	//커서를 최하단으로 이동
							break;
						}

						case 80: {		//방향키 아래 입력받았을 때
							gotoxy(36, CursorS);    // 커서를 현재 위치로 이동
							printf("  ");		//공백 출력
							if (CursorS != 24)	// 현재 위치가 최하단이 아니라면
								CursorS = CursorS + 2;	//커서를 아래로 2칸 이동
							else	// 현재 위치가 최하단이라면
								CursorS = 18;	//커서를 최상단으로 이동
							break;
						}
					}
				}
			}
			Sleep(10);	//10밀리초동안 스레드를 일시 정지 (반짝이는 효과를 추가하기 위해)
		}

		if (num == 0) {    //커서가 비활성화 상태일 경우
			gotoxy(36, CursorS);    // 커서 위치로 이동
			printf(">>");    // 커서를 화면에 표시
			num = 1;    // 커서를 활성화 상태로 바꿈
		}

		else {    //커서가 활성화 상태일 경우
			gotoxy(36, CursorS);    // 커서 위치로 이동
			printf("  ");   // 화면에 표시된 커서를 지움
			num = 0;    // 커서를 비활성화 상태로 바꿈
		}
	}
}

int startPage() {		//startPage 함수 (실행 첫 화면을 띄우기 위한 함수)
	int CursorS = 21;		//커서의 y좌표 위치 21로 선언
	int i = 0;				//반복문을 돌기 위한 정수 i 선언
	int num = 0;			//'>>'를 찍기 위한 정수 num 선언
	srand(time(NULL));	//srand를 사용하여 난수 발생기의 초기 시드 값을 설정하는 코드, 시드 값을 매번 다르게 설정함으로써 다양한 난수를 생성함
	system("mode con cols=100 lines=41");	//Windows 운영체제에서 콘솔 창의 크기를 변경하는 명령, 가로 100칸, 세로 41칸으로 지정
	cursorview();	//커서를 보이지 않게 하는 함수 호출
	SetConsoleTitle(TEXT("Tetris (1906125 노기봉)"));	//콘솔창 이름을 Tetris (1906125 노기봉) 으로 지정
	
	system("cls");		//화면 초기화
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);		//색상을 빨간색으로 지정
	printT(11, 8);		//T 출력
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);		//색상을 주황색으로 지정
	printE(25, 8);		//E 출력
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);		//색상을 노란색으로 지정
	printT(38, 8);		//T 출력
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);		//색상을 초록색으로 지정
	printR(52, 8);		//R 출력
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);		//색상을 하늘색으로 지정
	printI(65, 8);		//I 출력
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);		//색상을 보라색으로 지정
	printS(80, 8);		//S 출력
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);		//색상을 흰색으로 지정 (초기화)

	gotoxy(42, 21);		//42, 21 좌표이동
	printf("1. 게임 시작");	//문구 출력
	gotoxy(42, 24);		//42, 24 좌표이동
	printf("2. 랭킹 확인");	//문구 출력
	gotoxy(42, 27);		//42, 27 좌표이동
	printf("3. 게임 종료");	//문구 출력
	gotoxy(39, 21);			//39, 21 지점에
	printf(">>");			//>> 문구 출력
	gotoxy(80, 32);		//80, 32 좌표이동
	printf("c응용 프로젝트");		//문구 출력
	gotoxy(68, 33);		//68, 33 좌표이동
	printf("소프트웨어콘텐츠 2학년 2반");
	gotoxy(80, 34);		//80, 34 좌표이동
	printf("1906125 노기봉");	//문구 출력
	gotoxy(29, 38);		//29, 38 좌표이동
	printf("영남이공대학교 Yeungnam University College");	//문구 출력

	while (1) {			//계속 반복
		for (i = 0; i < 10; i++) {	//반짝이는걸 반복하기 위해 반복문을 추가
			if (kbhit()) {		//키보드 입력을 받았을 때
				int input = getch();	//input에 입력받은 키보드를 저장
				if (input == 13 || input == 32) {		//엔터키를 입력 했을 때
					if (CursorS == 21) {	//커서의 y위치가 21일 경우
						system("cls");			//화면 초기화
						return(selectLevel());			//selectLevel로 가게 됨
					}

					else if (CursorS == 24) {	//커서의 y위치가 24일 경우
						system("cls");			//화면 초기화
						return 4;		//4 리턴
					}

					else if (CursorS == 27) {	//커서의 y위치가 27일 경우
						system("cls");			//화면 초기화
						return 5;		//5 리턴
					}
				}

				else if (input == 224) { // 방향키가 눌렸을 때
					input = getch();	//input에 입력받은 키보드를 저장

					switch (input) {
					case 72: {		//위 방향키일때
						gotoxy(39, CursorS); // 커서 위치로 이동
						printf("  ");	// 화면에 표시된 커서를 지움
						if (CursorS != 21)	// 만약 커서의 y 좌표가 21이 아니라면
							CursorS = CursorS - 3;	// 커서의 y 좌표를 위로 이동
						else	// 만약 커서의 y 좌표가 21이라면
							CursorS = 27;	// 커서의 y 좌표를 최하단으로 이동
						break;
					}

					case 80: {		//아래 방향키일때
						gotoxy(39, CursorS); // 커서 위치로 이동
						printf("  ");	// 화면에 표시된 커서를 지움
						if (CursorS != 27)	// 만약 커서의 y 좌표가 27이 아니라면
							CursorS = CursorS + 3;
						else	// 만약 커서의 y 좌표가 27이라면
							CursorS = 21;	// 커서의 y 좌표를 최상단으로 이동
						break;
					}
					}
				}
			}
			Sleep(10);	//10밀리초동안 스레드를 일시 정지 (반짝이는 효과를 추가하기 위해)
		}

		if (num == 0) {		//커서가 비활성화 상태일 경우
			gotoxy(39, CursorS);	// 커서 위치로 이동
			printf(">>");	// 커서를 화면에 표시
			num = 1;	// 커서를 활성화 상태로 바꿈
		}

		else {		//커서가 활성화 상태일 경우
			gotoxy(39, CursorS);	// 커서 위치로 이동
			printf("  ");	// 화면에 표시된 커서를 지움
			num = 0;	// 커서를 비활성화 상태로 바꿈
		}
	}

	getch();	//사용자가 키를 입력하는것을 받기 위해, 키를 입력받으면 밑 반복문 실행

	for (int i = 0; i < 5; i++) { 		//키보드 입력시 반짝거리기 위해 몇번 반짝거릴지 반복 (5번)
		gotoxy(39, 25);		//39, 25 좌표이동
		printf("                      ");	//공백 출력 (위의 Press any key to start 를 가리기 위해)
		Sleep(100);		//0.1초동안 지연
		gotoxy(39, 25);		//39, 25 좌표이동
		printf("Press any key to start");	//문구 출력
		Sleep(100);		//0.1초동안 지연
	}
	system("cls");		//화면 초기화 
	return(selectLevel());
}

void screenLine() {		//screenLine 함수 (화면 전체의 라인을 출력하기 위한 함수)
	for (int i = 0; i < SCREEN_X_SIZE; i++) { //SCREEN_X_SIZE(40) 만큼 반복 (콘솔창 위쪽 벽을 출력하기 위해)
		printf("■");	//반복 돌면서 ■ 찍기
	}
	for (int i = 0; i < SCREEN_Y_SIZE; i++) { //SCREEN_Y_SIZE(40) 만큼 반복 (콘솔창 양쪽 벽을 출력하기 위해)
		gotoxy(0, i + 1);	//커서 위치를 (0, i+1)로 이동
		printf("■");		//반복 돌면서 ■ 찍기
		gotoxy((SCREEN_X_SIZE*2)-2, i);		//커서 위치를 (98, i)로 이동
		printf("■");		//반복 돌면서 ■ 찍기
	}

	gotoxy(0, SCREEN_Y_SIZE);	//커서 위치를 (0, 40)으로 이동

	for (int i = 0; i < SCREEN_X_SIZE; i++) {	//SCREEN_X_SIZE(50) 만큼 반복 (콘솔창 아래쪽 벽을 출력하기 위해)
		printf("■");	//반복 돌면서 ■ 찍기
	}
}

void boardLine() {	//boardLine 함수	(게임 보드판의 라인을 출력하기 위한 함수)
	for (int i = 0; i < BOARD_Y_SIZE; i++) {	//BOARD_Y_SIZE(24) 만큼 반복 (게임 보드판 양쪽 벽을 출력하기 위해)
		gotoxy(10, i + 10);	//커서 위치를 (10, i+7)으로 이동
		printf("■");		//반복 돌면서 ■ 찍기
		gotoxy(10+(BOARD_X_SIZE*2)-2, i + 10);	//커서 위치를 (32, i+7)으로 이동
		printf("■");		//반복 돌면서 ■ 찍기
	}

	gotoxy(10, 31);		//커서 위치를 (10, 31)로 이동	
	for (int i = 0; i < BOARD_X_SIZE; i++) {	//BOARD_X_SIZE(12) 만큼 반복 (게임 보드판 아래쪽 벽을 출력하기 위해)
		printf("■");	//반복 돌면서 ■ 찍기
	}
}

void gameBlockSet() {			//게임의 경계선을 모두 1로 설정하는 함수
	for (int i = 0; i < 12; i++) {		//맨 아랫줄 벽 만들기 위한 반복문, 12번 반복
		gameblock[24][i] = 1;			//25번째 행에 1 대입
	}
	for (int i = 0; i < 24; i++) {		//양쪽 벽 만들기 위한 반복문, 24번 반복
		gameblock[i][0] = 1;			//가장 왼쪽 벽 1 대입
		for (int j = 1; j < 11; j++) {	//양쪽 벽 제외한 중간 부분
			gameblock[i][j] = 0;	//0 대입
		}
		gameblock[i][11] = 1;			//가장 오른쪽 벽 1 대입
	}
}

void blockSetWall() {	//대기중인 블럭을 보여주는곳 틀을 출력하기 위한 함수
	gotoxy(43, 7);	//43, 7 좌표이동
	printf("N  E  X  T");	//NEXT 문구출력

	for (int i = 0; i < 6; i++) {	//가로선을 출력하기 위해 반복문을 통해 6번 실행
		gotoxy(42, 8 + i * 5);		//42, 8 + i * 5 좌표이동 (5칸씩 띄우기 위해 *5)
		for (int j = 0; j < 11; j++) {	//가로선을 출력하기 위해 그 길이만큼 반복
			if (i == 0 && j == 0) {		//첫번째 줄 첫번째 칸이면
				printf("┌");	//┌ 출력
			}
			else if (i == 0 && j == 10) {	//첫번째 줄 마지막 칸이면
				printf("┐");	//┐ 출력
			}
			else if (i == 5 && j == 0) {	//마지막 줄 첫번째 칸이면
				printf("└");	//└ 출력
			}
			else if (i == 5 && j == 10) {	//마지막 줄 마지막 칸이면
				printf("┘");	//┘ 출력
			}
			else {				//그 외 나머지는
				printf("─");	//─ 출력
			}
		}
	}
	for (int i = 0; i < 24; i++) {	//왼쪽과 오른쪽 틀을 그리기 위해 반복
		gotoxy(42, 9 + i);	//42, 9+i 좌표이동
		printf("│");		//│ 출력
		gotoxy(52, 9 + i);	//52, 9+i 좌표이동
		printf("│");		//│ 출력
	}
}

void guideWall() {		//조작법을 보여주는 곳 틀을 출력하는 함수
	for (int i = 0; i < 2; i++) {	//가장 위, 가장 아래를 출력하기 위해 반복문을 통해 2번 실행
		gotoxy(58, 10 + i * 20);		//58, 10 + i * 20 좌표이동
		for (int j = 0; j < 34; j++) {	//맨 위쪽 틀을 그리기 위해 반복
			if (i == 0 && j == 0) {		//첫번째 줄 첫번째 칸이면
				printf("┌");	//┌ 출력
			}
			else if (i == 0 && j == 33) {	//첫번째 줄 마지막 칸이면
				printf("┐");	//┐ 출력
			}
			else if (i == 1 && j == 0) {	//마지막 줄 첫번째 칸이면
				printf("└");	//└ 출력
			}
			else if (i == 1 && j == 33) {	//마지막 줄 마지막 칸이면
				printf("┘");	//┘ 출력
			}
			else {				//그 외 나머지는
				printf("─");	//─ 출력
			}
		}
		for (int i = 0; i < 19; i++) {	//왼쪽과 오른쪽 틀을 그리기 위해 반복
			gotoxy(58, 11 + i);	//58, 11+i 좌표이동
			printf("│");		//│ 출력
			gotoxy(91, 11 + i);	//91, 11+i 좌표이동
			printf("│");		//│ 출력
		}
	}
}

void printGuideMent() {	//조작법을 보여주는 함수
	gotoxy(67, 12);		//67, 12 좌표이동
	printf("Tetris 조작법");	//문구 출력
	gotoxy(65, 16);		//65, 16 좌표이동
	printf("▲");	//문구 출력
	gotoxy(72, 16);		//72, 16 좌표이동
	printf(": 블럭 회전");	//문구 출력
	gotoxy(61, 18);		//61, 18 좌표이동
	printf("◀");	//문구 출력
	gotoxy(69, 18);		//69, 18 좌표이동
	printf("▶");	//문구 출력
	gotoxy(72, 18);		//72, 18 좌표이동
	printf(": 좌/우 이동");	//문구 출력
	gotoxy(65, 20);		//65, 20 좌표이동
	printf("▼");	//문구 출력
	gotoxy(72, 20);		//72, 20 좌표이동
	printf(": 아래로 이동");	//문구 출력
	gotoxy(65, 23);		//65, 23 좌표이동
	printf("S");	//문구 출력
	gotoxy(72, 23);		//72, 23 좌표이동
	printf(": 왼쪽으로 회전");	//문구 출력
	gotoxy(65, 25);		//65, 25 좌표이동
	printf("D");	//문구 출력
	gotoxy(72, 25);		//72, 25 좌표이동
	printf(": 오른쪽으로 회전");	//문구 출력
	gotoxy(63, 27);
	printf("SPACE");
	gotoxy(72, 27);
	printf(": 하드드랍");
}

int scanGameOver() {		//게임오버됐는지 체크하는 함수
	for (int i = 1; i < 11; i++) {	//가장 윗부분을 반복문 돌면서 확인
		if (gameblock[4][i] != 0)		//0이 아닌부분이 있으면
			return 1;		//1 리턴 (게임오버됨)
	}
}

void gameOverPage() {	//게임오버 됐을 때 출력하는 화면
	system("cls");		//화면 초기화

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);		//색상을 빨간색으로 지정

	gotoxy(26, 6);
	printf("  ■■■      ■■■    ■■      ■■  ■■■■");		//게임 오버 문구 출력
	gotoxy(26, 7);
	printf("■      ■  ■      ■  ■  ■  ■  ■  ■      ");
	gotoxy(26, 8);
	printf("■          ■      ■  ■    ■    ■  ■      ");
	gotoxy(26, 9);
	printf("■      ■  ■■■■■  ■          ■  ■■■■  ");
	gotoxy(26, 10);
	printf("■    ■■  ■      ■  ■          ■  ■      ");
	gotoxy(26, 11);
	printf("■      ■  ■      ■  ■          ■  ■      ");
	gotoxy(26, 12);
	printf("  ■■■    ■      ■  ■          ■  ■■■■");
	gotoxy(26, 13);
	printf("                                                ");
	gotoxy(26, 14);
	printf("    ■■■    ■      ■  ■■■■  ■■■■  ");
	gotoxy(26, 15);
	printf("  ■      ■  ■      ■  ■        ■      ■");
	gotoxy(26, 16);
	printf("  ■      ■  ■      ■  ■        ■      ■");
	gotoxy(26, 17);
	printf("  ■      ■  ■      ■  ■■■    ■■■■  ");
	gotoxy(26, 18);
	printf("  ■      ■  ■      ■  ■        ■      ■");
	gotoxy(26, 19);
	printf("  ■      ■    ■  ■    ■        ■      ■");
	gotoxy(26, 20);
	printf("    ■■■        ■      ■■■■  ■      ■");
	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);		//색상을 흰색으로 지정 (초기화)
	gotoxy(42, 27);		//42, 27 좌표이동
	printf("Your Score : %d", score);	//최종 점수 출력

	Sleep(2000);		//2초동안 지연

	int result = checkRank(score);		//랭킹이 10위안에 드는지 아닌지 확인
	char id = ' ';		//id입력받을 변수 선언
	char initials[10];  // 최대 10개의 문자를 입력받을 수 있는 배열

	if (result == 1) {		//새로운 랭킹일 시에
		while (kbhit()) getch();	//키보드 버퍼 지우기
		gotoxy(44, 26);		//44, 26 위치에
		printf("New Record!!!");	//문구 출력
		gotoxy(28, 32);		//28, 32 위치에
		printf("랭킹에 등록할 이니셜을 입력해주세요: ");	//랭킹 등록하라는 문구 출력
		scanf("%s", initials);  // 최대 9개의 문자를 입력받고, 마지막에 NULL 문자를 자동으로 추가
		insertRank(initials, score);	//입력한 문자와 점수를 등록
	}
	else {
		gotoxy(36, 30);		//36, 30 위치에
		printf("Press any key to go to menu");	//문구 출력
		while (kbhit()) getch();	//키보드 버퍼 지우기
		getch();	//키보드 입력을 받을때 까지 대기
	}

}
