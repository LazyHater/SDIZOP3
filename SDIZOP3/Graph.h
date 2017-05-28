#pragma once
#include "Edge.h"
#include <string>
#include <deque>
#include <vector>

class Graph
{
public:
	Graph() {};
	virtual ~Graph() {};

	int getV() const; // returns the amount of vertexes
	int getE() const; // returns the amount of edges

	bool loadFile(std::string filename, bool isDirected); // loads the graph from a file filename
	Graph& generateRandomly(int n, double fill, bool isDirected = true); // generates the graph with n vertexes and fill density

	virtual bool adjacent(int x, int y) const = 0; // tests whether there is an edge from the vertex x to the vertex y;
	virtual std::deque<int> neighbors(int x) const = 0; // lists all vertices y such that there is an edge from the vertex x to the vertex y;
	virtual Graph& addVertex(int x) = 0; // adds the vertex x, if it is not there;
	virtual Graph& addEdge(int x, int y, int val, bool isDirected = false) = 0; // adds the edge from the vertex x to the vertex y, if it is not there, if it's undirected add symetric one
	virtual std::vector<Edge> getEdges() const = 0; // returns the vector of the graph's edges
	virtual int getEdgeValue(int x, int y) const = 0; // returns the value associated with the edge(x, y);
	virtual std::string toString() const = 0; // returns the graph's description as a string
	virtual Graph& clear() = 0; // clears the graph

protected:
	int V = 0, E = 0; // amount of vertexes V and edges E
};