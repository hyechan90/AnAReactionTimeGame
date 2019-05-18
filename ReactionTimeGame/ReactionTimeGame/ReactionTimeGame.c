#include "ReactionTimeGame.h"

int main() {
	int input = 0, curY = 0;

	while (_kbhit) {
		printMenu(curY);

		if (_kbhit()) { // ȭ��ǥ�� ������ ��
			input = _getch();

			if (input == 224) {
				input = _getch();
				switch (input)
				{
				case 72:
					curY = moveUp(curY); // â���� ���� �ö󰡱�
					break;
				case 80:
					curY = moveDown(curY); // â���� �Ʒ��� ����
					break;
				default:
					break;
				}
			}
		}
		else { // ����Ű�� ������ ��
			if (input == 13) {
				input = 0;
				if (curY == 0) {
					checkReactionTime(input, curY);
				}
				else if (curY == 1) {
					playWithComputer(input, curY);
				}
				else {
					printf("�����߽��ϴ�.\n");
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
	printf("�����ӵ� �����ϱ�\n");
	printf("��ǻ�Ͷ� ����ϱ�\n");
	printf("������\n\n");
	printf("����Ű�� �����̰� ����Ű�� �����ϼ���.\n");
	switch (curY) //Ŀ�� ��ǥ�� ���� Ŀ�� ǥ�ø� ��
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
	printf("%.3lf���Դϴ�.\n", sec);
	system("pause");
}

void playWithComputer()
{
	system("cls");
	int dif, comTime;
	double sec;
	printf("���̵��� ������(1 ~ 5) : ");
	scanf_s("%d", &dif);
	switch (dif) //���̵� ����
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
		printf("�߸��� �Է��Դϴ�.\n");
		system("pause");
		return 0;
	}
	sec = getReactionTime();
	if (comTime < sec * 1000) {
		printf("��ǻ�Ͱ� �̰���ϴ�.\n");
	}
	else {
		printf("����� �̰���ϴ�.\n");
	}
	printf("You : %.3lf��\n", sec);
	printf("Com : %.3lf��\n", (double)comTime / (double)1000);
	system("pause");
	return 0;
}

double getReactionTime()
{
	int sec, randTime;
	srand(time(NULL));
	randTime = rand() % 3000 + 400;
	printf("ȭ�鿡 \"��������\"�� ������ �����̽� ���� ��������.\n");
	Sleep(1500);
	printf("�غ�\n");
	Sleep(randTime);
	printf("��������!\n");
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
