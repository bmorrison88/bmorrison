// Author: Brandon Morrison
// CS 240 - Intro to Computing III
// Date Completed: 10/5/15
// Descrption: Pitcher header file.


/* Pitcher.h */
#ifndef PITCHER_H
#define PITCHER_H

#include <string>
#include "BaseBallPlayer.h"
using namespace std;

//Constants:
const double INNINGS_PER_GAME = 9.0;

class Pitcher: public BaseballPlayer {

private:
	int wins, saves, inningsPitched, earnedRuns, hits, walks;
public:
	Pitcher();
	Pitcher(int wins, int saves, int inningsPitched, int earnedRuns, int hits, int walks);
	int getWins() const;
	int getSaves() const;
	int getInningsPitched() const;
	int getEarnedRuns() const;
	int getHits() const;
	int getWalks() const;

	void setWins(int wins);
	void setSaves(int saves);
	void setInningsPitched(const int inningsPitched);
	void setEarnedRuns(const int earnedRuns);
	void setHits(int hits);
	void setWalks(int walks);
	double calculateERA();
	double calculateWHIP();

	virtual void loadData(istream & in);
	virtual void display(ostream &out);

};
#endif
