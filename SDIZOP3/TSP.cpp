#include "TSP.h"
#include <algorithm>
#include <iostream>
#include "Graph.h"

TSP::TSP()
{
}


TSP::~TSP()
{
}

std::vector<int> TSP::fullCheckAlgorithm(const Graph& graph)
{
	int currentWeight = 0;
	int minWeight = 99999;
	std::vector<int> result;
	std::vector<int> permutation(graph.getV());
	for (int i = 0; i < permutation.size(); i++) {
		permutation[i] = i;
	}

	std::sort(&permutation[0], &permutation[permutation.size() - 1]);

	do {
		bool skip = false;
		currentWeight = 0;
		for (int i = 0; i < permutation.size()-1; i++) {
			if (graph.adjacent(permutation[i], permutation[i + 1])) {
				currentWeight += graph.getEdgeValue(permutation[i], permutation[i + 1]);
			}
			else {
				skip = true;
				break;
			}
		}
		if (skip) continue;
		for (auto i : permutation) {
			std::cout << i;
		}
		std::cout << " Weight: " << currentWeight << "\n";
		if (currentWeight < minWeight) {
			minWeight = currentWeight;
			result = permutation;
		}
	} while (std::next_permutation(&permutation[0], &permutation[permutation.size() - 1]));

	std::cout << "Result: ";
	for (auto i : result) {
		std::cout << i;
	}
	std::cout << "\nWeight:" << minWeight << std::endl;


	return result;
}
