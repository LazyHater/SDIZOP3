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
	AdjacencyMatrix graph;
	graph.loadRawFromFile("C:\\Users\\Wakabajaszi\\Desktop\\dane_raw.txt");
	std::cout << graph.toString() << "\n\n";

	TSP::fullCheckAlgorithm(graph);
	for (auto i : TSP::greedyAlgorithm(graph, 0)) {
		std::cout << i;
	}
	std::cout << std::endl << BackpackProblem::solveGreedyApproximation(BackpackProblem::getRandomItems(20, 0, 100, 1, 10), 30).toString() << "\n\n\n";
	std::vector<Item> vec;
	int bp_w;

	BackpackProblem::loadFromFile("C:\\Users\\Wakabajaszi\\Desktop\\bpp.txt", vec, bp_w);
	Backpack bp(bp_w);
	for (auto& it : vec)
		bp.addItem(&it);
	std::cout << bp.toString() << "\n";

	//PerformanceTests::makeBackpackTests();
	return 0;
}