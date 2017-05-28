#include "Edge.h"
#include <string>
#include <sstream>

Edge::Edge()
{
}

Edge::~Edge()
{
}

std::string Edge::toString() const
{
	std::stringstream ss;
	ss << from << "-" << to << ":" << weight;
	return ss.str();
}

Edge & Edge::setEdge(int f, int t, int w)
{
	from = f;
	to = t;
	weight = w;
	return *this;
}

int Edge::getFrom() const
{
	return from;
}

int Edge::getTo() const
{
	return to;
}

int Edge::getWeight() const
{
	return weight;
}
