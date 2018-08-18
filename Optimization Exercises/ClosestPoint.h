#pragma once
#include "cell.h"
#include <iostream>
#include "Util.h"

class ClosestPoint
{
public:

	cell* addPoints();
	bool checkOnTable(int x, int y);
	void runClosestPoint();

	cell *cells;
	Util util;
};

