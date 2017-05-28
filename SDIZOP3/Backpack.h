#pragma once
#include <vector>
#include <deque>
#include <string>

#include "Item.h"
class Backpack
{
	
public:
	int add(Item* it);
	inline int getTotalPrice() { return total_p; }
	inline int getTotalWeight() { return total_w; }
	inline int getTotalMaxWeight() { return max_w; }
	std::string toString();
	Backpack(int max_w);
	~Backpack();

private:
	int total_w = 0;
	int total_p = 0;
	int max_w;
	std::deque<Item*> items;
};

