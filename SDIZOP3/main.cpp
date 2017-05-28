#include <iostream>
#include <queue>
#include "Backpack.h"

int main() {
	
	Item it;
	it.randomizePrice(1, 10);
	it.randomizeWeight(1, 10);

	Item it2;
	it2.randomizePrice(1, 10);
	it2.randomizeWeight(1, 10);

	Backpack bp(30);
	bp.add(&it);
	bp.add(&it2);

	//std::cout << it.toString() << ", "<<it2.toString()<<"\n" << bp.getTotalPrice() << "\n" << bp.getTotalWeight() << "\n";
	std::cout << bp.toString();

	return 0;
}