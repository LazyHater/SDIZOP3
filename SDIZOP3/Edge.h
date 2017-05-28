#pragma once
#include <iostream>

class Edge {
public:
	Edge();
	~Edge();
	Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {};
	std::string toString() const;
	Edge& setEdge(int f, int t, int w);
	int getFrom() const;
	int getTo() const;
	int getWeight() const;
private:
	int from = 0;
	int to = 0;
	int weight = 0;
};
