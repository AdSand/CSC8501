#include "QuestionSeven.h"
#include "BealNumber.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


HistoBeal::HistoBeal(int x, std::vector<std::vector<int>> y)
{
	bealNumberTotal = x;
	solutions = y;
}

void HistoBeal::showSolutionCount()
{
	for (int j = 0; j < this->getSolutions().size(); j++)
	{
		cout << "X";
	}
}

vector<HistoBeal> foundHistoBeals;

void generateHistoBeals(int minimum, int maximum)
{
	int BNT = minimum;
	vector<int> currentSolution;
	vector<vector<int>> allSolutions;

	while (BNT <= maximum)
	{
		generateSolutions(BNT, 6, currentSolution, allSolutions);
		if (allSolutions.size() >= 1)
		{
			HistoBeal newBeal(BNT, allSolutions);
			foundHistoBeals.push_back(newBeal);
		}
		BNT++;
		currentSolution.clear();
		allSolutions.clear();
	}
}

void drawTheHistogram(int min, int max)
{
	generateHistoBeals(min, max);
	if (foundHistoBeals.empty())

	{
		cout << "Empty Set";
	}

	for (int i = 0; i < foundHistoBeals.size(); i++)
	{
		cout << foundHistoBeals[i].getBNT() << "|| ";
		foundHistoBeals[i].showSolutionCount();
		cout << endl;
	}
}

