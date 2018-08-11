#include <iostream>

using namespace std;

int main()
{
	int table[10][10];
	int randomValue;
	int line, row = 0;
	int keyNumber;
	int replaceValue = 1;

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
	cout << "The Key number is: " << table[line][row] << " and it will be replaced by 1\n";
	keyNumber = table[line][row];
	for (int i = 1; i < 11; i++)
	{
	for (int j = 1; j < 11; j++)
		{	
			if (table[i][j] == keyNumber)
			{
				table[i][j] = replaceValue;
			}
			cout << table[i][j] << " ";
		}
		cout << "\n";
	}


	cout << "Hey\n";
	system("pause");
	return 0;
}
void checkNeighbours(int line, int row, int valueToCheck, int currentValue)
{

}
