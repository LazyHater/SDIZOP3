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
	std::string filename;

	while (!end) {
		system("cls");
		option = 0;
		std::cout << "\n-----DYSKRETNY PROBLEM PLECAKOWY------" << std::endl
			<< "1. Wczytaj plecak z pliku" << std::endl
			<< "2. Wygeneruj plecak losowo" << std::endl
			<< "3. Wyswietl plecak" << std::endl
			<< "4. Przeglad zupelny" << std::endl
			<< "5. Algorytm zachlanny" << std::endl
			<< "6. Algorytm oparty na programowaniu dynamicznym" << std::endl
			<< "7. Powrot" << std::endl
			<< "Twoj wybor: ";
		while (option < 1 || option > 7) {
			std::cin >> option;
		}
		std::cout << std::endl;

		switch (option) {
		case 1: // Load backpack from file
			std::cout << "Podaj nazwe pliku: ";
			std::cin >> filename;
			isLoaded = true;
			break;
		case 2: { // Generate backpack
			std::cout << "Podaj pojemnosc plecaka: ";
			std::cin >> maxWeight;
			std::cout << "Podaj ilosc przedmiotow: ";
			std::cin >> amount;
			isLoaded = true;
		}
				break;
		case 3: // Show backpack

			system("pause");
			break;
		case 4: // Full check algorithm
			if (isLoaded) {

			}
			else {
				std::cerr << "Najpierw wygeneruj lub zaladuj graf z pliku!\n";
			}
			system("pause");
		case 5: // Greedy algorithms
			if (isLoaded) {

			}
			else {
				std::cerr << "Najpierw wygeneruj lub zaladuj graf z pliku!\n";
			}
			system("pause");
			break;
		case 6: // Dynamic programming algorithm
			if (isLoaded) {
				//TODO
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
	return;
}

void tspMenu() {
	int option = 0, vertexes = 0;
	double density;
	bool end = false, isLoaded = false;
	std::string filename;

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
		case 1: // Load graph from file, UNDIRECTED
			std::cout << "Podaj nazwe pliku: ";
			std::cin >> filename;
			if (matrixGraph.loadRawFromFile(filename)) isLoaded = true;
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
				TSP::fullCheckAlgorithm(matrixGraph);
				std::cout << GetCounter() << std::endl;
			}
			else {
				std::cerr << "Najpierw wygeneruj lub zaladuj graf z pliku!\n";
			}
			system("pause");
			break;
		case 5: // Greedy algorithms
			if (isLoaded) {
				StartCounter();
				TSP::greedyAlgorithm(matrixGraph, 0);
				std::cout << GetCounter() << std::endl;
			}
			else {
				std::cerr << "Najpierw wygeneruj lub zaladuj graf z pliku!\n";
			}
			system("pause");
			break;
		case 6: // Local check algorithm
			if (isLoaded) {
				//TODO
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
	return;
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