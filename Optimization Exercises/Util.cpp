#include "Util.h"



Util::Util()
{
}


Util::~Util()
{
}

vector<cell> Util::convertCellpointerIntoVector(cell * _cell, int size)
{
	std::vector<cell> result;

	for (int i = 0; i < size; i++)
	{
		result.push_back(_cell[i]);
	}

	return result;
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

vector<cell> Util::mergeSort(vector<cell> _cell)
{
	int size = _cell.size();
	int half1, half2;

	cout << "\n Olha o size " << size;

	if (size % 2 == 0) {
		half1 = half2 = size / 2;
	}
	else {
		half1 = size / 2 + 1;
		half2 = size / 2;
	}
	std::cout << "\n Hafl 1 is " << half1;
	std::cout << "\n Hafl 2 is " << half2;

	std::vector<cell> left;
	std::vector<cell> right;

	for (int i = 0; i < half1; i++)
	{
		left.push_back(_cell[i]);
		std::cout << "\n I is " << i;
		std::cout << "\n Hello I'm left array and my number is " << left[i].x;
	}
	for (int i = 0; i < half2; i++)
	{
		right.push_back(_cell[i + half1]);
		std::cout << "\n I is " << i + half1;
		std::cout << "\n Hello I'm left array and my number is " << right[i].x;
	}
	std::cout << std::endl;

	return vector<cell>();

	//mergeSort(left);
	//mergeSort(right);
}



