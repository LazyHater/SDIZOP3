#include "TSP.h"
#include <algorithm>


TSP::TSP()
{
}


TSP::~TSP()
{
}

std::vector<int> TSP::fullCheckAlgorithm(const Graph& graph)
{
	std::vector<int> permutation(graph.getV);

	for (int i = 0; i < permutation.size(); i++) {
		permutation[i] = i;
	}

	std::next_permutation(permutation, permutation + graph.getV);

	/*if (permutation.size() == 1) {
		return permutation;
	}
	else {
		for (int i = 1; i < permutation.size(); i++) {

		}
	}

	if k == 1
		print P
	else
		for i = 1 to k do
			swap P[i]↔P[k]
			perm(k - 1)
			swap P[i]↔P[k]*/



	return std::vector<int>();
}


