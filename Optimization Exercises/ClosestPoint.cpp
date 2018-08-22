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

	//vector<Cell> resposta = util.sortCellArrayBasedOn_X_Vector(cells, 16);
	Cell *resposta;
	resposta = util.sortCellArrayBasedOn_X(cells, 16);

	cout << "\n So here we are again " << resposta[0].x;
	testaStrip(cells);

	cout << endl;

	//Cell P[] = { { 2, 3 },{ 12, 30 },{ 40, 50 },{ 5, 1 },{ 12, 10 },{ 3, 4 } };

	Cell P[] = { {-13, 0}, {-10, -11}, {-10, 9}, {-4, -2}, {-1, 8},
		{0, 6}, {0, -12}, {2, 12},
		{3, 11}, {5, 3}, {5, -7},
		{5, 11}, {6, 3}, {7, -10},
		{9, -5}, {11, -4} };

	int size = sizeof(P) / sizeof(P[0]);
	cout << "\nOlha que louco esse n tio " << size;
	printf("\nThe smallest distance is %f ", closest(P, size));

	cout << "\nPoint A: ";
	cout << "(" << pointA.x << "," << pointA.y << "), ";
	cout << "\nPoint B: ";
	cout << "(" << pointB.x << "," << pointB.y << "), ";

	cout << endl;
	//return 0;


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
	//Cell p1, p2;
	//float min = FLT_MAX;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (util.findDistanceBeetweenTwoPoints(P[i], P[j]) < minimo)
			{
				pointA = P[i];
				pointB = P[j];
				minimo = util.findDistanceBeetweenTwoPoints(P[i], P[j]);
			}
		}
	}
	cout << "\nPoint A: ";
	cout << "(" << pointA.x << "," << pointA.y << "), ";


	cout << "\nPoint B: ";
	cout << "(" << pointB.x << "," << pointB.y << "), ";
	cout << "\n Min is " << minimo; cout << endl;
	return minimo;
}
float ClosestPoint::stripClosest(Cell strip[], int size, float d)
{
	//float min = d;  // Initialize the minimum distance as d
	minimo = d;

	util.convertCellpointerIntoList(strip, size);
	vector<Cell> sortedStrip  = util.sortCellArrayBasedOn_Y(strip,size);
	
	// Pick all points one by one and try the next points till the difference
	// between y coordinates is smaller than d.
	// This is a proven fact that this loop runs at most 6 times
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size && (sortedStrip[j].y - sortedStrip[i].y) < minimo; ++j)
		{
			cout << "\nRole uma "  + i;
			if (util.findDistanceBeetweenTwoPoints(sortedStrip[i], sortedStrip[j]) < minimo)
			{
				pointA = sortedStrip[i];
				pointB = sortedStrip[j];
				minimo = util.findDistanceBeetweenTwoPoints(sortedStrip[i], sortedStrip[j]);
			}
		}
	}
	cout << "\nPoint A: ";
	cout << "(" << pointA.x << "," << pointA.y << "), ";


	cout << "\nPoint B: ";
	cout << "(" << pointB.x << "," << pointB.y << "), ";
	cout << "\n Min is " << minimo; cout << endl;
	return minimo;
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
//float ClosestPoint::closestUtil(Cell P[], int n)

float ClosestPoint::closestUtil(Cell P[], int n)
{
	// If there are 2 or 3 points, then use brute force
	if (n <= 3)
		return bruteForce(P, n);

	// Find the middle point
	int mid = n / 2;
	Cell midPoint = P[mid];

	// Consider the vertical line passing through the middle point
	// calculate the smallest distance dl on left of middle point and
	// dr on right side
	float dl = closestUtil(P, mid);
	float dr = closestUtil(P + mid, n - mid);

	// Find the smaller of two distances
	float d = min(dl, dr);

	// Build an array strip[] that contains points close (closer than d)
	// to the line passing through the middle point
	Cell *strip;
	strip = new Cell[n];
//	Cell strip[n];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(P[i].x - midPoint.x) < d)
			strip[j] = P[i], j++;

	// Find the closest points in strip.  Return the minimum of d and closest
	// distance is strip[]
	return min(d, stripClosest(strip, j, d));
}
// The main functin that finds the smallest distance
// This method mainly uses closestUtil()
float ClosestPoint::closest(Cell P[], int n)
{
	//qsort(P, n, sizeof(Cell), compareX);
	Cell *sortedP =  util.sortCellArrayBasedOn_X(P, n);
	
	// Use recursive function closestUtil() to find the smallest distance
	return closestUtil(sortedP, n);
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

