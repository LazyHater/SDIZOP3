#pragma once
#include <vector>
#include "Graph.h"
class TSP
{
public:
	TSP();
	~TSP();

	static std::vector<int> fullCheckAlgorithm(const Graph& graph);
};

