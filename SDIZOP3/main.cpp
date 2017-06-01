#include <iostream>
#include <queue>
#include "Backpack.h"
#include "AdjacencyMatrix.h"
#include "TSP.h"
#include "BackpackProblem.h"
#include "PerformanceTests.h"

/*GRAF TESTOWY
8 6
0 1 5
0 5 2
1 2 3
1 3 1
2 4 3
3 4 3
3 5 1
4 5 4*/

int main() {
	PerformanceTests::makeBackpackTests();
	PerformanceTests::makeTspTests();
	return 0;
}