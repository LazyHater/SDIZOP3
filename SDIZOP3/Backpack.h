#pragma once
#include <vector>
#include <deque>
#include <string>

#include "Item.h"
class Backpack
{
public:
	inline int getTotalPrice()		const { return total_p; }
	inline int getTotalWeight()		const { return total_w; }
	inline int getMaxWeight()		const { return max_w; }

	int addItem(Item* it);
	std::vector<Item> getItems() const;
	std::string toString() const;

	Backpack(int max_w);
	~Backpack();

private:
	int total_w = 0;
	int total_p = 0;
	int max_w;
	std::deque<Item*> items;
};

