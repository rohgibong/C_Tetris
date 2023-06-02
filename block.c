#include "block.h"	//block.h 헤더 파일을 프로그램에 포함시키기 위한 코드

int XSize = 18;			//x값을 설정하는 변수 XSize를 18으로 선언
int YSize = 7;			//y값을 설정하는 변수 YSize를 7으로 선언
int exx = 0;		//미리보기의 이전 x좌표
int exy = 0;		//미리보기의 y좌표
int exPlayBlock[4][4];
int currentNum = 0;		//현재까지 출력된 블럭의 개수 표시
int excurrent;
int score;

int yset() {	//y좌표 계산
	if (YSize >= 7) {	//y좌표가 양수일 때
		return YSize - 7;	//블록이 떨어지는 위치는 YSize에서 7을 뺀 값으로 결정
	}
	else {			//y좌표가 음수일 때 
		return 0;	//0으로 설정
	}
}

int block[7][4][4] = { // block이름의 [7][4][4]크기 배열 생성 ([모양][블럭의 표현][블럭의표현])
	{				//네모 모양
		{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}
	},
	{				//일자 모양
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0},
		{0,0,0,0}
	},
	{				//S 모양
		{0,0,0,0},
		{0,0,1,1},
		{0,1,1,0},
		{0,0,0,0},
	},
	{				//Z 모양
		{0,0,0,0},
		{0,1,1,0},
		{0,0,1,1},
		{0,0,0,0}
	},
	{				//L 모양
		{0,0,0,0},
		{0,1,1,1},
		{0,1,0,0},
		{0,0,0,0}
	},
	{				//J 모양
		{0,0,0,0},
		{0,1,1,1},
		{0,0,0,1},
		{0,0,0,0}
	},
	{				//T 모양
		{0,0,0,0},
		{0,1,1,1},
		{0,0,1,0},
		{0,0,0,0}
	}
};

int blockRand() {		//블럭의 종류가 중첩되지 않게 랜덤생성
	int i;			//i변수 선언
	
	while (1) {				//중복이 아닌 블럭이 나올 때 까지 반복
		if (currentNum != 0) {	//첫번째 블럭이아닌 경우
 			blockset[currentNum] = rand() % 7;	//0부터 6사이의 랜덤한 수를 blockset에 저장
			for (i = 0; i < currentNum; i++) {	//이번 세트에서 중복이 있는지 확인
				if (blockset[i] == blockset[currentNum]) {	//만약 중복되는 블럭이 있으면
					break;									//for문을 빠져나감
				}
			}
			if (i == currentNum) {		//i가 currentNum이랑 같으면 (중복이 없으면)
				break;					//while문을 빠져나감
			}
		}
		else {	//첫번째 블럭인 경우
			blockset[currentNum] = rand() % 7;	//0부터 6사이의 랜덤한 수를 blockset에 저장
			break;								//while문을 빠져나감
		}
	}

	i = blockset[currentNum];		//blockset[currentNum]값을 i에 저장
	currentNum++;					//currentNum을 1 증가
	if (currentNum == 7) {	//currentNum의 값이 7이면
		currentNum = 0;		//0으로 초기화
	}

	return i;			//i값 리턴
}

void printBlock(int arr[4][4]) {	//printBlock 함수 (playBlock에 받은 모양을 출력하기 위한 함수)
	for (int i = 0; i < 4; i++) {	//y행 4칸만큼 반복
		gotoxy(XSize, YSize + 1);	//커서 위치를 (XSize, YSize)로 이동
		for (int j = 0; j < 4; j++) {	//x열 4칸반큼 반복
			if (arr[i][j] == 1) {	//arr[i][j]가 1이면 (1인 부분이 블럭인 부분)
				printf("■");		//■를 출력
			}
			else if (arr[i][j] == 0) {	//arr[i][j]가 0이면 (0인 부분이 블럭이 아닌 부분)
				gotoxy(XSize + 2 * (j + 1), YSize + i);	//gotoxy를 이용해 커서가 블럭이 출력될 부분으로 뛰어넘음 (기존에 있던 블럭이 덮어씌워지는 것을 방지)
			}
		}
	}
}

