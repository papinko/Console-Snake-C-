
#include "grid.h"
#include <iostream>

using namespace std;

#define GRID_COL    20
#define GRID_ROW    20
#define EMPTY_BLOCK ' '
#define GRID_UPDATE(grid) grid_update(grid)



void Grid::grid_update(char grid[GRID_COL][GRID_ROW]) {

	for (int i = 0; i < GRID_COL; i++) {
		cout << "|";
		for (int j = 0; j < GRID_ROW; j++) {
			cout << grid[i][j] << EMPTY_BLOCK;
			//cout << "|";
		}
		cout << "|";
		cout << endl;
	}
	cout << "------------------------------------------" << endl;
}