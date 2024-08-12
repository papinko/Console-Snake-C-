// ---- User header files ----
#include "print.h"
#include "snake.h"
#include "parameters.h"
#include <fstream>

// ---- System header files ----
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>


#include <iostream>
#include <fstream>
#include <strstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

#define GAME_SPEED 300

// ---- Result table output ----
void Print::results(Snake * p_snake, Eat * p_eat, Parameter * p_parameter) {
	cout << "------------------------------------------" << endl;
	cout << "                 LEVEL " << p_parameter->level << endl;
	cout << "------------------------------------------" << endl;
	cout << "LENGHT: " << p_snake->snake_length + 1 << endl;
	cout << " SPEED: " << p_parameter->game_speed << endl;
	cout << "POINTS: " << p_parameter->points << endl;
	cout << "        " << p_parameter->last_speed_mod_in_point << " points for LEVEL " << p_parameter->level + 1 << endl;
	cout << "------------------------------------------" << endl;
}

void Print::Read() {

	TCHAR windir[MAX_PATH];

	GetWindowsDirectory(windir, MAX_PATH);

	ifstream myReadFile;
	myReadFile.open(GetWindowsDirectory(windir, MAX_PATH) + "snakeData.txt", ios::in);

	cout  << "------------------------------------------" << endl;
	char line;
	while (myReadFile.get(line))
	{
		cout << line;
		//if (myReadFile.peek() == '\n') //detect "\n"
		//{
			
		//}
	}
	cout << endl << "------------------------------------------";
	myReadFile.close();
}

void Print::menu() {

	do
	{
		for (int i = 0; i < 12; i++)
		{
			cout << endl;
		}

		string ch = " ";
		for (int i = 0; i < 45; i++)
		{
			ch += " ";
		}
		cout << ch << " ----  " << "|      " << "    /\\     " << "\\     /" << endl;
		cout << ch << "|    | " << "|      " << "   /  \\    " << " \\   /" << endl;
		cout << ch << "|----  " << "|      " << "  /    \\   " << "  \\ /" << endl;
		cout << ch << "|      " << "|      " << " /------\\  " << "   |" << endl;
		cout << ch << "|      " << "|_____ " << "/        \\ " << "   |" << endl;
		cout << endl << ch << "to continue HOLD ENTER" << endl;

		cout << endl << endl << endl;

		// ---- Reading ----
		Read();
		/*// ---- TIMER ----
		this_thread::sleep_for(chrono::milliseconds(1000));
		system("CLS");
		this_thread::sleep_for(chrono::milliseconds(1000));*/
		

		if (GetKeyState(VK_RETURN) & 0x8000) {

			system("CLS");

			cout << "3" << endl;
			this_thread::sleep_for(chrono::milliseconds(1000));

			cout << "2" << endl;
			this_thread::sleep_for(chrono::milliseconds(1000));

			cout << "1" << endl;
			this_thread::sleep_for(chrono::milliseconds(1000));
			break;
		}
		this_thread::sleep_for(chrono::milliseconds(1000));
		system("CLS");
	} while (true);

}