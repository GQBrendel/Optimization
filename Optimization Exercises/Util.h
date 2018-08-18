#pragma once
#include <iostream>
#include <vector>
#include "Cell.h"


class Util
{
public:
	Util();
	~Util();

	std::vector<int> convertCellIntoXArray(cell *cell, int size);
	cell *mergeSort(int *cellToSort, int size);
};

