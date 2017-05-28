#pragma once
#include <string>

class Item
{
public:
	int w; // weight
	int p; // price
	void randomizeWeight(int from, int to);
	void randomizePrice(int from, int to);
	
	std::string toString();

	Item();
	Item(int p, int w);
	~Item();

private:
	int random(int from, int to);

};

