#include "QuestionTwo.h"
#include "BealNumber.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void findFivePrimeBNT()
{
	int BNT = 16;
	int found = 0;
	BealNumber beals[5];
	vector<int> currentSolution;
	vector<vector<int>> allSolutions;

	while (found < 5)
	{
		switch (isPrime(BNT))
		{
		case false:
			BNT++;
			break;
		case true:
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