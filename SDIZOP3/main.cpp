#include <iostream>
#include <queue>
#include "Backpack.h"
#include "AdjacencyMatrix.h"
#include "TSP.h"

int main() {
	AdjacencyMatrix graph;
	graph.loadFile("C:\\Users\\Razoff\\Desktop\\dane_droga.txt", 0);
	std::cout << graph.toString() << "\n\n";

	TSP::fullCheckAlgorithm(graph);

	return 0;
}