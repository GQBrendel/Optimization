#pragma once
#include <iostream>
#include <stack>
#include <ctime>
#include <cstdlib>
#include "Cell.h"

class CellReplace
{
public:
	

	std::stack <cell> cellsToCheck;
	int table[10][10];
	int randomValue;
	int line, row = 0;
	int keyNumber;
	int replaceValue = 1;
	int test = 0;



	CellReplace();
	~CellReplace();
	void runCellReplace();
};

