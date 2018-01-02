// Author: Brandon Morrison
// CS 240 - Intro to Computing III
// Date Completed: 10/5/15
// Descrption: BaseBallTeam header file.


#ifndef BASEBALL_TEAM
#define BASEBALL_TEAM
#include <iostream>
#include <fstream>
#include <string>
#include "BaseBallPlayer.h"
#include "Pitcher.h"
#include "Batter.h"
using namespace std;

typedef BaseballPlayer* BaseballPlayerPtr;
const int TEAM_SIZE = 25;
const int NUMBER_PITCHERS = 10;
const int NUMBER_BATTERS = 10;
const int NUMBER_SUBS = 5;

class BaseballTeam
{
public:
	BaseballTeam();
	BaseballTeam(const BaseballTeam &t);
	BaseballTeam& operator = (const BaseballTeam &t);
	~BaseballTeam();
	void loadTeam(istream &in);
	void displayTeam(ostream &out);
	void showTotals(ostream &out);
	void deleteTeam();
	int calculateTeamWins() const;
	int calculateTeamSaves() const;
	double calculateTeamERA() const;
	double calculateTeamWHIP() const;
	double calculateTeamBA() const;
	int calculateTeamHomeRuns() const;
	int calculateTeamRBI() const;
	int calculateTeamSB() const;

private:
	BaseballPlayerPtr team[TEAM_SIZE];
};
#endif