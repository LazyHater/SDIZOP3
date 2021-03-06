#include "PerformanceTests.h"

#include <algorithm>
#include <fstream>
#include <iostream>

#include "BackpackProblem.h"
#include "TSP.h"

double PerformanceTests::PCFreq = 0.0;
__int64 PerformanceTests::CounterStart = 0;

class BackpackResult {
public:
	int it_n;
	int bp_w;
	double backpackFullCheck = 0;
	double backpackGreedy = 0;
};

class TspResult {
public:
	int it_n;
	int bp_w;
	double TspFullCheck = 0;
	double TspGreedy = 0;
};

void PerformanceTests::makeBackpackTests()
{
	std::cout << "TESTING BACKPACK\n";
	std::vector<BackpackResult> results;
	for (int it_n : { 5, 10, 15, 17, 20}) {
		for (int bp_w : { 50, 75, 100 }) {
			BackpackResult result;
			result.it_n = it_n;
			result.bp_w = bp_w;
			
			std::cout << "TEST FOR it_n: " << it_n << " bp_w: "<<bp_w << "\n";
			for (int i = 0; i < 100; i++) {

				auto items = BackpackProblem::getRandomItems(it_n, 1, 100, 5, 30);

				StartCounter();
				BackpackProblem::solveFullCheck(items, bp_w);
				result.backpackFullCheck += GetCounter() / 100.0f;

				StartCounter();
				BackpackProblem::solveGreedyApproximation(items, bp_w);
				result.backpackGreedy += GetCounter() / 100.0f;
			}
			results.push_back(result);
		}
	}
	
	std::sort(results.begin(), results.end(), [](BackpackResult& lhs, BackpackResult& rhs) {
		return lhs.bp_w < rhs.bp_w;
	});

	std::ofstream file("C:\\Users\\Wakabajaszi\\Desktop\\bp_tests.csv", std::ios::app);
	if (file.is_open()) {
		file << "it_n;bp_w;backpackFullCheck;backpackGreedy\n";
		for (auto res : results) {
			file << res.it_n<<";" <<res.bp_w << ";" << res.backpackFullCheck << ";" << res.backpackGreedy<<"\n";
		}
		file.close();
		std::cout << "Generated file bp_tests.csv\n";
	}
	else {
		std::cerr << "Cannot create file!.\n";
	}
}

PerformanceTests::PerformanceTests()
{
}


PerformanceTests::~PerformanceTests()
{
}
