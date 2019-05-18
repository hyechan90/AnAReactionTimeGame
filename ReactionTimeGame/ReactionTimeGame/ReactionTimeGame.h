#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

void printMenu(int curY);
int moveUp(int curY);
int moveDown(int curY);
void checkReactionTime();
void playWithComputer();
double getReactionTime();
void gotoxy(int x, int y);
int returnReactionTime();