void removePrint(int arr[4][4]) {	//removePrint 함수 (잔상을 삭제하기 위한 함수)
	for (int i = 0; i < 4; i++) {	//y행 4칸만큼 반복
		gotoxy(XSize, YSize + 1);	//커서 위치를 (XSize, YSize)로 이동
		for (int j = 0; j < 4; j++) {	//x열 4칸반큼 반복
			if (arr[i][j] == 1) {	//arr[i][j]가 1이면 (1인 부분이 블럭인 부분)
				printf("  ");		//공백을 출력 (블럭인 부분을 삭제)
			}
			else if (arr[i][j] == 0) {	//arr[i][j]가 0이면
				gotoxy(XSize + 2 * (j + 1), YSize + i);	//gotoxy를 이용해 블럭(1인 부분)이 아닌 부분은 건너뜀.
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
				printf("□");
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

int blockCheckMoveLeft() {		//왼쪽으로 이동시 간섭 체크
	for (int i = 0; i < 4; i++) {	//i 4번만큼 반복
		for (int j = 0; j < 4; j++) {	//j 4번만큼 반복
			if (playBlock[j][i] != 0 && gameblock[yset() + j][(XSize - 10) / 2 - 1 + i] != 0) {		//현재 이동 중인 블럭과 게임 판에서의 블럭이 같은 위치에 존재하는지를 확인
				return 1;			//존재하면 1 리턴
			}
		}
	}
}

int blockCheckMoveRight() {		//오른쪽으로 이동시 간섭 체크
	for (int i = 3; i >= 0; i--) {	//i 4번만큼 반복
		for (int j = 0; j < 4; j++) {	//j 4번만큼 반복
			if (playBlock[j][i] != 0 && gameblock[yset() + j][(XSize - 10) / 2 + 1 + i] != 0) {		//현재 이동 중인 블럭과 게임 판에서의 블럭이 같은 위치에 존재하는지를 확인
				return 1;			//존재하면 1 리턴
			}
		}
	}
}

int blockCheckDown() {		//아래로 이동시 간섭 체크
	for (int i = 3; i >= 0; i--) {	//i 4번만큼 반복
		for (int j = 0; j < 4; j++) {	//j 4번만큼 반복
			if (playBlock[i][j] != 0 && gameblock[yset() + 1 + i][(XSize - 10) / 2 + j] != 0) {		//현재 이동 중인 블럭과 게임 판에서의 블럭이 같은 위치에 존재하는지를 확인
				return 1;			//존재하면 1 리턴
			}
		}
	}
	return 0;			//아니면 0 리턴 (이동이 가능)
}

int blockCheckTurnLeft() {		//회전시 왼쪽 간섭체크 
	for (int j = 0; j < 3; j++) {		//j가 0부터 2까지 증가
		if (playBlock[j][1] != 0 && gameblock[yset() + j][(XSize - 10) / 2 + 1] != 0) {		//둘 중 하나라도 1이면 (간섭이 발생했으면)
			return 1;		//1 리턴 (회전불가)
		}
	}
	return 0;		//간섭이 발생하지 않은 경우 0 리턴
}

int blockCheckTurnRight() {		//회전시 오른쪽 간섭체크 
	for (int j = 0; j < 3; j++) {		//j가 0부터 2까지 증가
		if (playBlock[j][3] != 0 && gameblock[yset() + j][(XSize - 10) / 2 + 3] != 0) {		//둘 중 하나라도 1이면 (간섭이 발생했으면)
			return 2;		//2 리턴 (회전불가)
		}
	}
	return 0;		//간섭이 발생하지 않은 경우 0 리턴
}

int blockCheckTurnUp() {		//회전시 위쪽 간섭체크 
	for (int i = 1; i < 4; i++) {		//i가 1부터 3까지 증가
		if (playBlock[0][i] != 0 && gameblock[yset()][(XSize - 10) / 2 + i] != 0) {		//둘 중 하나라도 1이면 (간섭이 발생했으면)
			return 3;		//3 리턴 (회전불가)
		}
	}
	return 0;		//간섭이 발생하지 않은 경우 0 리턴
}

int blockCheckTurnDown(void) {		//회전시 아래쪽 간섭체크 
	for (int i = 1; i < 4; i++) {		//i가 1부터 3까지 증가
		if (playBlock[2][i] != 0 && gameblock[yset() + 2][(XSize - 10) / 2 + i] != 0) {		//둘 중 하나라도 1이면 (간섭이 발생했으면)
			return 4;		//4 리턴 (회전불가)
		}
	}
	return 0;		//간섭이 발생하지 않은 경우 0 리턴
}

int blockCheckTurn() {			//회전을 할때 간섭을 체크하기 위한 함수

	if (playBlock[3][2] != 0 && gameblock[yset() + 3][(XSize - 10) / 2 + 2] != 0) {		// 일자 모양의 블럭 간섭이 (2, 3)에서 일어났을 때
		YSize -= 1;		//y값을 1 감소
		if (blockCheckTurnUp() == 3) {		//이동한 좌표가 위쪽 간섭 시
			YSize += 1;			//이동한 좌표 초기화
			return 1;			//1 리턴 (회전 불가)
		}
		else {
			if (blockCheckTurnDown() == 4) {		//이동한 좌표가 아래쪽 간섭 시
				YSize -= 1;		//한칸 더 이동
				if (blockCheckTurnUp() == 3) {		//다시 이동한 좌표가 위쪽 간섭 시
					YSize += 2;			//이동한 좌표 초기화
					return 1;			//1 리턴 (회전 불가)
				}
				else {				//간섭 하지 않을 시
					return 0;		//0 리턴
				}
			}
			else {					//간섭 하지 않을 시
				return 0;			//0 리턴
			}
		}
	}
	else if ((playBlock[1][0] != 0 && gameblock[yset()+1][(XSize-10)/2]!=0)&& XSize >= 10){	//일자 모양의 블럭 간섭이 (0, 1)에서 일어났을 때
		XSize += 2;				//x값을 2 증가
		if (blockCheckTurnRight() == 2) {		//이동한 좌표가 오른쪽 간섭시
			XSize -= 2;				//이동한 좌표 초기화
			return 1;				//1 리턴 (회전 불가)
		}
		else {				//간섭 하지 않을 시
			return 0;		//0 리턴
		}
	}
	else if (blockCheckTurnDown() == 4) {		//하단 간섭 체크
		if (playBlock[3][2] == 1) {		//일자 블럭 간섭 시
			YSize -= 2;			//y값 2 감소
			if (blockCheckTurnUp() == 3 || (playBlock[1][2] == 1 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] == 1)) {	//위쪽, 중앙 간섭 체크, 간섭이 발생했으면
				YSize += 2;		//이동한 좌표 초기화
				return 1;		//1 리턴(회전 불가)
			}
			else {			//간섭이 발생하지 않았으면
				return 0;	//0 리턴
			}
		}
		YSize -= 1;		//일자 블럭이 아닌 경우 y좌표를 1칸 위로 옮김
		if (blockCheckTurnUp() != 3) {		//이동한 좌표가 상단 간섭 안 할때
			if (blockCheckTurnLeft() == 1) {	//왼쪽 간섭 체크, 간섭이 발생했으면
				XSize += 2;		//x값 2 증가
				if (blockCheckTurnDown() == 4) {	//이동한 좌표 하단 간섭 체크, 간섭이 발생했으면
					XSize -= 2;		//x값 2 감소
					YSize += 1;		//y값 1 증가 (좌표 초기화)
					return 1;		//1 리턴(회전 불가)
				}
				else if (blockCheckTurnLeft() == 1) {	//이동한 좌표 왼쪽 간섭 체크, 간섭이 발생했으면
					XSize -= 2;		//x값 2 감소
					YSize += 1;		//y값 1 증가 (좌표 초기화)
					return 1;		//1 리턴(회전 불가)
				}
				else if (blockCheckTurnRight() == 2) {	//이동한 좌표 오른쪽 간섭 체크, 간섭이 발생했으면
					XSize -= 2;		//x값 2 감소
					YSize += 1;		//y값 1 증가 (좌표 초기화)
					return 1;		//1 리턴(회전 불가)
				}
				else if (blockCheckTurnUp() == 4) {	//이동한 좌표 위쪽 간섭 체크, 간섭이 발생했으면
					XSize -= 2;		//x값 2 감소
					YSize += 1;		//y값 1 증가 (좌표 초기화)
					return 1;		//1 리턴(회전 불가)
				}
				else if (playBlock[1][2] == 1 && gameblock[yset()+1][(XSize-10)/2+2]==1) {	//이동한 좌표 중앙 간섭 체크, 간섭이 발생했으면
					XSize -= 2;		//x값 2 감소
					YSize += 1;		//y값 1 증가 (좌표 초기화)
					return 1;		//1 리턴(회전 불가)
				}
				else {		//모든 간섭에 해당되지 않으면
					return 0;		//0 리턴
				}
			}
			else if (blockCheckTurnRight() == 2) {	//왼쪽 간섭 체크, 간섭이 발생했으면
				XSize -= 2;		//x값 2 감소
				if (blockCheckTurnDown() == 4) {	//이동한 좌표 하단 간섭 체크, 간섭이 발생했으면
					XSize += 2;		//x값 2 증가
					YSize += 1;		//y값 1 증가 (좌표 초기화)
					return 1;		//1 리턴(회전 불가)
				}
				else if (blockCheckTurnLeft() == 1) {	//이동한 좌표 왼쪽 간섭 체크, 간섭이 발생했으면
					XSize += 2;		//x값 2 증가
					YSize += 1;		//y값 1 증가 (좌표 초기화)
					return 1;		//1 리턴(회전 불가)
				}
				else if (blockCheckTurnRight() == 2) {	//이동한 좌표 오른쪽 간섭 체크, 간섭이 발생했으면
					XSize += 2;		//x값 2 증가
					YSize += 1;		//y값 1 증가 (좌표 초기화)
					return 1;		//1 리턴(회전 불가)
				}
				else if (blockCheckTurnUp() == 4) {	//이동한 좌표 위쪽 간섭 체크, 간섭이 발생했으면
					XSize += 2;		//x값 2 증가
					YSize += 1;		//y값 1 증가 (좌표 초기화)
					return 1;		//1 리턴(회전 불가)
				}
				else if (playBlock[1][2] == 1 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] == 1) {	//이동한 좌표 중앙 간섭 체크, 간섭이 발생했으면
					XSize += 2;		//x값 2 증가
					YSize += 1;		//y값 1 증가 (좌표 초기화)
					return 1;		//1 리턴(회전 불가)
				}
				else {		//모든 간섭에 해당되지 않으면
					return 0;		//0 리턴
				}
			}
		}
		else {		//상단 간섭 시
			YSize += 1;	//y값 1 증가 (좌표 초기화) 
			return 1;	//1 리턴 (회전 불가)
		}
	}
	else if (blockCheckTurnLeft() == 1) {		//왼쪽 간섭 체크
		if (playBlock[1][0] == 1) {		//일자 블럭의 간섭이 발생했으면
			XSize += 4;		//x값 4 증가
			if (blockCheckTurnRight() == 2 || (playBlock[1][2] == 1 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] == 1)) {		//이동한 좌표 오른쪽 간섭 체크, 중앙 간섭 체크, 간섭이 발생했으면
				XSize -= 4;		//x값 4 감소 (좌표 초기화)
				return 1;		//1 리턴 (회전 불가)
			}
			else {		//간섭 하지 않았을 시
				return 0;	//0 리턴
			}
		}
		XSize += 2;		//x값 2 증가
		if (blockCheckTurnRight() == 2) {		//이동한 좌표 오른쪽 간섭 체크
			XSize -= 2;		//x값 2 감소
			YSize -= 1;		//y값 1 감소
			if (blockCheckTurnDown() == 4) {	//이동한 좌표 하단 간섭 체크
				YSize += 1;		//y값 1 증가 (좌표 초기화)
				return 1;		//1 리턴 (회전 불가)
			}
			else if (blockCheckTurnLeft() == 1) {	//이동한 좌표 왼쪽 간섭 체크
				YSize += 1;		//y값 1 증가 (좌표 초기화)
				return 1;		//1 리턴 (회전 불가)
			}
			else if (blockCheckTurnRight() == 2) {	//이동한 좌표 오른쪽 간섭 체크
				YSize += 1;		//y값 1 증가 (좌표 초기화)
				return 1;		//1 리턴 (회전 불가)
			}
			else if (blockCheckTurnUp() == 3) {	//이동한 좌표 위쪽 간섭 체크
				YSize += 1;		//y값 1 증가 (좌표 초기화)
				return 1;		//1 리턴 (회전 불가)
			}
			else if (playBlock[1][2] == 1 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] == 1) {	//이동한 좌표 중앙 간섭 체크
				YSize += 1;		//y값 1 증가 (좌표 초기화)
				return 1;		//1 리턴 (회전 불가)
			}
			else {		//모든 간섭에 해당되지 않으면
				return 0;	//0 리턴
			}
		}
		else if (playBlock[1][2] == 1 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] == 1) {
			YSize += 1;		//y값 1 증가 (좌표 초기화)
			return 1;		//1 리턴 (회전 불가)
		}
		else {		//모든 간섭에 해당되지 않으면
			return 0;	//0 리턴
		}
	}
	else if (blockCheckTurnRight() == 2) {		//오른쪽 간섭 체크
		XSize -= 2;		//x값 2 감소
		if (blockCheckTurnLeft() == 1) {	//이동한 좌표 왼쪽 간섭체크
			XSize += 2;		//x값 2 증가
			YSize -= 1;		//y값 1 감소
			if (blockCheckTurnDown() == 4) {	//이동한 좌표 하단 간섭 체크
				YSize += 1;		//y값 1 증가 (좌표 초기화)
				return 1;		//1 리턴 (회전 불가)
			} else if (blockCheckTurnLeft() == 1) {	//이동한 좌표 왼쪽 간섭 체크
				YSize += 1;		//y값 1 증가 (좌표 초기화)
				return 1;		//1 리턴 (회전 불가)
			}
			else if (blockCheckTurnRight() == 2) {	//이동한 좌표 오른쪽 간섭 체크
				YSize += 1;		//y값 1 증가 (좌표 초기화)
				return 1;		//1 리턴 (회전 불가)
			}
			else if (blockCheckTurnUp() == 3) {	//이동한 좌표 위쪽 간섭 체크
				YSize += 1;		//y값 1 증가 (좌표 초기화)
				return 1;		//1 리턴 (회전 불가)
			}
			else if (playBlock[1][2] == 1 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] == 1) {	//이동한 좌표 중앙 간섭 체크
				YSize += 1;		//y값 1 증가 (좌표 초기화)
				return 1;		//1 리턴 (회전 불가)
			}
			else {		//모든 간섭에 해당되지 않으면
				return 0;	//0 리턴
			}
		}
		else if (playBlock[1][2] != 0 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] != 0) {	//이동한 좌표 중앙 간섭 체크
			YSize += 1;		//y값 1 증가 (좌표 초기화)
			return 1;		//1 리턴 (회전 불가)
		}
		else {		//모든 간섭에 해당되지 않으면
			return 0;	//0 리턴
		}
	}
	else if (blockCheckTurnLeft() == 3) {	//상단 간섭 체크
		YSize += 1;		//y값 1 증가
		if (blockCheckTurnDown() != 4) {	//이동한 좌표 하단 간섭 안 할 때 
			if (blockCheckTurnLeft() == 1) {	//이동한 좌표 왼쪽 간섭체크
				XSize += 2;		//x값 2 증가
				if (blockCheckTurnDown() == 4) {	//이동한 좌표 하단 간섭 체크
					XSize -= 2;		//x값 2 감소
					YSize -= 1;		//y값 1 감소 (좌표 초기화)
					return 1;		//1 리턴 (회전 불가)
				}
				else if (blockCheckTurnLeft() == 1) {	//이동한 좌표 왼쪽 간섭 체크
					XSize -= 2;		//x값 2 감소
					YSize -= 1;		//y값 1 감소 (좌표 초기화)
					return 1;		//1 리턴 (회전 불가)
				}
				else if (blockCheckTurnRight() == 2) {	//이동한 좌표 오른쪽 간섭 체크
					XSize -= 2;		//x값 2 감소
					YSize -= 1;		//y값 1 감소 (좌표 초기화)
					return 1;		//1 리턴 (회전 불가)
				}
				else if (blockCheckTurnUp() == 3) {	//이동한 좌표 위쪽 간섭 체크
					XSize -= 2;		//x값 2 감소
					YSize -= 1;		//y값 1 감소 (좌표 초기화)
					return 1;		//1 리턴 (회전 불가)
				}
				else if (playBlock[1][2] != 0 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] != 0) {	//이동한 좌표 중앙 간섭 체크
					YSize += 1;		//y값 1 증가 (좌표 초기화)
					return 1;		//1 리턴 (회전 불가)
				}
				else {		//모든 간섭에 해당되지 않으면
					return 0;	//0 리턴
				}
			}
			if (blockCheckTurnRight()==2) {	//이동한 좌표 오른쪽 간섭체크
				XSize -= 2;		//x값 2 감소
				if (blockCheckTurnDown() == 4) {	//이동한 좌표 하단 간섭 체크
					XSize += 2;		//x값 2 증가
					YSize -= 1;		//y값 1 감소 (좌표 초기화)
					return 1;		//1 리턴 (회전 불가)
				}
				else if (blockCheckTurnLeft() == 1) {	//이동한 좌표 왼쪽 간섭 체크
					XSize += 2;		//x값 2 증가
					YSize -= 1;		//y값 1 감소 (좌표 초기화)
					return 1;		//1 리턴 (회전 불가)
				}
				else if (blockCheckTurnRight() == 1) {	//이동한 좌표 오른쪽 간섭 체크
					XSize += 2;		//x값 2 증가
					YSize -= 1;		//y값 1 감소 (좌표 초기화)
					return 1;		//1 리턴 (회전 불가)
				}
				else if (blockCheckTurnUp() == 1) {	//이동한 좌표 위쪽 간섭 체크
					XSize += 2;		//x값 2 증가
					YSize -= 1;		//y값 1 감소 (좌표 초기화)
					return 1;		//1 리턴 (회전 불가)
				}
				else if (playBlock[1][2] != 0 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] != 0) {	//이동한 좌표 중앙 간섭 체크
					YSize += 1;		//y값 1 증가 (좌표 초기화)
					return 1;		//1 리턴 (회전 불가)
				}
				else {		//모든 간섭에 해당되지 않으면
					return 0;	//0 리턴
				}
			}
			else {		//회전할 수 없을 때
				YSize -= 1;		//y값 1 감소
				return 1;		//1 리턴
			}
		}
		else if (playBlock[1][2] != 0 && gameblock[yset() + 1][(XSize - 10) / 2 + 2] != 0) {	//이동한 좌표 중앙 간섭 체크
			YSize += 1;		//y값 1 증가 (좌표 초기화)
			return 1;		//1 리턴 (회전 불가)
		}
		else {		//모든 간섭에 해당되지 않으면
			return 0;	//0 리턴
		}
	}
}

