#include "eat.h"
#include <iostream>


void Eat::eat_respawn(char game_grid[GRID_COL][GRID_ROW]) {

	Eat::x_pos_eat = rand() % GRID_ROW;
	Eat::y_pos_eat = rand() % GRID_COL;

	game_grid[y_pos_eat][x_pos_eat] = EAT;
}