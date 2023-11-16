#include "QuestionOne.h"
#include "BealNumber.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void findFiveBNT()
{
	int BNT = 16;
	int found = 0;
	BealNumber beals[5];
	vector<int> currentSolution;
	vector<vector<int>> allSolutions;

	while (found < 5)
	{
		// generate solutions for current BNT
		generateSolutions(BNT, 6, currentSolution, allSolutions);
		if (allSolutions.size() >= 1)
		{
			// at least one solution exists for the BNT
			BealNumber newBeal(BNT, allSolutions);
			beals[found] = newBeal;
			found++;
		}
		BNT++;
		currentSolution.clear();
		allSolutions.clear();
	}

	for (BealNumber i : beals)
	{
		-i;
	}
}