void calcTurnLeft() {	//왼쪽으로 돌 때 회전 연산하는 함수
	int temp = 0;			//변수 temp 선언

	temp = playBlock[2][3];		//회전축 기준 꼭짓점 회전 
	playBlock[2][3] = playBlock[2][1];
	playBlock[2][1] = playBlock[0][1];
	playBlock[0][1] = playBlock[0][3];
	playBlock[0][3] = temp;

	temp = playBlock[1][3];		//회전축 기준 모서리 회전 
	playBlock[1][3] = playBlock[2][2];
	playBlock[2][2] = playBlock[1][1];
	playBlock[1][1] = playBlock[0][2];
	playBlock[0][2] = temp;

	temp = playBlock[1][0];		//일자블럭만 포함되는 부분 회전 
	playBlock[1][0] = playBlock[3][2];
	playBlock[3][2] = temp;
}

void calcTurnRight() {	//오른쪽으로 돌 때 회전 연산하는 함수
	int temp = 0;			//변수 temp 선언

	temp = playBlock[0][3];		//회전축 기준 꼭짓점 회전 
	playBlock[0][3] = playBlock[0][1];
	playBlock[0][1] = playBlock[2][1];
	playBlock[2][1] = playBlock[2][3];
	playBlock[2][3] = temp;

	temp = playBlock[0][2];		//회전축 기준 모서리 회전 
	playBlock[0][2] = playBlock[1][1];
	playBlock[1][1] = playBlock[2][2];
	playBlock[2][2] = playBlock[1][3];
	playBlock[1][3] = temp;

	temp = playBlock[1][0];		//일자블럭만 포함되는 부분 회전 
	playBlock[1][0] = playBlock[3][2];
	playBlock[3][2] = temp;
}

