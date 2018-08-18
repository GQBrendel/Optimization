#include "Util.h"



Util::Util()
{
}


Util::~Util()
{
}




cell * Util::mergeSort(cell * cellToSort, int size)
{
	int middle = (1 + size) / 2;
	std::cout << "\n Middle is " << middle;

	std::vector<cell> left;
	std::vector<cell> right;

	/*
	cell * leftArray;
	cell * rightArray;
	leftArray = new cell[size];
	rightArray = new cell[size];
	*/
	for (int i = 0; i < middle; i++)
	{
		left.push_back(cellToSort[i]);
		std::cout << "\n I is " << i;
		std::cout << "\n Hello I'm left array and my number is " << left[i].x;
	}
	for (int i = 0; i < middle; i++)
	{
		right.push_back(cellToSort[i+middle]);
		std::cout << "\n I is " << i+middle;
		std::cout << "\n Hello I'm left array and my number is " << right[i].x;
	}
	std::cout << std::endl;

	//mergeSort(rightArray, middle);
	//mergeSort(cellToSort, middle+1);

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

