#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <array>
#include "Cell.h"
#include <algorithm>


using namespace std;

class Util
{
public:
	Util();
	~Util();

	vector<Cell> convertCellpointerIntoVector(Cell * _cell, int size);
	list<Cell> convertCellpointerIntoList(Cell * _cell, int size);

	Cell * sortCellArrayBasedOn_X(Cell * _cell, int size);

	vector<Cell> sortCellArrayBasedOn_X_Vector(Cell * _cell, int size);
	vector<Cell> sortCellArrayBasedOn_Y(Cell * _cell, int size);
	std::vector<Cell> convertCellIntoArray(Cell * cell, int size);
	vector<Cell> mergeSort(vector<Cell> _cell, int arrayLenght);
	vector<Cell> sort(vector<Cell> array1, vector<Cell> array2, int half1, int half2);

	float findDistanceBeetweenTwoPoints(Cell p1, Cell p2);
	

private:


	void mergeSort(vector<Cell> _cell, int from, int to, int half1, int half2);

};

