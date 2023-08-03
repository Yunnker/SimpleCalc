#include <iostream>
using namespace std;
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <string>
#include "kalkulator.h"


int main()
{
	system("title Calculator by Junker");
	kalkulator k1;
	k1.openKalkFile();
	for (;;)
	{
		k1.insertData();
		k1.getChoice();
		k1.makeCalcs();
		_getch();
		system("cls");
	}

}
