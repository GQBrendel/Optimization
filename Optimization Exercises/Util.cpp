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
	vector<cell> currentCell = _cell;
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
		left.push_back(currentCell[i]);
		std::cout << "\n I is " << i;
		std::cout << "\n Hello I'm left array and my number is " << left[i].x;
	}
	for (int i = 0; i < half2; i++)
	{
		right.push_back(currentCell[i + half1]);
		std::cout << "\n I is " << i + half1;
		std::cout << "\n Hello I'm right array and my number is " << right[i].x;
	}
	std::cout << std::endl;

	currentCell = sort(left, right, half1, half2, size);

	cout << "\nOrdered Output:\n";
	for (int i = 0; i < currentCell.size(); i++) {
		cout << "(" << currentCell[i].x << "," << currentCell[i].y << ") ";
	}

	return vector<cell>();

	//mergeSort(left);
	//mergeSort(right);
}

vector<cell> Util::sort(vector<cell> array1, vector<cell> array2, int half1, int half2, int size)
{
	vector<cell> orderedArray;

	cout << "\nSIZE IS " << size << endl << endl;

	int i1 = 0;
	int i2 = 0;

	for (int i = 0; i < size; i++)
	{
		if (array1[i1].x <= array2[i2].x && i1 < half1) {
			orderedArray.push_back(array1[i1]);
			i1++;
		}
		else if (i2 < half2) {
			orderedArray.push_back(array2[i2]);
			i2++;
		}
		if (i1 == half1) {
			while (i2 < half2) {
				orderedArray.push_back(array2[i2]);
				i2++;
				i++;
			}
		}
		else if (i2 == half2) {
			while (i1 < half1) {
				orderedArray.push_back(array1[i1]);
				i1++;
				i++;
			}
		}
	}
	return orderedArray;
}