void turnLeft() {		//turnLeft 함수 (왼쪽으로 회전하는 함수)
	if (playBlock[1][2] == 1 && playBlock[2][1] == 1 && playBlock[2][2] == 1 && playBlock[1][1] == 1) {		//정사각형 블럭일시 
		return;			//회전을 하지 않고 종료
	}

	removePrint(playBlock);	//잔상 삭제

	calcTurnLeft();		//회전 연산

	if (blockCheckTurn() == 1) {	//벽 간섭 체크해서 1이 리턴되면
		calcTurnRight();		//원상복구
	}
	guide();
	printBlock(playBlock);		//회전된 모습 출력
}

void turnRight() {		//turnRight 함수 (오른쪽으로 회전하는 함수)
	if (playBlock[1][2] == 1 && playBlock[2][1] == 1 && playBlock[2][2] == 1 && playBlock[1][1] == 1) {		//정사각형 블럭일시
		return;			//회전을 하지 않고 종료
	}

	removePrint(playBlock);	//잔상 삭제

	calcTurnRight();	//회전 연산

	if (blockCheckTurn() == 1) {	//벽 간섭 체크해서 1이 리턴되면
		calcTurnLeft();		//원상복구
	}
	guide();
	printBlock(playBlock);		//회전된 모습 출력
}

