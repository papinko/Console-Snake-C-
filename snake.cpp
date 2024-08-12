
// ---- User header files ----
#include <iostream>
#include <thread>

#include <Windows.h>

#include <stdio.h>
#include <vector>
#include <fstream>

#include <ctime>

#include <iomanip>
#include <stdlib.h>
#include <chrono>




// ---- System header files ----
#include "snake.h"
#include "grid.h"
#include "parameters.h"
#include "eat.h"
#include "print.h"

#define GRID_COL   20
#define GRID_ROW   20
#define GAME_SPEED 300

#define VIEW_UPDATE grid.grid_update(grid.game_grid);

#define KEY_UP     72
#define KEY_DOWN   80
#define KEY_LEFT   75
#define KEY_RIGHT  77

#define SNAKE_BLOCK  '+'
#define EAT          '#' //?
#define EMPTY_BLOCK  ' '


using namespace std;



// ---- X_POS MOVING ----
void Snake::x_pos_left_move(Snake* p_snake, char game_grid[GRID_COL][GRID_ROW], int* last_key) {

	// ---- Last block deleting ---- 
	p_snake->x_pos_head--;

	// ---- Changing of last_key ----
	*last_key = KEY_LEFT;
}


void Snake::x_pos_right_move(Snake* p_snake, char game_grid[GRID_COL][GRID_ROW], int* last_key) {

	// ---- Last block deleting ---- 
	p_snake->x_pos_head++;

	// ---- Changing of last_key ----
	*last_key = KEY_RIGHT;
}


// ---- Y_POS MOVING ----
void Snake::y_pos_down_move(Snake* p_snake, char game_grid[GRID_COL][GRID_ROW], int* last_key) {

	// ---- Y_POS ADD ONE BLOCK ---- 
	p_snake->y_pos_head++;

	// ---- Changing of last_key ----
	*last_key = KEY_DOWN;
}


void Snake::y_pos_up_move(Snake* p_snake, char game_grid[GRID_COL][GRID_ROW], int* last_key) {

	// ---- Snake head position changing ----
	p_snake->y_pos_head--;

	// ---- Changing of last_key ----
	*last_key = KEY_UP;
}



void Snake::Respawn(Snake* p_snake, char game_grid[GRID_COL][GRID_ROW]) {

	// ---- Push the last element back ----
	p_snake->snake_actualle_x_pos.push_back(p_snake->x_pos_head);
	p_snake->snake_actualle_y_pos.push_back(p_snake->y_pos_head);


	// ---- Snake head and body drawning ----
	if (!p_snake->snake_actualle_y_pos.empty() && !p_snake->snake_actualle_x_pos.empty()) {
		for (int i = 0; i < p_snake->snake_actualle_x_pos.size(); i++)
		{
			game_grid[p_snake->snake_actualle_y_pos[i]][p_snake->snake_actualle_x_pos[i]] = SNAKE_BLOCK;
		}
	}


	// ---- Deleting the first element in array (vector) ----
	if (p_snake->snake_length < p_snake->snake_actualle_y_pos.size()) {
		p_snake->snake_actualle_x_pos.erase(p_snake->snake_actualle_x_pos.begin());
		p_snake->snake_actualle_y_pos.erase(p_snake->snake_actualle_y_pos.begin());
	}
}


// ---- Array filling with empty lines ----
void Array_Filling_With_Empty_Characters(char game_grid[GRID_COL][GRID_ROW]) {
	for (int i = 0; i < GRID_COL; i++) {
		for (int j = 0; j < GRID_ROW; j++) {
			if (game_grid[i][j] != EAT)
				game_grid[i][j] = EMPTY_BLOCK;
		}
	}
}


