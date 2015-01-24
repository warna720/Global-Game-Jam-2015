#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

#include "cell.h"

class Level
{

public:
	Level(int x, int y);

	Cell& at(int x, int y);
	
	void SetLevel( int lvl );

private:
	std::vector< std::vector<Cell> > map;
};

#endif
