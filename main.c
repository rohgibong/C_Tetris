#pragma warning(disable:4996)	//getch & kbhit 오류 제거
#include "block.h"	 //block 헤더파일 불러오기
#include "screen.h"	 //screen 헤더파일 불러오기
						
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

		while (1) {		//게임이 실행되는 동안 무한으로 반복. 게임 종료 조건 만족 시 나가게 됨
			currentBlock = setColor(playBlock);	//playBlock(활성화 된 블럭)을 setColor함수에 넣게되면 블럭 모양에 맞는 색깔 코드(정수)를 리턴하게됨. 그 수를 currentBlock에 저장
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), currentBlock);		//위에서 받은 색깔 코드를 통해 색 지정
			moveBlock(speed);			//1초간격으로 블럭이 하강하는 함수 호출
			setGameBlock();			//현재 떨어지고 있는 테트리스 블록을 게임 화면에 추가하는 함수 호출
			scanGameBlock();		//줄이 완성되었는지 확인하기 위한 함수 호출
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	//색깔을 다시 흰색으로 되돌림

			if (scanGameOver() == 1) {	//게임오버됐는지 확인하기 위한 함수 호출
				break;		//게임오버가 됐으면 while문을 빠져나감
			}

			changeac(blockRand());	//대기중인 블럭 한칸씩 앞으로 당기는 함수 호출
		}
		gameOverPage();		//게임오버 화면을 띄우는 함수
	}

	return 0;	//main함수 리턴값을 0을 줌으로써, 프로그램이 정상적으로 종료되었음을 의미
}

