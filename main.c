#pragma warning(disable:4996)	//getch & kbhit 오류 제거
#include "block.h"	 //block 헤더파일 불러오기
#include "screen.h"	 //screen 헤더파일 불러오기
#include "data.h"	 //data 헤더파일 불러오기
						
int main() {
	int speed;				//난이도별 속도를 정하기 위한 정수 speed 선언
	int num = 0;			//난이도를 선택받기 위한 정수 num 선언
	extern int score;		//외부에서 점수를 받아오기 위해 extern으로 score 정수 선언
	while (1) {				//난이도를 선택받을동안 반복
		clock_t starttime = 0;	//프로그램 실행 시간 담기위한 starttime 선언
		clock_t endtime = 0;	//프로그램 실행 시간 담기위한 endtime 선언
		int speednum = 0;		//스피드가 올라간지 확인하기 위한 정수 speednum 선언
		num = startPage();		//startPage에서 난이도를 선택받음
		if (num == 1) {			//num(난이도)이 1일 때
			speed = 30;			//speed에 30을 줌
		}
		else if (num == 2) {	//num(난이도)이 2일 때
			speed = 20;			//speed에 20을 줌
		}
		else if (num == 3) {	//num(난이도)이 3일 때
			speed = 10;			//speed에 10을 줌
		}
		else if (num == 4) {	//랭킹 보기를 선택했을 때
			showRank();			//랭크를 보여줌
			continue;			//계속 반복
		}
		else if (num == 5) {	//게임 종료를 선택했을 때
			return 0;			//0 리턴
		}
		else {					//그 외에는
			continue;			//계속 반복
		}
		screenLine();	//화면 전체 라인을 출력하는 함수 호출
		boardLine();	//게임보드 라인을 출력하는 함수 호출
		gameBlockSet();	//경계선을 지정하는 함수 호출
		blockSetWall();	//다음 나올 블럭들을 보여주는 곳 UI를 출력하는 함수 호출
		guideWall();	//조작키 UI 라인을 출력하는 함수 호출
		printGuideMent();	//조작키 UI 내용을 출력하는 함수 호출

		changeac(blockRand());		//첫 활성화 될 블럭 지정		(최초에 선언 할수록 대기 블럭 5번째에서 4번째 3번째 .. 점점 앞으로 당겨져서
		changeac(blockRand());		//처음 대기 블럭 5개 지정		 총 6번을 해줘야 첫 활설화 될 블럭과 대기 블럭 5개를 만들어 줄 수 있음)
		changeac(blockRand());		//처음 대기 블럭 5개 지정 
		changeac(blockRand());		//처음 대기 블럭 5개 지정 
		changeac(blockRand());		//처음 대기 블럭 5개 지정 
		changeac(blockRand());		//처음 대기 블럭 5개 지정
		gotoxy(10, 7);				//10, 7 지점에
		printf("SCORE : %d", score);	//score를 출력

		starttime = clock();	//게임을 시작했을 때 시간을 담음
		while (1) {		//게임이 실행되는 동안 무한으로 반복. 게임 종료 조건 만족 시 나가게 됨
			currentBlock = setColor(playBlock);	//playBlock(활성화 된 블럭)을 setColor함수에 넣게되면 블럭 모양에 맞는 색깔 코드(정수)를 리턴하게됨. 그 수를 currentBlock에 저장
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), currentBlock);		//위에서 받은 색깔 코드를 통해 색 지정
			moveBlock(speed);			//1초간격으로 블럭이 하강하는 함수 호출
			setGameBlock();			//현재 떨어지고 있는 테트리스 블록을 게임 화면에 추가하는 함수 호출
			scanGameBlock();		//줄이 완성되었는지 확인하기 위한 함수 호출
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	//색깔을 다시 흰색으로 되돌림
			gotoxy(10, 7);				//10, 7 지점에
			printf("SCORE : %d", score);	//score를 출력 (업데이트)

			endtime = clock();		//게임이 경과된 시간을 endtime에 담음
			if (endtime - starttime >= 60000 && speednum == 0) {	//게임 실행 시간 1분이 경과됐고, 속도가 한번도 오르지 않았을 때
				if (num == 1) {		//난이도가 easy이면,
					speed -= 5;		//속도를 10ms * 5 만큼 더 빠르게 변경
				}
				else if (num == 2) {		//난이도가 normal이면,
					speed -= 5;		//속도를 10ms * 5 만큼 더 빠르게 변경
				}
				else if (num == 3) {		//난이도가 hard이면,
					speed -= 2;		//속도를 10ms * 2 만큼 더 빠르게 변경
				}
				speednum++;		//속도가 증가했다는 표시
				gotoxy(25, 7);	//25, 7 지점에
				printf("Speed UP!");	//Speed Up! 문구 출력
			}
			else if (endtime - starttime >= 120000 && speednum == 1) {	//게임 실행 시간 2분이 경과됐고, 속도가 한번 올랐을 때
				if (num == 1) {		//난이도가 easy이면,
					speed -= 5;		//속도를 10ms * 5 만큼 더 빠르게 변경
				}
				else if (num == 2) {		//난이도가 normal이면,
					speed -= 5;		//속도를 10ms * 5 만큼 더 빠르게 변경
				}
				else if (num == 3) {		//난이도가 hard이면,
					speed -= 2;		//속도를 10ms * 2 만큼 더 빠르게 변경
				}
				speednum++;		//속도가 증가했다는 표시
				gotoxy(25, 7);	//25, 7 지점에
				printf("Speed UP!!");	//Speed Up!! 문구 출력
			}
			else if (endtime - starttime >= 180000 && speednum == 2) {	//게임 실행 시간 3분이 경과됐고, 속도가 두번 올랐을 때
				if (num == 1) {		//난이도가 easy이면,
					speed -= 3;		//속도를 10ms * 3 만큼 더 빠르게 변경
				}
				else if (num == 2) {		//난이도가 normal이면,
					speed -= 3;		//속도를 10ms * 3 만큼 더 빠르게 변경
				}
				else if (num == 3) {		//난이도가 hard이면,
					speed -= 2;		//속도를 10ms * 2 만큼 더 빠르게 변경
				}
				speednum++;		//속도가 증가했다는 표시
				gotoxy(25, 7);	//25, 7 지점에
				printf("Speed UP!!!");	//Speed Up!!! 문구 출력
			}
			if (scanGameOver() == 1) {	//게임오버됐는지 확인하기 위한 함수 호출
				break;		//게임오버가 됐으면 while문을 빠져나감
			}

			changeac(blockRand());	//대기중인 블럭 한칸씩 앞으로 당기는 함수 호출
		}
		gameOverPage();		//게임오버 화면을 띄우는 함수
	}

	return 0;	//main함수 리턴값을 0을 줌으로써, 프로그램이 정상적으로 종료되었음을 의미
}

