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
	int minWeight = INT_MAX;
	std::vector<int> result;
	std::vector<int> permutation(graph.getV);
	for (int i = 0; i < permutation.size(); i++) {
		permutation[i] = i;
	}

	std::sort(&permutation[0], &permutation[permutation.size() - 1]);

	do {
		for (auto i : permutation) {
			std::cout << i;
		}
		std::cout << "\n";

		for (int i = 0; i < permutation.size()-1; i++) {
			currentWeight += graph.getEdgeValue(i, i + 1);
		}
		if (currentWeight < minWeight) {
			minWeight = currentWeight;
			result = permutation;
		}
	} while (std::next_permutation(&permutation[0], &permutation[permutation.size() - 1]));

	for (auto i : result) {
		std::cout << i;
	}
	std::cout << "\n" << minWeight << std::endl;


	return result;
}
