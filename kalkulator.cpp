#include "kalkulator.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;


//Opening calculation history file
void kalkulator::openKalkFile()
{
	historyfile.open("history.txt", ios::out | ios::app | ios::in);
	if (historyfile.good() == false)
	{
		cout << "Calculation history file does not exist" << endl;
		exit(0);
	}
}


//Inserting x and y to calculator
void kalkulator::insertData()
{
	cout << "Insert 1st number: ";
	cin >> x;
	cout << "Insert 2nd number: ";
	cin >> y;
	cout << endl;
}


//Draw operations menu and get char choice
void kalkulator::getChoice()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	cout << "MAIN MENU" << endl;
	cout << "------------------------------" << endl;
	cout << "1. Addition" << endl;
	cout << "2. Subtraction" << endl;
	cout << "3. Multiplication" << endl;
	cout << "4. Division" << endl;
	cout << "5. Show calculations history" << endl;
	cout << "6. Clear calculations history" << endl;
	cout << "7. Exit program" << endl;
	cout << "------------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl << "Choice: " << endl;
	choice = _getch();	
}




void kalkulator::makeCalcs()
{
	string line;
	switch (choice)
	{
	case '1':
		cout << "Addition outcome equals: " << x + y << endl;
		historyfile << "Addition outcome of " << x << " and " << y << " equals: " << x + y << endl;
		break;
	case '2':
		cout << "Subtraction outcome equals: " << x - y << endl;
		historyfile << "Subtraction outcome of " << x << " and " << y << " equals: " << x - y << endl;
		break;
	case '3':
		cout << "Multiplication outcome equals: " << x * y << endl;
		historyfile << "SMultiplication outcome of " << x << " by " << y << " equals: " << x * y << endl;
		break;
	case '4':
		if (y == 0) cout << "Do not divide by 0!";
		else {
			cout << "Division outcome equals: " << x / y << endl;
			historyfile << "Division outcome of  " << x << " by " << y << " equals: " << x / y << endl;
		}
		break;
	
		break;
	case '5':

		historyfile.clear();
		historyfile.seekg(0);
		while (!historyfile.eof())
		{
			getline(historyfile, line);

			cout << line << endl;

		}
		historyfile.clear();
		historyfile.seekg(0);
		break;
	case '6':
		historyfile.close();
		historyfile.open("history.txt", std::ofstream::out | std::ofstream::trunc);
		historyfile.close();
		historyfile.open("history.txt", ios::out | ios::app | ios::in);
		cout << "Cleaned" << endl;
		break;
	case '7':
		historyfile.close();
		exit(0);
		break;
	}
}


