#include "QuestionFive.h"
#include "BealNumber.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void findTenCompositeBNT()
{
	int BNT = 16;
	int found = 0;
	BealNumber beals[10];
	vector<int> currentSolution;
	vector<vector<int>> allSolutions;

	while (found < 10)
	{
		switch (isPrime(BNT))
		{
		case true:
			BNT++;
			break;
		case false:
			generateSolutions(BNT, 6, currentSolution, allSolutions);
			if (allSolutions.size() >= 1)
			{
				BealNumber newBeal(BNT, allSolutions);
				beals[found] = newBeal;
				found++;
			}
			BNT++;
			currentSolution.clear();
			allSolutions.clear();
			break;
		}
	}

	for (BealNumber i : beals)
	{
		-i;
	}
}