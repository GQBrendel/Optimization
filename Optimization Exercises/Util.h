#pragma once
#include <iostream>
#include <vector>
#include "Cell.h"


using namespace std;

class Util
{
public:
	Util();
	~Util();

	vector<cell> convertCellpointerIntoVector(cell * _cell, int size);
	std::vector<int> convertCellIntoXArray(cell *cell, int size);
	vector<cell> mergeSort(vector<cell> _cell);
	vector<cell> sort(vector<cell> array1, vector<cell> array2, int half1, int half2, int size);
};

