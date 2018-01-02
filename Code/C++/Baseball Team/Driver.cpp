// Author: Brandon Morrison
// CS 240 - Intro to Computing III
// Date Completed: 10/5/15
// Description: Driver class for Baseball stats. In this program, I had to read a text file
//				and manipulate the data to successfully calculate the stats. The data is 
//				then printed to the user in a formatted output. I chose to include this program
//				because it was one of the first programs I completed in C++.

#include <iostream> // IO stream
#include<fstream> // file IO
#include<string> //string
#include <iomanip> //IO manipulation
#include "BaseBallPlayer.h"
#include "BaseballTeam.h"
#include "Pitcher.h"
#include "Batter.h"

using namespace std;

int main()
{
	BaseballTeam t;
	ifstream infile;
	string file = "BaseballTeam.txt";
	infile.open(file);
	t.loadTeam(infile);
	t.displayTeam(cout);
	infile.close();
	system("pause");

}