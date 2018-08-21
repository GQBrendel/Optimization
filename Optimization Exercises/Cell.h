#pragma once
#include <vector>

struct Cell
{
	int x;
	int y;
	Cell(int _x, int _y)
	{		
		x = _x;
		y = _y;
	}
	Cell()
	{
		x = 0; y = 0;
	}
};
