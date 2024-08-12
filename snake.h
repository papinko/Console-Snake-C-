#pragma once
#include "grid.h"
#include "parameters.h"


#include <vector>
#include <string>


#define GRID_COL 20
#define GRID_ROW 20

using namespace std;

struct Snake
{

public: int snake_length = 0;
		int x_pos_head = 1;
		int y_pos_head = 1;

		int x_pos_last_block = 0;
		int y_pos_last_block = 0;

		vector<int> snake_actualle_x_pos;
		vector<int> snake_actualle_y_pos;

		void x_pos_left_move(Snake* p_snake, char game_grid[GRID_COL][GRID_ROW], int* last_key);
		void x_pos_right_move(Snake* p_snake, char game_grid[GRID_COL][GRID_ROW], int* last_key);

		void y_pos_down_move(Snake* p_snake, char game_grid[GRID_COL][GRID_ROW], int* last_key);
		void y_pos_up_move(Snake* p_snake, char game_grid[GRID_COL][GRID_ROW], int* last_key);
		void Respawn(Snake* p_snake, char game_grid[GRID_COL][GRID_ROW]);
		void Moving(Snake* p_snake);
		void message(string text);
		void Write(Parameter * p_parameter);
};