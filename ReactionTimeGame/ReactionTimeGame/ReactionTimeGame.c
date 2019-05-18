#include "ReactionTimeGame.h"

int main() {
	int input = 0, curY = 0;

	while (_kbhit) {
		printMenu(curY);

		if (_kbhit()) { // 화살표를 눌렀을 때
			input = _getch();

			if (input == 224) {
				input = _getch();
				switch (input)
				{
				case 72:
					curY = moveUp(curY); // 창에서 위로 올라가기
					break;
				case 80:
					curY = moveDown(curY); // 창에서 아래로 가기
					break;
				default:
					break;
				}
			}
		}
		else { // 엔터키를 눌렀을 때
			if (input == 13) {
				input = 0;
				if (curY == 0) {
					checkReactionTime(input, curY);
				}
				else if (curY == 1) {
					playWithComputer(input, curY);
				}
				else {
					printf("종료했습니다.\n");
					exit(0);
				}
			}
		}
		Sleep(200);
		system("cls");
	}
}

void printMenu(int curY)
{
	printf("반응속도 측정하기\n");
	printf("컴퓨터랑 대결하기\n");
	printf("나가기\n\n");
	printf("방향키로 움직이고 엔터키로 선택하세요.\n");
	switch (curY) //커서 좌표에 따라 커서 표시를 함
	{
	case 0:
		gotoxy(18, 0);
		printf("<-");
		break;
	case 1:
		gotoxy(18, 1);
		printf("<-");
		break;
	case 2:
		gotoxy(7, 2);
		printf("<-");
		break;
	}
}

int moveUp(int curY)
{
	if (curY == 0) {
		curY = 2;
	}
	else {
		curY -= 1;
	}
	return curY;
}

int moveDown(int curY)
{
	if (curY == 2) {
		curY = 0;
	}
	else {
		curY += 1;
	}
	return curY;
}

void checkReactionTime()
{
	double sec;
	system("cls");
	sec = getReactionTime();
	printf("%.3lf초입니다.\n", sec);
	system("pause");
}

void playWithComputer()
{
	system("cls");
	int dif, comTime;
	double sec;
	printf("난이도를 고르세요(1 ~ 5) : ");
	scanf_s("%d", &dif);
	switch (dif) //난이도 설정
	{
	case 1:
		comTime = rand() % 500 + 400;
		break;
	case 2:
		comTime = rand() % 400 + 300;
		break;
	case 3:
		comTime = rand() % 300 + 200;
		break;
	case 4:
		comTime = rand() % 200 + 150;
		break;
	case 5:
		comTime = rand() % 150 + 100;
		break;
	default:
		printf("잘못된 입력입니다.\n");
		system("pause");
		return 0;
	}
	sec = getReactionTime();
	if (comTime < sec * 1000) {
		printf("컴퓨터가 이겼습니다.\n");
	}
	else {
		printf("당신이 이겼습니다.\n");
	}
	printf("You : %.3lf초\n", sec);
	printf("Com : %.3lf초\n", (double)comTime / (double)1000);
	system("pause");
	return 0;
}

double getReactionTime()
{
	int sec, randTime;
	srand(time(NULL));
	randTime = rand() % 3000 + 400;
	printf("화면에 \"누르세요\"가 나오면 스페이스 바을 누르세요.\n");
	Sleep(1500);
	printf("준비\n");
	Sleep(randTime);
	printf("누르세요!\n");
	sec = returnReactionTime();
	return sec / 1000.0;
}

void gotoxy(int x, int y)
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int returnReactionTime()
{
	int start, finish, chget;
	start = clock();
	while (!_kbhit()) {
		chget = _getch();
		if (chget == 32) {
			break;
		}
	}
	finish = clock();
	return finish - start;
}
