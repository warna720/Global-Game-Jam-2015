#include "level.h"

#include <iostream>

#include "level_defs.h"

Level::Level(int x, int y) : map(y, std::vector<Cell>(x)){}

Cell& Level::at(int x, int y)
{
	if (y+1 > map.size() || y < 0)
	{
		std::cerr << "X coord out of bounds" << std::endl;
		std::cerr << "X: " << x << std::endl;
		std::cerr << "XSize: " << map.size() << std::endl;

		exit(1);		
	}
	else if (x+1 > map[y].size() || x < 0)
	{
		std::cerr << "Y coord out of bounds" << std::endl;
		std::cerr << "Y: " << y << std::endl;
		std::cerr << "YSize: " << map[x].size()  << std::endl;

		exit(1);
	}

	return map[y][x];
}

void Level::SetLevel( int lvl )
{
    for( int i=0; i < 24; ++i )
        for( int j=0; j < 32; ++j )
        {
            int id = levels[lvl][i][j];
            map[i][j].n = id;
            map[i][j].solid = level_map[id]; 
        }   
}
