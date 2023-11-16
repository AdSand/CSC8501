#include <iostream>
#include "BealNumber.h"
#include "QuestionOne.h"
#include "QuestionTwo.h"
#include "QuestionThree.h"
#include "QuestionFour.h"
#include "QuestionFive.h"
#include "QuestionSix.h"
#include "QuestionSeven.h"
#include "QuestionEight.h"
#include "LargePowers.h"
#include <thread>
#include <string>
using namespace std;


int selection = 0;
string filename;

void displayMenu()
{
	cout << endl << "Please select an option from the menu: " << endl
		<< "1: Display first 5 lowest distinct BNT values" << endl
		<< "2: Display first 5 prime distinct BNTs" << endl
		<< "3: Display within ranges" << endl
		<< "4: Read from a file" << endl
		<< "5: Display first 10 composite BNTs" << endl
		<< "6: Display BNTs that are square, betwen 1000 and 100000" << endl
		<< "7: Display ASCII histogram of BNTs between values" << endl
		<< "8: Display highest BNT" << endl
		<< "9: Exit the program" << endl
		<< "0: Clear the text file" << endl;
	return;
}

void makeSelection()
{
	cin >> selection;
	return;
}

void openSection(int choice)
{
	cout << endl;
	switch (choice)
	{
	case 1: 
		cout << "Selected option 1" << endl;
		findFiveBNT();
		break;
	case 2:
		cout << "Selected option 2" << endl;
		findFivePrimeBNT();
		break;
	case 3:
		cout << "Selected option 3" << endl;
		generateInRange(3, 20, 3, 15);
		break;
	case 4:
		cout << "Selected option 4. Please enter the filename:" << endl;
		cin >> filename;
		readFromFile(filename);
		break;
	case 5:
		cout << "Selected option 5" << endl;
		findTenCompositeBNT();
		break;
	case 6:
		cout << "Selected option 6" << endl;
		squareBigBeals();
		break;
	case 7:
		cout << "Selected option 7" << endl;
		int min;
		int max;
		cout << "Enter a minimum range: ";
		cin >> min;
		cout << "Enter a maximum range: ";
		cin >> max;
		drawTheHistogram(min, max);
		break;
	case 8:
		cout << "Selected option 8 \n Would you like the pattern method (enter 'v' for verified or 'u' for unverified) \n or \n the brute force method (enter 'b')" << endl;
		cout << "Make selection here: ";
		char methodChoice;
		cin >> methodChoice;
		switch (methodChoice)
		{
		case 'v':
			outHighestPattern(129, true);
			break;
		case 'u':
			outHighestPattern(20000, false);
			break;
		case 'b':
			outHighestBrute();
			break;
		}
		break;
	case 0:
		clearFile("solutions.txt");
		break;
	case 9:
		cout << "Exiting Program" << endl;
		break;
	}
}

int main()
{
	while (selection != 9)
	{
		thread displayMenuThread(displayMenu);
		thread makeSelectionThread(makeSelection);

		displayMenuThread.join();
		makeSelectionThread.join();

		openSection(selection);
	}
	return 0;
}