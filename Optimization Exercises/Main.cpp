#include <iostream>
#include <stack>
#include <ctime>

using namespace std;
struct cell
{
	int x;
	int y;
	cell(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

int table[10][10];

int main()
{
	srand(time(0));
	int randomValue;
	int line, row = 0;
	int keyNumber;
	int replaceValue = 1;
	int test = 0;

	for (int i = 1; i < 11; i++) 
	{
		for (int j = 1; j < 11; j++)
		{
			randomValue = rand() % 5 + 5;
			if (randomValue < 7)
			{
				randomValue = 0;
			}
			table[i][j] = randomValue;
			cout << randomValue << " ";
		}
		cout << "\n";
	}
	cout << "Line: ";
	cin >> line;
	cout << "Row: ";
	cin >> row;

	stack <cell> cellsToCheck;
	cout << "The Key number is: " << table[line][row] << " and it will be replaced by 1\n";
	keyNumber = table[line][row];
	cell cellToTheStack = cell(line, row);
	cellsToCheck.push(cellToTheStack);


	while (!cellsToCheck.empty()) //So we'll loop as long as something is in the stack
	{
		cell currentCell = cell(0,0);
		if (!cellsToCheck.empty())
		{
			currentCell = cellsToCheck.top();
		}

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
				cell cellToTheStack = cell(cX + 1, cY);
				cellsToCheck.push(cellToTheStack);
			}
		}
		if (cX != 1)
		{
			//check top
			checkedValue = table[cX - 1][cY];
			if (keyNumber == checkedValue) {
				//feedStack(cX - 1, cY);

				cell cellToTheStack = cell(cX - 1, cY);
				cellsToCheck.push(cellToTheStack);

			}
		}
		if (cY != 10)
		{
			//check right
			checkedValue = table[cX][cY + 1];
			if (keyNumber == checkedValue) {
				cell cellToTheStack = cell(cX, cY + 1);
				cellsToCheck.push(cellToTheStack);
			}
		}
		if (cY != 1)
		{
			//check left
			checkedValue = table[cX][cY - 1];
			if (keyNumber == checkedValue) {
				cell cellToTheStack = cell(cX, cY - 1);
				cellsToCheck.push(cellToTheStack);
			}
		}
		test++;
	}

	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
			{	
				cout << table[i][j] << " ";
			}
			cout << "\n";
		}
	std::system("pause");
	return 0;
}
