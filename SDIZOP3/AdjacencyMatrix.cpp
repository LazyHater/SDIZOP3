#include "AdjacencyMatrix.h"
#include "Edge.h"
#include <climits>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>

AdjacencyMatrix::AdjacencyMatrix(const AdjacencyMatrix & obj)
{
	for (auto vec : obj.matrix)
		matrix.push_back(std::vector<int>(vec));
	V = obj.V;
	E = obj.E;
}

AdjacencyMatrix::~AdjacencyMatrix()
{
}

bool AdjacencyMatrix::adjacent(int x, int y) const
{
	return INT_MAX != matrix[x][y];
}

std::deque<int> AdjacencyMatrix::neighbors(int x) const
{
	std::deque<int> tmp;
	for (int i = 0; i < matrix.size(); i++)
		if (matrix[x][i] != INT_MAX)
			tmp.push_back(i);
	return tmp;
}

Graph & AdjacencyMatrix::addVertex(int x)
{
	while (x >= matrix.size()) {
		for (auto& vec : matrix) {
			vec.push_back(INT_MAX);
		}
		std::vector<int> vec;
		for (int i = 0; i <= matrix.size(); i++)
			vec.push_back(INT_MAX);

		matrix.push_back(vec);
		V++;
	}
	return *this;
}

Graph & AdjacencyMatrix::addEdge(int x, int y, int val, bool isDirected)
{
	if (x >= matrix.size())
		addVertex(x);

	if (y >= matrix.size())
		addVertex(y);

	if (isDirected) {
		if (matrix[x][y] == INT_MAX)
			E++;

		matrix[x][y] = val;
	}
	else {
		if (matrix[x][y] == INT_MAX || matrix[y][x] == INT_MAX)
			E++;

		matrix[x][y] = val;
		matrix[y][x] = val;
	}

	return *this;
}

int AdjacencyMatrix::getEdgeValue(int x, int y) const
{
	return matrix[x][y];
}

std::string AdjacencyMatrix::toString() const
{
	std::stringstream ss;
	ss << "Adjacency matrix, V: " << V << " E: " << E << "\n";
	for (auto& vec : matrix) {
		for (int val : vec) {
			if (val == INT_MAX)
				ss << std::setw(3) << "0";
			else
				ss << std::setw(3) << val;
			ss << " ";
		}
		ss << "\n";
	}
	return ss.str();
}

Graph & AdjacencyMatrix::clear()
{
	V = 0;
	E = 0;
	matrix.clear(); // Clear the matrix
	return *this;
}

std::vector<Edge> AdjacencyMatrix::getEdges() const {
	std::vector<Edge> edges;
	edges.reserve(E);
	for (int x = 0; x < V; x++)
		for (int y = 0; y < V; y++)
			if (adjacent(x, y))
				edges.push_back(Edge(x, y, getEdgeValue(x, y)));
	return edges;
}