void moveLeft() {		//moveLeft 함수 (왼쪽으로 이동하는 함수)
	if (blockCheckMoveLeft() != 1) {	//왼쪽 벽에 간섭이 되지 않으면
		removePrint(playBlock);	//잔상 삭제
		XSize -= 2;				//x축 왼쪽 방향으로 2만큼 이동
		guide();
		printBlock(playBlock);	//이동한 자리에 출력
	}
}

void moveRight() {		//moveRight 함수 (오른쪽으로 이동하는 함수)
	if (blockCheckMoveRight() != 1) {	//오른쪽 벽에 간섭이 되지 않으면
		removePrint(playBlock);	//잔상 삭제
		XSize += 2;				//x축 오른쪽 방향으로 2만큼 이동
		guide();
		printBlock(playBlock);	//이동한 자리에 출력
	}
}

int moveDown() {		//moveDown 함수 (밑으로 이동하는 함수)
	if (blockCheckDown() != 1) {	//간섭 없을 시 (내려갈 수 있으면)
		removePrint(playBlock);	//잔상 삭제
		YSize+=1;				//y축 방향으로 1만큼 이동
		printBlock(playBlock);	//이동한 자리에 출력
		score += 1;				//점수 1점 추가
		return 0;	//0 리턴
	}
	else {	//간섭 시 (더이상 못 내려갈 시)
		return 1;	//1 리턴
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

int keyBoard() {		//keyBoard 함수 (키보드 입력을 받는 함수)
	if (_kbhit()) {		//키보드 입력을 받았을 때
		int key = _getch();	//입력받은 값을 key에 저장
		if (key == 224) {	//key값이 224(방향키) 이면
			key = _getch();	//한번더 저장 (방향키는 224와 숫자 하나가 더 나옴)
			switch (key) {	//받아온 key의 값을 넣고
			case 72:		//key가 72(위쪽 방향키) 이면
				turnLeft();	//왼쪽으로 돌기
				break;
			case 75:		//key가 75(왼쪽 방향키) 이면
				moveLeft();	//왼쪽으로 이동
				break;
			case 77:		//key가 77(오른쪽 방향키) 이면
				moveRight();//오른쪽으로 이동
				break;
			case 80:		//key가 80(아래쪽 방향키) 이면
				moveDown();	//아래로 이동
				return 1;	//1 리턴(지연시간을 초기화하기위해)
				break;
			}
		}
		else if (key == 115) { //key가 115(s키) 이면
			turnLeft();		   //왼쪽으로 돌기
		}
		else if (key == 100) { //key 100(d키) 이면
			turnRight();	   //오른쪽으로 돌기
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

void topgameline() {	//상단 경계선을 지정하는 함수
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);		//상단 경계선을 흰색으로 지정 
	gotoxy(10, 9);	//10, 9 좌표 이동
	for (int j = 0; j < 12; j++) {	//12번 반복하면서
		printf("──");		//── 출력
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), currentBlock);		//텍스트 색 다시 원래 블록 색으로 지정 
}

void moveBlock(int speed) {		//moveBlock 함수 (1초간격으로 블럭이 하강함)
	XSize = 18;			//x열 좌표를 18로 지정
	YSize = 8;			//y행 좌표를 8으로 지정

	moveDown();			//처음 블럭이 생성될때 블럭 위치를 조정하기 위해
	moveDown();			//두번 아래로 실행
	guide();
	while (1) {			//계속 반복
		for (int i = 0; i < speed; i++) {	//10ms씩 speed번 반복 = (10*speed) / 1000초 간격으로 하강
			if (_kbhit()) {				//키보드 입력이 있을 시
				if (keyBoard() == 1) {	//밑으로 이동하는 방향키 입력 받았을 때 (1을 리턴받았을 때)
					continue;			//지연시간 초기화(다시 n초동안 기다려야 블럭이 아래로 내려감)
				}
			}
			topgameline();			//젤 윗줄 경계선 출력	
			Sleep(10);				//10ms 대기
		}
		if (blockCheckDown() == 1) {		//아래로 더 이상 이동이 불가능하면
			return;					//함수를 종료
		}
		moveDown();		//아래로 하강
	}
}

int checkXsize(int arr[4]) {			//대기중인 블럭 X좌표를 설정하기 위한 함수
	if (setColor(arr) == 14 || setColor(arr) == 11) {		//대기중인 블럭이 네모나 일자 모양이면
		return 44;			//X좌표값을 44로 줌
	}
	else {					//대기중인 블럭이 네모나 일자 모양이 아니면
		return 43;			//X좌표값을 43으로 줌
	}
}

void blockPrint() {			//대기중인 블럭 출력
	XSize = checkXsize(blocksetprint[0]);		//checkXsize함수를 통해 X좌표값을 설정
	YSize = 9;				//y행 9 위치에
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), setColor(blocksetprint[0]));	//블록 모양에 맞는 색깔 지정
	printBlock(blocksetprint[0]);	//blocksetprint에 담은 첫번째 블럭을 출력

	XSize = checkXsize(blocksetprint[1]);		//checkXsize함수를 통해 X좌표값을 설정
	YSize = 14;				//y행 14 위치에
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), setColor(blocksetprint[1]));	//블록 모양에 맞는 색깔 지정
	printBlock(blocksetprint[1]);	//blocksetprint에 담은 두번째 블럭을 출력

	XSize = checkXsize(blocksetprint[2]);		//checkXsize함수를 통해 X좌표값을 설정
	YSize = 19;				//y행 19 위치에
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), setColor(blocksetprint[2]));	//블록 모양에 맞는 색깔 지정
	printBlock(blocksetprint[2]);	//blocksetprint에 담은 세번째 블럭을 출력

	XSize = checkXsize(blocksetprint[3]);		//checkXsize함수를 통해 X좌표값을 설정
	YSize = 24;				//y행 24 위치에
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), setColor(blocksetprint[3]));	//블록 모양에 맞는 색깔 지정
	printBlock(blocksetprint[3]);	//blocksetprint에 담은 네번째 블럭을 출력

	XSize = checkXsize(blocksetprint[4]);		//checkXsize함수를 통해 X좌표값을 설정
	YSize = 29;				//y행 29 위치에
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), setColor(blocksetprint[4]));	//블록 모양에 맞는 색깔 지정
	printBlock(blocksetprint[4]);	//blocksetprint에 담은 다섯번째 블럭을 출력

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void removeBlockPrint() {			//대기중인 블럭 잔상 지우기
	XSize = checkXsize(blocksetprint[0]);		//checkXsize함수를 통해 X좌표값을 설정
	YSize = 9;				//y행 9 위치에
	removePrint(blocksetprint[0]);	//blocksetprint에 담은 첫번째 블럭 잔상을 제거

	XSize = checkXsize(blocksetprint[1]);		//checkXsize함수를 통해 X좌표값을 설정
	YSize = 14;				//y행 14 위치에
	removePrint(blocksetprint[1]);	//blocksetprint에 담은 두번째 블럭 잔상을 제거

	XSize = checkXsize(blocksetprint[2]);		//checkXsize함수를 통해 X좌표값을 설정
	YSize = 19;				//y행 19 위치에
	removePrint(blocksetprint[2]);	//blocksetprint에 담은 세번째 블럭 잔상을 제거

	XSize = checkXsize(blocksetprint[3]);		//checkXsize함수를 통해 X좌표값을 설정
	YSize = 24;				//y행 24 위치에
	removePrint(blocksetprint[3]);	//blocksetprint에 담은 네번째 블럭 잔상을 제거

	XSize = checkXsize(blocksetprint[4]);		//checkXsize함수를 통해 X좌표값을 설정
	YSize = 29;				//y행 29 위치에
	removePrint(blocksetprint[4]);	//blocksetprint에 담은 다섯번째 블럭 잔상을 제거
}

