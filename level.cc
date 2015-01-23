#include "level.h"

Level::Level(int x, int y) : map(x, std::vector<Cell>(y)){}

Cell& Level::at(int x, int y)
{
	return map[x][y];
}