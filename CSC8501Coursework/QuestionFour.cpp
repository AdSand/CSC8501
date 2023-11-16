#include "QuestionFour.h"
#include "BealNumber.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>

using namespace std;

void writeToFile(vector<int>& solution)
{
	ofstream myfile;
	myfile.open("solutions.txt", ios::out | ios::app);
	int sum = solution[0] + solution[1] + solution[2] + solution[3] + solution[4] + solution[5];
	myfile << sum << ": " << solution[0] << ", " << solution[1] << ", " << solution[2] << ", "
		<< solution[3] << ", " << solution[4] << ", " << solution[5] << endl;
	myfile.close();
}

void readFromFile(string filename)
{
	string line;
	ifstream myfile(filename);
	const regex checkFormat(R"(\d+: (\d{1,}, \d{1,}, \d{1,}, \d{1,}, \d{1,}, \d{1,}))");
	while (getline(myfile, line))
	{
		if (regex_match(line, checkFormat))
		{
			vector<int> numbers;
			string numberStr;
			istringstream sstream(line);

			getline(sstream, numberStr, ':');
			numbers.push_back(stoi(numberStr));
			while (getline(sstream, numberStr, ','))
			{
				numbers.push_back(stoi(numberStr));
			}

			if (verifyConjecture(numbers[1], numbers[2], numbers[3], numbers[4], numbers[5], numbers[6])
				&&
				numbers[0] == (numbers[1] + numbers[2] + numbers[3] + numbers[4] + numbers[5] + numbers[6])
				)
			{
				cout << line << endl;
			}
			else
			{
				cout << line << " - NOT A VALID SOLUTION" << endl;
			}
		}
		else
		{
			cout << "Incorrect formatting" << endl;
		}
	}
	myfile.close();
}

void clearFile(string filename)
{
	ofstream myfile(filename, ios::out, ios::trunc);
	cout << "File cleared" << endl;
	myfile.close();
}
