#include "CellReplace.h"


CellReplace::CellReplace()
{
}


CellReplace::~CellReplace()
{
}
void CellReplace::runCellReplace()
{

	std::srand(time(0));


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			randomValue = rand() % 5 + 5;
			if (randomValue < 7)
			{
				randomValue = 0;
			}
			table[i][j] = randomValue;
			std::cout << randomValue << " ";
		}
		std::cout << "\n";
	}
	std::cout << "Line: ";
	std::cin >> line;
	std::cout << "Row: ";
	std::cin >> row;


	std::cout << "The Key number is: " << table[line][row] << " and it will be replaced by 1\n";
	keyNumber = table[line][row];
	Cell cellToTheStack = Cell(line, row);
	cellsToCheck.push(cellToTheStack);


	while (!cellsToCheck.empty()) //So we'll loop as long as something is in the stack
	{
		Cell currentCell = Cell(0, 0);
		currentCell = cellsToCheck.top();

		int checkedValue = -100;
		int cX = currentCell.x;
		int cY = currentCell.y;

		if (!cellsToCheck.empty())
		{
			cellsToCheck.pop(); //pop first and then feed if needed in the checks
			table[cX][cY] = 1;
		}
		if (cX != 10) //Check botton limit
		{
			//check botton
			checkedValue = table[cX + 1][cY];
			if (keyNumber == checkedValue) {
				//feedStack(cX + 1, cY);
				Cell cellToTheStack = Cell(cX + 1, cY);
				cellsToCheck.push(cellToTheStack);
			}
		}
		if (cX != 1)
		{
			//check top
			checkedValue = table[cX - 1][cY];
			if (keyNumber == checkedValue) {
				//feedStack(cX - 1, cY);

				Cell cellToTheStack = Cell(cX - 1, cY);
				cellsToCheck.push(cellToTheStack);

			}
		}
		if (cY != 10)
		{
			//check right
			checkedValue = table[cX][cY + 1];
			if (keyNumber == checkedValue) {
				Cell cellToTheStack = Cell(cX, cY + 1);
				cellsToCheck.push(cellToTheStack);
			}
		}
		if (cY != 1)
		{
			//check left
			checkedValue = table[cX][cY - 1];
			if (keyNumber == checkedValue) {
				Cell cellToTheStack = Cell(cX, cY - 1);
				cellsToCheck.push(cellToTheStack);
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << table[i][j] << " ";
		}
		std::cout << "\n";
	}

}
