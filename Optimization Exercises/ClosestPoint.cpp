#include "ClosestPoint.h"



cell* ClosestPoint::addPoints()
{

	cells = new cell[16]
	//I abstracted the floating points
	  { cell(-13, 0.5), cell(-10.5, -11.5),
		cell(-10, 9), cell(-4.5, -2), cell(-1, 8.5),
		cell(0.5, 6), cell(0.5, -12), cell(2, 12.5),
		cell(3.5, 11), cell(5.5, 3), cell(5.5, -7),
		cell(5, 11.5), cell(6.5, 3.2), cell(7, -10),
		cell(9, -5), cell(11.5, -4)
	};


	for (int i = 0; i < 16; i++) {
		std::cout << "(" << cells[i].x << "," << cells[i].y << "), " ;
	}
	return cells;
}
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
	char table[50][50];


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
				table[i][j] = 'X';

			}
			std::cout << table[i][j] << ' ';
		}
		std::cout << "\n";
	}
}
