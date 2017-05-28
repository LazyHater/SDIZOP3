#include "Graph.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

int Graph::getV() const
{
	return V;
}

int Graph::getE() const
{
	return E;
}

bool Graph::loadFile(string filename, bool isDirected)
{
	clear();
	int from, to, weight, a, b;
	ifstream file(filename, ios::out);
	if (file.is_open()) {
		file >> a >> b;
		while (file >> from >> to >> weight) {
			addEdge(from, to, weight, isDirected);
		}
		file.close();
		return true;
	}
	else {
		cerr << "Nie mozna otworzyc pliku." << endl;
		system("pause");
		return false;
	}
}

Graph& Graph::generateRandomly(int n, double fill, bool isDirected) {
	clear();
	int maxEdges = (n*(n - 1));
	if (!isDirected) maxEdges /= 2;
	int howManyEdgesToCreate = fill*double(maxEdges);


	vector<int> verticlesDone;
	verticlesDone.push_back(0);
	for (int i = 1; i < n; i++) {
		int selected_idx = rand() % verticlesDone.size();
		int val = rand() % 20 + 1;
		addEdge(verticlesDone[selected_idx], i, val, isDirected);
		verticlesDone.push_back(i);
	}

	while (howManyEdgesToCreate >= getE()) {
		int from = 0;
		int to = 0;

		do {
			from = rand() % n;
			to = rand() % n;
		} while (adjacent(from, to) || from == to || (!isDirected && adjacent(to, from)));

		addEdge(from, to, rand() % 20 + 1, isDirected);

	}

	return *this;
}
