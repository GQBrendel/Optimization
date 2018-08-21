#include "ClosestPoint.h"
/*
Algorithm to find the closest pair of points,
thanks for learning at: https://www.geeksforgeeks.org/closest-pair-of-points/
*/

using namespace std;


bool ClosestPoint::checkOnTable( int x, int y)
{
	bool result = false;
	for (int i = 0; i < 16; i++) {

		if (cells[i].x == x && cells[i].y == y)
		{
			result = true;
			return result;
		}
	}
	return result;
}
void ClosestPoint::runClosestPoint()
{
	char table[40][40];


	//First of all get a list of points and add to the stack
	cells = addPoints();

	//Then print the table
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (checkOnTable(i-20,j-20)) {
				table[i][j] = 'O';
			}
			else
			{
				table[i][j] = '_';

			}
			std::cout << table[i][j] << ' ';
		}
		std::cout << "\n";
	}

	//vector<cell> cellsVector = util.convertCellpointerIntoVector(cells, 16);
	
	//Coonvert in a list
	list<Cell> cellsList = util.convertCellpointerIntoList(cells, 16);
	
	//sort it based on X
	cellsList.sort([](const Cell &f, const Cell &s) { return f.x < s.x; });

	vector<Cell> resposta = util.sortCellArrayBasedOn_X(cells, 16);

	resposta = util.sortCellArrayBasedOn_Y(cells, 16);

	cout << "\n So here we are again " << resposta[0].y;
	testaStrip(cells);

	//util.mergeSort(cellsVector, cellsVector.size());
}
void ClosestPoint::testaStrip(Cell strip[])
{
	cout << "Recebeu como parametro " << strip[0].x;
}
// A Brute Force method to return the smallest distance between two points
// in P[] of size n
float ClosestPoint::bruteForce(Cell P[], int n)
{
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (util.findDistanceBeetweenTwoPoints(P[i], P[j]) < min)
				min = util.findDistanceBeetweenTwoPoints(P[i], P[j]);
	return min;
}
float ClosestPoint::stripClosest(Cell strip[], int size, float d)
{
	float min = d;  // Initialize the minimum distance as d

	util.convertCellpointerIntoList(strip, size);
	vector<Cell> sortedStrip  = util.sortCellArrayBasedOn_Y(strip,size);
	
	// Pick all points one by one and try the next points till the difference
	// between y coordinates is smaller than d.
	// This is a proven fact that this loop runs at most 6 times
	for (int i = 0; i < size; ++i)
		for (int j = i + 1; j < size && (sortedStrip[j].y - sortedStrip[i].y) < min; ++j)
			if (util.findDistanceBeetweenTwoPoints(sortedStrip[i], sortedStrip[j]) < min)
				min = util.findDistanceBeetweenTwoPoints(sortedStrip[i], sortedStrip[j]);

	return min;
}
// Needed to sort array of points according to X coordinate
int ClosestPoint::compareX(const void* a, const void* b)
{
	Cell *p1 = (Cell *)a, *p2 = (Cell *)b;
	return (p1->x - p2->x);
}
// Needed to sort array of points according to Y coordinate
int ClosestPoint::compareY(const void* a, const void* b)
{
	Cell *p1 = (Cell *)a, *p2 = (Cell *)b;
	return (p1->y - p2->y);
}

Cell* ClosestPoint::addPoints()
{
	cells = new Cell[16]
		//I abstracted the floating points
	{ Cell(13, 0.5), Cell(-10.5, -11.5),
		Cell(-10, 9), Cell(-4.5, -2), Cell(-1, 8.5),
		Cell(0.5, 6), Cell(0.5, -12), Cell(2, 12.5),
		Cell(-12, 11), Cell(-8, 3), Cell(-5, -7),
		Cell(5, 11.5), Cell(6.5, 3.2), Cell(7, -10),
		Cell(9, -5), Cell(11.5, -4)
	};
	/*for (int i = 0; i < 16; i++) {
	std::cout << "(" << cells[i].x << "," << cells[i].y << "), " ;
	}*/
	return cells;
}

