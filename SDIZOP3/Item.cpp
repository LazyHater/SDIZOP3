#include "Item.h"
#include <cstdlib>


int Item::random(int from, int to)
{
	int diff = to - from;
	return rand() % diff + from;
}

void Item::randomizeWeight(int from, int to)
{
	w = random(from, to);
}

void Item::randomizePrice(int from, int to)
{
	p = random(from, to);
}

std::string Item::toString() {
	std::string buff = "[w: ";
	buff.append(std::to_string(w));
	buff.append(", p: ");
	buff.append(std::to_string(p));
	buff.append("]");
	return buff;
}

Item::Item()
{
}

Item::Item(int p, int w): p(p), w(w)
{
}


Item::~Item()
{
}
