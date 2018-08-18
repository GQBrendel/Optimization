#pragma once
#include <vector>

struct cell
{
	int x;
	int y;
	cell(int _x, int _y)
	{		
		x = _x;
		y = _y;
	}
	cell()
	{
		x = 0; y = 0;
	}
};
