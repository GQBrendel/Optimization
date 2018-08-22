#include "ClosestPoint.h"
/*
Algorithm to find the closest pair of points,
thanks for learning at: https://www.geeksforgeeks.org/closest-pair-of-points/
*/

using namespace std;


void ClosestPoint::runClosestPoint()
{
	srand(time(NULL));
	char table[40][40];

	cout << "This program check on a table of 16 random points with the value beetween\n (-20,-20) , (20,20)"
		<< " and find the closest point\n";
	
	/*Cell pointsArray[] = { { -13, 0 }, { -10, -11 },{ -10, 9 },{ -4, -2 },{ -1, 8 },
	{ 0, 6 },{ 0, -12 },{ 2, 12 },	{ 3, 11 },{ 5, 3 },{ 5, -7 }, 
	{ 5, 11 },{ 6, 3 },{ 7, -10 }, 	{ 9, -5 },{ 11, -4 } };*/

	//Fill the table with random numbers, I know this looks ugly
	Cell pointsArray[] = { { rng(), rng() }, { rng(), rng() },{ rng(), rng() },{ rng(), rng() },{ rng(), rng() },
	{ rng(), rng() },{ rng(), rng() },{ rng(), rng() },	{ rng(), rng() },{ rng(), rng() },{ rng(), rng() },
	{ rng(), rng() },{ rng(), rng() },{ rng(), rng() }, { rng(), rng() },{ rng(), rng() } };

	//Then print the table
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (checkOnTable(pointsArray, i-20, j-20)) {
				table[i][j] = 'O';
			}
			else if (i-20 == 0 || j-20 == 0)
			{
				table[i][j] = '.';
			}
			else
			{
				table[i][j] = '_';

			}
			std::cout << table[i][j] << ' ';
		}
		std::cout << "\n";
	}

	int size = sizeof(pointsArray) / sizeof(pointsArray[0]);

	printf("\nThe smallest distance is %f ", closest(pointsArray, size));

	cout << "\n\nPoint A: ";
	cout << "(" << pointA.x << "," << pointA.y << "), ";
	cout << "\nPoint B: ";
	cout << "(" << pointB.x << "," << pointB.y << "), ";

	cout << endl;

	//Print it again with the reult
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if ((i-20 == pointA.x && j-20 == pointA.y) || (i-20 == pointB.x && j-20 == pointB.y))
			{
				table[i][j] = 'X';
			}
			std::cout << table[i][j] << ' ';
		}
		std::cout << "\n";
	}
}

int ClosestPoint::rng()
{
	//I choose a random distribution instead of a pseudo random to get more variation
	std::mt19937 result;
	result.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 40); // distribution in range [0, 40]

	return (dist(result) - 20);
}

bool ClosestPoint::checkOnTable(Cell points[], int x, int y)
{
	bool result = false;
	for (int i = 0; i < 16; i++) {

		if (points[i].x == x && points[i].y == y)
		{
			result = true;
			return result;
		}
	}
	return result;
}
// A Brute Force method to return the smallest distance between two points
// in P[] of size n
float ClosestPoint::bruteForce(Cell P[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (util.findDistanceBeetweenTwoPoints(P[i], P[j]) < minimum)
			{
				pointA = P[i];
				pointB = P[j];
				minimum = util.findDistanceBeetweenTwoPoints(P[i], P[j]);
			}
		}
	}
	/*
	cout << "\nPoint A: ";
	cout << "(" << pointA.x << "," << pointA.y << "), ";
	cout << "\nPoint B: ";
	cout << "(" << pointB.x << "," << pointB.y << "), ";
	cout << "\n Min is " << minimum; cout << endl;
	*/
	return minimum;
}
float ClosestPoint::stripClosest(Cell strip[], int size, float d)
{
	minimum = d;

	util.convertCellpointerIntoList(strip, size);
	vector<Cell> sortedStrip  = util.sortCellArrayBasedOn_Y(strip,size);
	
	// Pick all points one by one and try the next points till the difference
	// between y coordinates is smaller than d.
	// This is a proven fact that this loop runs at most 6 times
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size && (sortedStrip[j].y - sortedStrip[i].y) < minimum; ++j)
		{
			if (util.findDistanceBeetweenTwoPoints(sortedStrip[i], sortedStrip[j]) < minimum)
			{
				pointA = sortedStrip[i];
				pointB = sortedStrip[j];
				minimum = util.findDistanceBeetweenTwoPoints(sortedStrip[i], sortedStrip[j]);
			}
		}
	}
	/*
	cout << "\nPoint A: ";
	cout << "(" << pointA.x << "," << pointA.y << "), ";
	cout << "\nPoint B: ";
	cout << "(" << pointB.x << "," << pointB.y << "), ";
	cout << "\n Min is " << minimum; cout << endl;
	*/
	return minimum;
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

