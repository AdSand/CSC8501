#pragma once
#include "BealNumber.h"
#include <vector>

class QuestionSeven
{
};

class HistoBeal : public BealNumber
{
public:

	HistoBeal() = default;
	HistoBeal(int x, std::vector<std::vector<int>> y);
	void showSolutionCount();
};

void drawTheHistogram(int min, int max);