#pragma once
#include "Backpack.h"

class BackpackProblem
{
public:
	static std::vector<Item> getRandomItems(int n, int p_from, int p_to, int w_from, int w_to);
	static Backpack solveFullCheck(std::vector<Item>& items, int backpack_w);
	static Backpack solveGreedyApproximation(std::vector<Item>& items, int backpack_w);

	static void BackpackProblem::loadFromFile(const std::string fname, std::vector<Item>& items, int& bp_w);

	BackpackProblem();
	~BackpackProblem();
};

