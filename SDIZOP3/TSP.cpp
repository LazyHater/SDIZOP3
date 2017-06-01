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
	std::vector<int> visited;

	int current = start_v;
	visited.push_back(current);

	for (int i = 0; i < graph.getV() - 1; i++) {
		auto neightbours = graph.neighbors(current);
		int min = INT_MAX / 2;
		int min_v = -1;

		for (int vertex : neightbours)
			//if it is 'closer' than min
			if (graph.getEdgeValue(current, vertex) < min)
				//and not visited yet
				if (std::find(visited.begin(), visited.end(), vertex) == visited.end()) {
					min = graph.getEdgeValue(current, vertex);
					min_v = vertex;
				}
		
		if (min_v < 0) {
			std::cerr << "Could not complete graph!\n";
			return visited;
		}
		
		visited.push_back(min_v);
		current = min_v;
	}

	return visited;
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

		currentWeight += graph.getEdgeValue(permutation[permutation.size() - 1], permutation[0]);

		if (skip) continue;

		if (currentWeight < minWeight) {
			minWeight = currentWeight;
			result = permutation;
		}
	} while (std::next_permutation(&permutation[0], &permutation[permutation.size() - 1]));

	return result;
}
