#pragma once

#define GRID_COL   20
#define GRID_ROW   20

#define EAT        '#'

struct Eat
{
public:
	int x_pos_eat;
	int y_pos_eat;

	void eat_respawn(char game_grid[GRID_COL][GRID_ROW]);
};

