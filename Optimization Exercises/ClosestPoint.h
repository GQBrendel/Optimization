#pragma once
#include "cell.h"
#include <iostream>

class ClosestPoint
{
public:

	cell* addPoints();
	bool checkOnTable(int x, int y);
	void runClosestPoint();

	cell *cells;// = addPoints();
};

