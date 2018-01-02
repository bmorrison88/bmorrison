// Author: Brandon Morrison
// CS 240 - Intro to Computing III
// Date Completed: 10/5/15
// Descrption: Batter header file.


/* Batter.h */
#ifndef BATTER_H
#define BATTER_H

#include <string>
#include "BaseBallPlayer.h"

using namespace std;

class Batter : public BaseballPlayer {
private:
	int atBats, hits, hr, rbi, sb;
public:
	Batter();
	Batter(int atBats, int hits, int hr, int rbi, int sb);
	int getAtBats() const;
	int getHits() const;
	int getHR() const;
	int getRBI() const;
	int getSB() const;

	void setAtBats(int atBats);
	void setHits(int hits);
	void setHR(int hr) ;
	void setRBI(int rbi);
	void setSB(int sb);

	double calculateBattingAvg();

	virtual void loadData(istream & in);
	virtual void display(ostream &out);
};
#endif