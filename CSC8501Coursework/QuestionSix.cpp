#include "QuestionSix.h"
#include "BealNumber.h"
#include <iostream>
#include <fstream>
using namespace std;

void findSquareBeal(int BNT)
{
	if (BNT % 3 != 0)
	{
		BNT *= BNT;
		int n = (BNT - 7) / 3;
		cout << "Using method one --------------	" <<
			BNT << ": " << "2, " << n << ", 2, " << n << ", 2, " << n+1 << endl;
	}
	else
	{
		BNT *= BNT;
		int n = (BNT -18) / 9;
		cout << "Using method two --------------	" << 
			BNT << ": " << "2, " << ((4*n)-1) << ", 2, " << ((4 * n) - 1) << ", 16, " << n << endl;
	}
}

void squareBigBeals()
{
	for (int i = 32; i <= 316; i++)
	{
		findSquareBeal(i);
	}
}