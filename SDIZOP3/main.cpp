#include <iostream>
#include <queue>
#include "Backpack.h"
#include "AdjacencyMatrix.h"
#include "TSP.h"
#include "BackpackProblem.h"
#include "PerformanceTests.h"

// Time variables
double PCFreq = 0.0;
__int64 CounterStart = 0;

// Start time counter
void StartCounter() {
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		std::cerr << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}

// Get current value of last started counter
double GetCounter() {
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}

std::vector<Edge> eraseDuplicats(const std::vector<Edge>& inputEdges) {
	std::vector<Edge> result(inputEdges);

	for (int j = 0; j < result.size(); j++) {
		Edge e1 = result[j];
		for (int i = 0; i < result.size(); i++) {
			if (i == j) continue;
			Edge e2 = result[i];
			if (e1.getFrom() == e2.getTo() && e2.getFrom() == e1.getTo()) {
				result.erase(result.begin() + i);
			}
		}
	}
	return result;
}

void dkpMenu() {
	int option = 0, maxWeight = 0, amount = 0;
	bool end = false, isLoaded = false;
	std::vector<Item> items;
	Backpack bp(0);

	while (!end) {
		system("cls");
		option = 0;
		std::cout << "\n-----DYSKRETNY PROBLEM PLECAKOWY------" << std::endl
			<< "1. Wczytaj przedmioty z pliku" << std::endl
			<< "2. Wygeneruj przedmioty losowo" << std::endl
			<< "3. Wyswietl przedmioty" << std::endl
			<< "4. Wyswietl plecak wynikowy" << std::endl
			<< "5. Przeglad zupelny" << std::endl
			<< "6. Algorytm zachlanny" << std::endl
			<< "7. Algorytm oparty na programowaniu dynamicznym" << std::endl
			<< "8. Powrot" << std::endl
			<< "Twoj wybor: ";

		while (option < 1 || option > 8) {
			std::cin >> option;
		}
		std::cout << std::endl;

		switch (option) {
		case 1: { // Load items from file
			std::cout << "Podaj nazwe pliku: ";
			std::string filename;
			std::cin >> filename;
			if (!DKP::loadFromFile(filename, items, maxWeight)) {
				isLoaded = true;
			}
			else {
				isLoaded = false;
			}
		}
			break;

		case 2: { // Generate items
			std::cout << "Podaj ilosc przedmiotow: ";
			std::cin >> amount;
			std::cout << "Podaj maksymalna pojemnosc plecaka: ";
			std::cin >> maxWeight;
			items = DKP::generateRandomsItems(amount, 1, 100, 1, 20);
			isLoaded = true;
		}
				break;

		case 3: // Show items
			std::cout << "Maksymalna waga: " << maxWeight << "\n";
			for (auto val : items) {
				std::cout << val.toString() << "\n";
			}
			std::cout << std::endl;
			system("pause");
			break;

		case 4:
			std::cout << bp.toString() << std::endl;
			system("pause");
			break;

		case 5: // Full check algorithm
			if (isLoaded) {
				StartCounter();
				bp = DKP::fullCheckAlgorithm(items, maxWeight);
				std::cout << "Czas: " << GetCounter() << std::endl;
			}
			else {
				std::cerr << "Najpierw wygeneruj lub zaladuj przedmioty z pliku!\n";
			}
			system("pause");
			break;

		case 6: // Greedy algorithms
			if (isLoaded) {
				StartCounter();
				bp = DKP::greedyAlgorithm(items, maxWeight);
				std::cout << "Czas: " << GetCounter() << std::endl;
			}
			else {
				std::cerr << "Najpierw wygeneruj lub zaladuj przedmioty z pliku!\n";
			}
			system("pause");
			break;

		case 7: // Dynamic programming algorithm
			if (isLoaded) {
				//TODO
				std::cerr << "UNIMPLEMENTED!\n";
			}
			else {
				std::cerr << "Najpierw wygeneruj lub zaladuj graf z pliku!\n";
			}
			system("pause");
			break;

		case 8: // Exit
			end = true;
			break;

		default:
			break;
		}
	}
	return;
}

