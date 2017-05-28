#include "Backpack.h"



int Backpack::add(Item* it)
{
	if (total_w + it->w > max_w)
		return 1;
	items.push_back(it);
	total_w += it->w;
	total_p += it->p;
	return 0;
}

std::string Backpack::toString()
{
	std::string buff = "{total_p: ";
	buff.append(std::to_string(total_p));
	buff.append(", total_w: ");
	buff.append(std::to_string(total_w));
	buff.append(", max_w: ");
	buff.append(std::to_string(max_w));
	buff.append(", items: ");

	for (Item* it : items)
		buff.append(it->toString()).append(", ");

	buff.append("}");
	return buff;
}

Backpack::Backpack(int max_w) : max_w(max_w)
{
}

Backpack::~Backpack()
{
}
