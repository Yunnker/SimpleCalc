#pragma once
using namespace std;
#include <fstream>


class kalkulator
{
public:

	void openKalkFile();	//Opening calculation history file
	void insertData();		//Inserting x and y to calculator
	void getChoice();		//Draw operations menu and get char choice
	void makeCalcs();		//Does, draws, and registers calculations to calculation history file

	fstream historyfile;	//File that stores calculation history
	double long x, y;		//x and y that will be necessery for calculations
	char choice;			//Choice of operation decided by user

};

