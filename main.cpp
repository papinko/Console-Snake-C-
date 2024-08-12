
// ---- System header files ----
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <fstream>

#include <ctime>
#include <iomanip>
#include <stdlib.h>


// ---- User header files ----
#include "snake.h"
#include "grid.h"
#include "parameters.h"
#include "eat.h"
#include "print.h"


using namespace std;


#define SNAKE_BLOCK  '+'
#define EAT          '#' //?
#define EMPTY_BLOCK  ' '



void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}


int main(int argc, char* argv[]) {

	Parameter parameter;

	// ---- Cursor off ----
	ShowConsoleCursor(false);

	// ---- Public instance ----
	Snake snake;
	Snake* p_snake = &snake;
	Print print;

	// ---- Game running ----
	do
	{
		print.menu();
		snake.Moving(p_snake);
		
	} while (true);

	

	system("pause>nul");
	return 0;
}