#pragma once
#include <vector>

class BealNumber
{
protected:
	int bealNumberTotal;
	std::vector<std::vector<int>> solutions;

public:
	BealNumber() = default;
	BealNumber(int x, std::vector<std::vector<int>> y);

	int getBNT();
	std::vector<std::vector<int>> getSolutions();
	virtual void showSolutionCount();
	void operator-();

};

template <typename T>
T customPower(T base, T exponent);

bool verifyConjecture(int A, int x, int B, int y, int C, int z);
void generateSolutions(int BNT, int K, std::vector<int>& currentSolution, std::vector<std::vector<int>>& allSolutions);
bool isPrime(int BNT);