#pragma once
#include "Graph.h"
#include <vector>
#include <deque>

class AdjacencyMatrix :
	public Graph
{
public:
	AdjacencyMatrix() {};
	AdjacencyMatrix(const AdjacencyMatrix& obj); // Copy constructor
	~AdjacencyMatrix();

	virtual bool adjacent(int x, int y) const override;
	virtual std::deque<int> neighbors(int x) const override;
	virtual Graph & addVertex(int x) override;
	virtual Graph & addEdge(int x, int y, int val, bool isDirected = false) override;
	inline virtual int getEdgeValue(int x, int y) const override {return matrix[x][y];}
	virtual std::vector<Edge> getEdges() const;

	int loadRawFromFile(const std::string fname);
	void generateFullGraph(int size);

	virtual std::string toString() const override;
	virtual Graph & clear() override;
private:
	std::vector<std::vector<int>> matrix; // Adjacency matrix
};