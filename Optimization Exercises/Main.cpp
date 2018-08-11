#include <iostream>

using namespace std;

int main()
{
	int table[10][10];
	int randomValue;
	int line, row = 0;
	int keyNumber;

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
	/*for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			cout << "[" << i << "]" << "[" << j <<  "]" << " ";
		}
		cout << "\n";
	}*/
	cout << "Choose a key number to change: " << "\n";
	cin >> keyNumber;
	cout << "Line: ";
	cin >> line;
	cout << "Row: ";
	cin >> row;
	cout << "The coosed value is: " << table[line][row] << "\n";


	cout << "Hey\n";
	system("pause");
	return 0;
}
