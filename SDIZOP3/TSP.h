#pragma once
#include "AdjacencyMatrix.h"
#include <vector>
class TSP
{
public:
	TSP();
	~TSP();
	static std::vector<int> fullCheckAlgorithm(const Graph& graph);

private:
	void elo();
};

