#pragma once
#include "Backpack.h"

class DKP
{
public:
	static std::vector<Item> generateRandomsItems(int n, int p_from, int p_to, int w_from, int w_to);
	static Backpack fullCheckAlgorithm(std::vector<Item>& items, int backpack_w);
	static Backpack greedyAlgorithm(std::vector<Item>& items, int backpack_w);

	static int DKP::loadFromFile(const std::string fname, std::vector<Item>& items, int& bp_w);

	DKP();
	~DKP();
};

