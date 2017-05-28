#include <iostream>
#include <vector>

#include "BackpackProblem.h"

int main() {
	
	std::vector<Item> items = BackpackProblem::getRandomItems(10, 1, 100, 1, 20);

	for (Item& it : items) {
		std::cout << it.toString()<<"\n";
	}

	Backpack bp = BackpackProblem::solveFullCheck(items, 30);
	
	std::cout << bp.toString()<<"\n";

	return 0;
}