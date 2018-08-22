#include "Util.h"



Util::Util()
{
}


Util::~Util()
{
}

vector<Cell> Util::convertCellpointerIntoVector(Cell * _cell, int size)
{
	std::vector<Cell> result;

	for (int i = 0; i < size; i++)
	{
		result.push_back(_cell[i]);
	}
	return result;
}

list<Cell> Util::convertCellpointerIntoList(Cell * _cell, int size)
{
	std::list<Cell> result;
	for (int i = 0; i < size; i++)
	{
		result.push_back(_cell[i]);
	}
	return result;
}
Cell* Util::sortCellArrayBasedOn_X(Cell * _cell, int size)
{
	Cell *result;
	result = new Cell[size];
	std::list<Cell> listToSort;
	for (int i = 0; i < size; i++)
	{
		listToSort.push_back(_cell[i]);
	}
	listToSort.sort([](const Cell &f, const Cell &s) { return f.x < s.x; });
	for (int i = 0; i < size; i++)
	{
		result[i] = listToSort.front();
		listToSort.pop_front();
	}
	return result;
}
vector<Cell> Util::sortCellArrayBasedOn_X_Vector(Cell * _cell, int size)
{
	vector<Cell> result;
	std::list<Cell> listToSort;
	for (int i = 0; i < size; i++)
	{
		listToSort.push_back(_cell[i]);
	}
	listToSort.sort([](const Cell &f, const Cell &s) { return f.x < s.x; });
	for (int i = 0; i < size; i++)
	{
		result.push_back(listToSort.front());
		listToSort.pop_front();
	}
	return result;
}
vector<Cell> Util::sortCellArrayBasedOn_Y(Cell * _cell, int size)
{
	vector<Cell> result;
	std::list<Cell> listToSort;
	for (int i = 0; i < size; i++)
	{
		listToSort.push_back(_cell[i]);
	}
	listToSort.sort([](const Cell &f, const Cell &s) { return f.y < s.y; });
	for (int i = 0; i < size; i++)
	{
		result.push_back(listToSort.front());
		listToSort.pop_front();
	}
	return result;
}

std::vector<int> Util::convertCellIntoXArray(Cell * cell, int size)
{
	std::vector<int> resultVector;

	for (int i = 0; i < size; i++)
	{
		resultVector.push_back(cell[i].x);
	}

	return resultVector;
}

vector<Cell> Util::mergeSort(vector<Cell> _cell, int size)
{
	vector<Cell> currentCell = _cell;
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

	std::vector<Cell> left;
	std::vector<Cell> right;

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
	//mergeSort(left, 0, half1, half1, half2);
	//mergeSort(right, half2, size, half1, half2);

	return right;
}

void Util::mergeSort(vector<Cell> _cell, int from, int to, int half1, int half2)
{
	if (to - from < 2)
		return;

	std::vector<Cell> left;
	std::vector<Cell> right;

	for (int i = from; i < (to + from) / 2; i++) {
		left.push_back(_cell[i]);
	}
	for (int i = (to + from) / 2; i < to; i++) {
		right.push_back(_cell[i]);
	}

	mergeSort(left, from, (to + from) / 2, half1, half2);
	mergeSort(right, (to + from) / 2, to, half1, half2);


	sort(left, right, half1, half2);
}

vector<Cell> Util::sort(vector<Cell> array1, vector<Cell> array2, int half1, int half2)
{
	vector<Cell> orderedArray;
	int size = array1.size() + array2.size();

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

float Util::findDistanceBeetweenTwoPoints(Cell p1, Cell p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
		(p1.y - p2.y)*(p1.y - p2.y));
}
