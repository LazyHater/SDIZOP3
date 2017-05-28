#include "BackpackProblem.h"
#include <iostream>




std::vector<Item> BackpackProblem::getRandomItems(int n, int p_from, int p_to, int w_from, int w_to)
{
	std::vector<Item> items;
	items.reserve(n);

	for (int i = 0; i < n; i++) {
		Item it;
		it.randomizePrice(p_from, p_to);
		it.randomizeWeight(w_from, w_to);
		items.push_back(it);
	}

	return items;
}

Backpack BackpackProblem::solveFullCheck(std::vector<Item>& items, int backpack_w)
{
	
	size_t items_n = items.size();
	Backpack best_bp(backpack_w);
	for (unsigned long long set = 0; set < (1 << items_n); set++) {
		Backpack bp(backpack_w);

		for (int i = 0; i < items_n; i++) {
			if (set & (1 << i)) {
				if (bp.add(&items[i]) != 0)
					break;
			}
		}

		if (bp.getTotalPrice() > best_bp.getTotalPrice())
			best_bp = bp;
	}

	return best_bp;
}

BackpackProblem::BackpackProblem()
{
}


BackpackProblem::~BackpackProblem()
{
}