// ---- Function serve for snake-moving ----
void Snake::Moving(Snake* p_snake) {
	// ---- Parameter instance ----
	Parameter parameter;
	Parameter* p_parameter = &parameter;

	// ---- Print instance ----
	Print print;

	parameter.game_speed = GAME_SPEED;


	// ---- GRID instance ----
	Grid grid;
	//char game_grid[GRID_COL][GRID_ROW];


	// ---- EAT instance ----
	Eat eat;
	Eat* p_eat = &eat;

	// Array filling with empty lines
	Array_Filling_With_Empty_Characters(grid.game_grid);


	// ---- First eat respawning ----
	eat.eat_respawn(grid.game_grid);


	// ---- "Buffer" last key pressed ----
	int last_key = KEY_DOWN;


	// ---- game life ----
	bool game_life = true;


	// ---- Snake moving ----
	do {
		system("CLS");

		// Array filling with empty lines
		Array_Filling_With_Empty_Characters(grid.game_grid);


		// ---- buttons push detecting ----
		if (GetKeyState(VK_DOWN) & 0x8000) {
			p_snake->y_pos_down_move(p_snake, grid.game_grid, &last_key);
		}

		else if (GetKeyState(VK_UP) & 0x8000) {
			p_snake->y_pos_up_move(p_snake, grid.game_grid, &last_key);
		}

		else if (GetKeyState(VK_RIGHT) & 0x8000) {
			p_snake->x_pos_right_move(p_snake, grid.game_grid, &last_key);
		}

		else if (GetKeyState(VK_LEFT) & 0x8000) {
			p_snake->x_pos_left_move(p_snake, grid.game_grid, &last_key);
		}

		else {
			if (last_key == KEY_DOWN) {
				p_snake->y_pos_down_move(p_snake, grid.game_grid, &last_key);
			}

			else if (last_key == KEY_UP) {
				p_snake->y_pos_up_move(p_snake, grid.game_grid, &last_key);
			}

			else if (last_key == KEY_RIGHT) {
				p_snake->x_pos_right_move(p_snake, grid.game_grid, &last_key);
			}

			else if (last_key == KEY_LEFT) {
				p_snake->x_pos_left_move(p_snake, grid.game_grid, &last_key);
			}
		}


		// ---- Collision snake head with eat ----
		if (grid.game_grid[p_snake->y_pos_head][p_snake->x_pos_head] == grid.game_grid[eat.y_pos_eat][eat.x_pos_eat]) {

			p_snake->snake_length++;
			eat.eat_respawn(grid.game_grid);
			parameter.points += 50;
		}


		// ---- Collision snake with borders ----
		if (p_snake->y_pos_head < 0 || p_snake->y_pos_head > GRID_COL || parameter.points < 0) {
			message("GAME OVER");
			p_snake->snake_actualle_x_pos.erase(p_snake->snake_actualle_x_pos.begin(), p_snake->snake_actualle_x_pos.begin() + p_snake->snake_actualle_x_pos.size());
			p_snake->snake_actualle_y_pos.erase(p_snake->snake_actualle_y_pos.begin(), p_snake->snake_actualle_y_pos.begin() + p_snake->snake_actualle_y_pos.size());

			// ---- Writing ----
			Write(p_parameter);
			

			break;
		}


		// ---- Collision with yourself ----
		if (!p_snake->snake_actualle_y_pos.empty() && !p_snake->snake_actualle_x_pos.empty()) {
			for (int i = 0; i < snake_actualle_x_pos.size(); i++)
			{
				if (p_snake->y_pos_head == p_snake->snake_actualle_y_pos[i] &&
					p_snake->x_pos_head == p_snake->snake_actualle_x_pos[i]) {

					// .... Deleting cut-off of snake part ....
					p_snake->snake_actualle_x_pos.erase(p_snake->snake_actualle_x_pos.begin(), p_snake->snake_actualle_x_pos.begin() + i + 1); // + 1 -- because head is one block
					p_snake->snake_actualle_y_pos.erase(p_snake->snake_actualle_y_pos.begin(), p_snake->snake_actualle_y_pos.begin() + i + 1); // + 1 -- because head is one block

					p_snake->snake_length -= i + 1; // + 1 -- because head is one block
					parameter.points -= i * 50;
				}
			}
		}

		if (parameter.points > parameter.last_speed_mod_in_point) {

			parameter.game_speed -= 10;

			parameter.last_speed_mod_in_point += 200;

			parameter.level++;

			parameter.next_level_from = parameter.last_speed_mod_in_point + 300;
		}


		// ---- Snake an grid respawning ----
		p_snake->Respawn(p_snake, grid.game_grid);

		parameter.points++;

		// ---- Menu drawing ----
		print.results(p_snake, p_eat, p_parameter);


		// ---- View update ----
		VIEW_UPDATE


			// ---- TIMER ----
			this_thread::sleep_for(chrono::milliseconds(parameter.game_speed));

	} while (game_life);
}

void Snake::Write(Parameter * p_parameter) {
	//write
	ofstream outfile;


	TCHAR windir[MAX_PATH];
	GetWindowsDirectory(windir, MAX_PATH);
	outfile.open(GetWindowsDirectory(windir, MAX_PATH) + "snakeData.txt", ios_base::app);


	string name;
	cout << "SAVING PLAYER GAME DATA" << endl;

	cout << "Player name: ";
	cin >> name;

	auto start = std::chrono::system_clock::now();
	// Some computation here
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	
	outfile << "Player name: " << name << "[" << p_parameter->points << "]" << "   LEVEL: " << p_parameter->level << "      "  << ctime(&end_time) << endl;
	

	outfile.close();
}

void Snake::message(string message) {
	string ch = " ";
	for (int i = 0; i < 50; i++)
	{
		ch += " ";
	}
	for (int i = 0; i < 3; i++)
	{
		for (int i = 0; i < 12; i++)
		{
			cout << endl;
		}

		cout << ch << "You are dead, dude :(" << endl;
		cout << ch << "       " << message << endl;
		this_thread::sleep_for(chrono::milliseconds(700));
		system("CLS");
		this_thread::sleep_for(chrono::milliseconds(700));
	}
}



