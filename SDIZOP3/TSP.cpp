#include "TSP.h"
#include <algorithm>
#include <limits.h>

TSP::TSP()
{
}


TSP::~TSP()
{
}

std::vector<int> TSP::fullCheckAlgorithm()
{
	return std::vector<int>();
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
