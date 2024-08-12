#pragma once

struct Parameter
{
public:
	const int grid_col = 20;
	const int grid_row = 20;

	int game_speed;
	int last_speed_mod_in_point = 200;
	int points = 0;
	int level = 1;
	int next_level_from = 0;
};