void tspMenu() {
	int option = 0, vertexes = 0;
	bool end = false, isLoaded = false;
	AdjacencyMatrix matrixGraph;

	while (!end) {
		system("cls");
		option = 0;
		std::cout << "\n-----ASYMETRYCZNY PROBLEM KOMIWOJAZERA------" << std::endl
			<< "1. Wczytaj graf miast z pliku" << std::endl
			<< "2. Wygeneruj graf miast losowo" << std::endl
			<< "3. Wyswietl reprezentacje macierzowa grafu miast" << std::endl
			<< "4. Przeglad zupelny" << std::endl
			<< "5. Algorytm zachlanny" << std::endl
			<< "6. Algorytm przeszukiwania lokalnego" << std::endl
			<< "7. Powrot" << std::endl
			<< "Twoj wybor: ";

		while (option < 1 || option > 7) {
			std::cin >> option;
		}
		std::cout << std::endl;

		switch (option) {
		case 1: { // Load graph from file
			std::cout << "Podaj nazwe pliku: ";
			std::string filename;
			std::cin >> filename;
			if (matrixGraph.loadRawFromFile(filename)) isLoaded = true;
		}
		break;

		case 2: { // Generate graph
			std::cout << "Podaj ilosc miast: ";
			std::cin >> vertexes;
			matrixGraph.generateFullGraph(vertexes);
			isLoaded = true;
		}
				break;
		case 3: // Print adjacency matrix
			std::cout << matrixGraph.toString() << std::endl;
			system("pause");
			break;

		case 4: // Full check algorithm
			if (isLoaded) {
				StartCounter();
				auto result = TSP::fullCheckAlgorithm(matrixGraph);
				std::cout << "Czas: " << GetCounter() << std::endl;

				for (auto val : result) {
					std::cout << val << " ";
				}
				std::cout << std::endl;
			}
			else {
				std::cerr << "Najpierw wygeneruj lub zaladuj graf z pliku!\n";
			}
			system("pause");
			break;

		case 5: // Greedy algorithm
			if (isLoaded) {
				StartCounter();
				auto result = TSP::greedyAlgorithm(matrixGraph, 0);
				std::cout << "Czas: " << GetCounter() << std::endl;

				for (auto val : result) {
					std::cout << val << " ";
				}
				std::cout << std::endl;
			}
			else {
				std::cerr << "Najpierw wygeneruj lub zaladuj graf z pliku!\n";
			}
			system("pause");
			break;

		case 6: // Local check algorithm
			if (isLoaded) {
				//TODO
				std::cerr << "UNIMPLEMENTED!\n";
			}
			else {
				std::cerr << "Najpierw wygeneruj lub zaladuj graf z pliku!\n";
			}
			system("pause");
			break;

		case 7: // Exit
			end = true;
			break;
		default:
			break;
		}
	}
}

void mainMenu() {
	int option = 0;
	bool end = false;
	unsigned int size;
	std::string filename;

	while (!end) {
		system("cls");
		option = 0;
		std::cout << "\n-----MENU GLOWNE------" << std::endl
			<< "1. Dyskretny problem plecakowy" << std::endl
			<< "2. Asymetryczny problem komiwojazera" << std::endl
			<< "3. Uruchom testy" << std::endl
			<< "4. Zakoncz" << std::endl
			<< "Twoj wybor: ";
		while (option < 1 || option > 4) {
			std::cin >> option;
		}
		std::cout << std::endl;

		switch (option) {
		case 1: // Discrete knapsack problem
			dkpMenu();
			break;
		case 2: // Travelling salesman problem
			tspMenu();
			break;
		case 3: // Run tests
			PerformanceTests::makeBackpackTests();
			PerformanceTests::makeTspTests();
			system("pause");
			break;
		case 4: // EXIT
			end = true;
			break;
		default:
			break;
		}
	}
	return;
}

int main() {
	mainMenu();
	return 0;
}