void changeac(int num) {		//대기중인 블럭 한칸씩 앞으로 당기기
	removeBlockPrint();			//대기중인 블럭 잔상 지우기
	for (int i = 0; i < 4; i++) {	//i 0~3까지 반복
		for (int j = 0; j < 4; j++) {	//j 0~3까지 반복
			playBlock[i][j] = blocksetprint[0][i][j];		//대기중인 첫번째 블럭을 playBlock에 저장
			blocksetprint[0][i][j] = blocksetprint[1][i][j];	//대기중인 두번째 블럭을 대기중인 첫번째 블럭에 저장
			blocksetprint[1][i][j] = blocksetprint[2][i][j];	//대기중인 세번째 블럭을 대기중인 두번째 블럭에 저장
			blocksetprint[2][i][j] = blocksetprint[3][i][j];	//대기중인 네번째 블럭을 대기중인 세번째 블럭에 저장
			blocksetprint[3][i][j] = blocksetprint[4][i][j];	//대기중인 다섯번째 블럭을 대기중인 네번째 블럭에 저장
			blocksetprint[4][i][j] = block[num][i][j];			//랜덤한 블럭 하나를 대기중인 다섯번째 블럭에 저장
		}
	}
	blockPrint();		//블럭 출력
}

void setGameBlock() {			//현재 떨어지고 있는 테트리스 블럭을 게임 화면에 추가하는 함수
	for (int i = 0; i < 4; i++) {	//i 0~3까지 반복
		for(int j=0; j<4; j++){		////j 0~3까지 반복
			if (playBlock[i][j] == 1) {	//값이 1인 부분에 대해	(플레이 하고있는 블럭인 부분)
				gameblock[yset() + i][(XSize - 10) / 2 + j] = currentBlock;	//게임 화면에 해당 블럭을 추가
			}
		}
	}
}

