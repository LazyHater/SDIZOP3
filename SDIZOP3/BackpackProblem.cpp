#include "BackpackProblem.h"
#include <iostream>
#include <algorithm>
#include <fstream>

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

	//2^n possible combinations, we need to check all
	for (unsigned long long set = 0; set < (1 << items_n); set++) {
		Backpack bp(backpack_w);

		for (int i = 0; i < items_n; i++) {
			if (set & (1 << i)) {
				if (bp.addItem(&items[i]) != 0) //if cannot add another item, break
					break;
			}
		}

		if (bp.getTotalPrice() > best_bp.getTotalPrice())
			best_bp = bp;
	}

	return best_bp;
}

Backpack BackpackProblem::solveGreedyApproximation(std::vector<Item>& items, int backpack_w)
{
	Backpack bp(backpack_w);

	std::sort(items.begin(), items.end(), [](const Item& lhs, const Item& rhs) {
		return (lhs.p / lhs.w) > (rhs.p / rhs.w);
	});

	for (Item& it : items)
		bp.addItem(&it);

	return bp;
}

void BackpackProblem::loadFromFile(const std::string fname, std::vector<Item>& items, int& bp_w)
{
	items.clear();
	int it_w, it_p, it_n;
	std::ifstream file(fname, std::ios::out);
	if (file.is_open()) {
		file >> bp_w >> it_n;
		while (file >> it_w >> it_p) {
			items.push_back(Item(it_p, it_w));
		}
		file.close();
	}
	else {
		std::cerr << "Cannot open file.\n";
		system("pause");
	}
}

BackpackProblem::BackpackProblem()
{
}


BackpackProblem::~BackpackProblem()
{
}
