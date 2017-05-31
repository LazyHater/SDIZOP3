#include <iostream>
#include <queue>
#include "Backpack.h"
#include "AdjacencyMatrix.h"
#include "TSP.h"

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
	graph.loadFile("C:\\Users\\Wakabajaszi\\Desktop\\dane.txt", true);
	std::cout << graph.toString() << "\n\n";

	TSP::fullCheckAlgorithm(graph);
	for (auto i : TSP::greedyAlgorithm(graph, 0)) {
		std::cout << i;
	}
	std::cout << std::endl;
	

	return 0;
}