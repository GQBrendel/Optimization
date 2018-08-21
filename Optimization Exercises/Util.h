#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Cell.h"
#include <algorithm>


using namespace std;

class Util
{
public:
	Util();
	~Util();

	vector<cell> convertCellpointerIntoVector(cell * _cell, int size);
	list<cell> convertCellpointerIntoList(cell * _cell, int size);
	std::vector<int> convertCellIntoXArray(cell *cell, int size);
	vector<cell> mergeSort(vector<cell> _cell, int arrayLenght);
	vector<cell> sort(vector<cell> array1, vector<cell> array2, int half1, int half2);

private:


	void mergeSort(vector<cell> _cell, int from, int to, int half1, int half2);

};