void printGameBlock() {		//줄이 완성되었을때 한줄 당기고 나머지 블럭들을 출력하기 위한 함수
	for (int i = 4; i < 24; i++) {	//i가 4부터, 20번 반복
		gotoxy(12, 7 + i);		//12, 7+i 좌표 이동
		for (int j = 1; j < 11; j++)	//j가 1부터 10번 반복
		{
			if (gameblock[i][j] == 0) {		//gameblock[i][j]가 0이면 (블럭이 없으면)
				printf("  ");		//공백 출력
			}
			else {	//블럭이 있으면
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), gameblock[i][j]);	//블럭 색깔 지정
				printf("■");		//■ 출력
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	//색깔 다시 흰색으로 지정
}

void finishedGameBlock(int a) {		//줄이 완성되었을 때 호출하는 함수
	int k = 0;
	for (int i = a; i > 0; i--) {	//받아온 a값을 i에 넣고 i가 0보다 클 동안 반복하고 i를 1씩 빼기
		for (int j = 1; j < 11; j++){	//j가 1부터 10번 반복
			gameblock[i][j] = gameblock[i - 1][j];		//완성된 줄의 윗줄부터 하나씩 아랫줄로 이동 
			k++;
		}
		printGameBlock();		//게임 화면 갱신
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

void scanGameBlock() {		//블럭의 줄이 완성되었는지 확인하기 위한 함수
	int j;		//j변수 선언
	for (int i = 23; i > 3; i--){		//i가 23부터 20번 반복
		for (j = 1; j < 11; j++){	//j가 1부터 10번 반복
			if (gameblock[i][j] == 0) {		//완성이 되지 않은 부분이 있다면
				break;		//반복 종료 (다음 줄로)
			}
		}
		if (j == 11) {		//완성이 되었다면
			finishedGameBlock(i++);		// 한 줄씩 당기기 
		}
	}
}

int compareBlock(int arr[4][4], int a) {	//arr배열에 담긴 블럭이 block배열의 a번째 블럭과 같은지 비교하는 함수
	for (int i = 0; i < 4; i++) {	//4번 반복
		for (int j = 0; j < 4; j++) {	//4번 반복
			if (arr[i][j] != block[a][i][j]) {	//arr배열의 블럭과 block배열의 a번째 블럭이 같지 않으면
				return 1;		//1 리턴 (같지 않다는 신호)
			}
		}
	}
	return 0;	//같으면 0 리턴
}

int setColor(int arr[4][4]) {	//블럭을 받아와서 그 블럭에 색깔을 입히기 위해 색깔 코드를 지정해주는 함수
	int i;		//i 변수 선언

	for (i = 0; i < 7; i++) {	//7번 반복
		if (compareBlock(arr, i) == 0) {	//arr배열에 받아온 블럭이 어떤 블럭인지 찾기위해 compareBlock에 넣음
			break;		//블럭을 찾았으면(0을 리턴 받았으면) break
		}
	}

	if (i == 0) {		//0번째 블럭이면 (네모 모양이면)
		return 14;		//노랑색 코드인 14를 리턴
	}
	if (i == 1) {		//1번째 블럭이면 (일자 모양이면)
		return 11;		//하늘색 코드인 11을 리턴
	}
	if (i == 2) {		//2번째 블럭이면 (S 모양이면)
		return 10;		//연두색 코드인 10을 리턴
	}
	if (i == 3) {		//3번째 블럭이면 (Z 모양이면)
		return 12;		//빨간색 코드인 12를 리턴
	}
	if (i == 4) {		//4번째 블럭이면 (L 모양이면)
		return 4;		//주황색 코드인 4를 리턴
	}
	if (i == 5) {		//5번째 블럭이면 (J 모양이면)
		return 9;		//파란색 코드인 9를 리턴
	}
	if (i == 6) {		//6번째 블럭이면 (T 모양이면)
		return 13;		//보라색 코드인 13을 리턴
	}
}

