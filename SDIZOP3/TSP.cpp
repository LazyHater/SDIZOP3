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

bool TSP::nextPermutation(int * begin, int * end)
{
	//find longest non-increasing suffix 
	int* pivot = end;
	while ((pivot > begin)&&(*(pivot) <= *(pivot - 1))) 
		pivot--;
	

	//that is the last sequence
	if (pivot <= begin)
		return false;

	//identify pivot
	pivot--;

	int* succesor = end;
	while (*succesor <= *pivot) {
		succesor--;
	}

	//swap pivot and succesor
	int tmp = *pivot;
	*pivot = *succesor;
	*succesor = tmp;

	//reverse suffix
	pivot++;
	while (pivot < end) {
		int tmp = *pivot;
		*pivot = *end;
		*end = tmp;
		pivot++;
		end--;
	}

	return true;
}

std::vector<int> TSP::fullCheckAlgorithm(const Graph& graph)
{
	int currentWeight = 0;
	int minWeight = 99999;
	std::vector<int> result;
	int* permutation = new int[graph.getV()];
	int* best = new int[graph.getV()];

	for (int i = 0; i < graph.getV(); i++) {
		permutation[i] = i;
		best[i] = -1;
	}

	do {
		currentWeight = 0;
		for (int i = 0; i < graph.getV() - 1; i++) {
			currentWeight += graph.getEdgeValue(permutation[i], permutation[i + 1]);
		}
		currentWeight += graph.getEdgeValue(permutation[graph.getV() - 1], permutation[0]);

		if (currentWeight < minWeight) {
			minWeight = currentWeight;
			memcpy(best, permutation, graph.getV() * sizeof(int));
		}
	} while (nextPermutation(permutation, permutation + graph.getV() - 1));

	for (int i = 0; i < graph.getV(); i++) {
		result.push_back(best[i]);
	}

	delete permutation;
	delete best;
	return result;
}
