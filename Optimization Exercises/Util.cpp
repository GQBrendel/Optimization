#include "Util.h"



Util::Util()
{
}


Util::~Util()
{
}




cell * Util::mergeSort(int * cellToSort, int size)
{
	float middle = (1 + size) / 2;

	int * rightArray;
	rightArray = new int[size];

	for (int i = 0; i < middle; i++)
	{
		//rightArray[i] = cellToSort[i].x;
	}

	int * leftArray;
	leftArray = new int[size];

	for (int i = middle; i < size; i++)
	{
		//leftArray[i] = cellToSort[i].x;
	}

	mergeSort(rightArray, middle);
	mergeSort(cellToSort, middle+1);

	return nullptr;
}

std::vector<int> Util::convertCellIntoXArray(cell * cell, int size)
{
	std::vector<int> resultVector;

	for (int i = 0; i < size; i++)
	{
		resultVector.push_back(cell[i].x);
	}

	return resultVector;
}

