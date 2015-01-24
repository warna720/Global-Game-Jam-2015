#include "level.h"

#include <iostream>

Level::Level(int x, int y) : map(x, std::vector<Cell>(y)){}

Cell& Level::at(int x, int y)
{
	if (x+1 > map.size() || x < 0)
	{
		std::cerr << "X coord out of bounds" << std::endl;
		std::cerr << "X: " << x << std::endl;
		std::cerr << "XSize: " << map.size() << std::endl;

		exit(1);		
	}
	else if (y+1 > map[x].size() || y < 0)
	{
		std::cerr << "Y coord out of bounds" << std::endl;
		std::cerr << "Y: " << y << std::endl;
		std::cerr << "YSize: " << map[x].size()  << std::endl;

		exit(1);
	}

	return map[x][y];
}