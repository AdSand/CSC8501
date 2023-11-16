#include "QuestionEight.h"
#include "BealNumber.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "QuestionThree.h"

using namespace std;

void outHighestPattern(int range, bool verified)
{
	int BNT = 46;
	const int A = 8;
	const int B = 8;
	const int C = 16;
	int x = 5;
	int y = 5;
	int z = 4;

	// loop to 129 for the highest verified beal number total
	for (int i = BNT; i < range; i++)
	{
		cout << BNT << ": " << A << ", " << x << ", " << B << ", " << y << ", " << C << ", " << z << endl;
		x += 4;
		y += 4;
		z += 3;
		BNT += 11;
	}
	cout << "Using the pattern, we can find ----> "
		<< BNT << ": " << A << ", " << x << ", " << B << ", " << y << ", " << C << ", " << z << endl;
	switch (verified)
	{
	case true:
		cout << "After this, I can't verify that they are valid BNTs" << endl;
		break;
	case false:
		cout << "And so on...." << endl;
		break;
	}
}

void outHighestBrute()
{
	generateInRange(3, 20, 3, 15);
}