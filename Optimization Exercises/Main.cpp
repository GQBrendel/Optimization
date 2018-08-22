#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "CellReplace.h"
#include "ClosestPoint.h"

using namespace std;
int main()
{

	CellReplace cellReplace;
	ClosestPoint closestPoint;

	closestPoint.runClosestPoint();
	//cellReplace.runCellReplace();

	
	std::system("pause");
	return 0;
}
