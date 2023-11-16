#include "QuestionThree.h"
#include "BealNumber.h"
#include "LargePowers.h"
#include "QuestionFour.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void generateInRange(int baseStart, int baseLimit, int powerStart, int powerLimit)
{
	for (int A = baseStart; A <= baseLimit; A++)
	{
		for (int x = powerStart; x <= powerLimit; x++)
		{
			for (int B = baseStart; B <= baseLimit; B++)
			{
				for (int y = powerStart; y <= powerLimit; y++)
				{
					for (int C = baseStart; C <= baseLimit; C++)
					{
						for (int z = powerStart; z <= powerLimit; z++)
						{
							if (verifyLargeConjecture<uint64_t>(A, x, B, y, C, z))
							{
								cout << A + B + C + x + y + z << ": ";
								cout << A << ", " << x << ", " << B << ", " << y << ", " << C << ", " << z << endl;
								vector<int> solution = {A, x, B, y, C, z};
								writeToFile(solution);
							}
						}
					}
				}
			}
		}
	}
}