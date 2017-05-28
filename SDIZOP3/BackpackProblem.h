#pragma once
#include "Backpack.h"

class BackpackProblem
{
public:
	static Backpack solve(const std::vector<Item>& items, int backpack_w);

	BackpackProblem();
	~BackpackProblem();
};

