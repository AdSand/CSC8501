#include "BealNumber.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <format>
#include "QuestionFour.h"
#include "LargePowers.h"
using namespace std;

BealNumber::BealNumber(int x, std::vector<std::vector<int>> y) :
	bealNumberTotal(x),
	solutions(y) {
}

int BealNumber::getBNT()
{
	return bealNumberTotal;
}

std::vector<std::vector<int>> BealNumber::getSolutions()
{
	return solutions;
}

void BealNumber::showSolutionCount()
{
	cout << "There are " << solutions.size() << " that exist";
}

void BealNumber::operator-()
{
	// use this operator to print out the first solution that has been found
	cout << this->getBNT() << ": ";
	vector<vector<int>> j = this->getSolutions();
	bool first = true;
	for (int z : j[0])
	{
		if (!first)
		{
			cout << ", ";
		}
		cout << z;
		first = false;
	}
	cout << endl;
}

bool verifyConjecture(int A, int x, int B, int y, int C, int z)
{
	if ((x <= 2) || (y <= 2) || (z <= 2))
	{
		return false;
	}
	return ((pow(A, x) + pow(B, y)) == pow(C, z));
}

bool isPrime(int BNT)
{
	if (BNT <= 1) return false;

	for (int i = 2; i <= BNT / 2; i++)
	{
		if (BNT % i == 0) return false;
	}
	return true;
}

void generateSolutions(int BNT, int K, vector<int>& currentSolution, vector<vector<int>>& allSolutions)
{
	if (BNT == 0 && K == 0)
	{
		if (verifyConjecture(currentSolution[0], currentSolution[1], currentSolution[2],
			currentSolution[3], currentSolution[4], currentSolution[5]))
		{
			// We have found a valid solution here!
			writeToFile(currentSolution);
			allSolutions.push_back(currentSolution);
		}
		return;
	}

	if (K <= 0 || BNT < 0)
	{
		return;
	}

	for (int i = 2; i <= BNT; i++)
	{
		currentSolution.push_back(i);
		generateSolutions(BNT - i, K - 1, currentSolution, allSolutions);
		currentSolution.pop_back();
	}
}