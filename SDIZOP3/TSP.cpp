#include "TSP.h"
#include "Graph.h"

#include <algorithm>
#include <iostream>
#include <limits.h>


TSP::TSP()
{
}


TSP::~TSP()
{
}


std::vector<int> TSP::greedyAlgorithm(const Graph & graph, int start_v)
{
	std::vector<int> visited, result;

	int current = start_v;
	for (int i = 0; i < graph.getV(); i++) {
		auto neightbours = graph.neighbors(current);
		int min = INT_MAX / 2;
		int min_v = -1;

		for (int vertex : neightbours)
			if (graph.getEdgeValue(current, vertex) < min)
				if (std::find(visited.begin(), visited.end(), vertex) == visited.end()) {
					min = graph.getEdgeValue(current, vertex);
					min_v = vertex;
				}
		
		if (min_v < 0) {
			std::cerr << "Could not complete graph!\n";
			return result;
		}

		result.push_back(min_v);
	}

	return result;
}

std::vector<int> TSP::fullCheckAlgorithm(const Graph& graph)
{
	int currentWeight = 0;
	int minWeight = INT_MAX;
	std::vector<int> result;
	std::vector<int> permutation(graph.getV());
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
