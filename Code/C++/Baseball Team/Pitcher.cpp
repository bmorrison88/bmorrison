// Author: Brandon Morrison
// CS 240 - Intro to Computing III
// Date Completed: 10/5/15
// Descrption: Implementation of the Pitcher class.

#include <iostream>
#include <string>
#include <iomanip>
#include "BaseBallPlayer.h"
#include "Pitcher.h"

using namespace std;


Pitcher::Pitcher():BaseballPlayer()
{
	name = "";
	position = "P";
	wins = 0;
	saves = 0;
	inningsPitched = 0;
	earnedRuns = 0;
	hits = 0;
	walks = 0;
}

Pitcher::Pitcher(int wins, int saves, int inningsPitched, int earnedRuns, int hits, int walks) : BaseballPlayer(name,"P")
{
	setName(name);
	setWins(wins);
	setSaves(saves);
	setInningsPitched(inningsPitched);
	setEarnedRuns(earnedRuns);
	setHits(hits);
	setWalks(walks);
}

int Pitcher::getWins() const
{
	return wins;
}

int Pitcher::getSaves() const
{
	return saves;
}

int Pitcher::getInningsPitched() const
{
	return inningsPitched;
}

int Pitcher::getEarnedRuns() const
{
	return earnedRuns;
}

int Pitcher::getHits() const
{
	return hits;
}

int Pitcher::getWalks() const
{
	return walks;
}

void Pitcher::setWins(int wins)
{
	this->wins = wins;
}

void Pitcher::setSaves(int saves)
{
	this->saves = saves;
}

void Pitcher::setInningsPitched(int inningsPitched)
{
	this->inningsPitched = inningsPitched;
}

void Pitcher::setEarnedRuns(int earnedRuns)
{
	this->earnedRuns = earnedRuns;
}

void Pitcher::setHits(int hits)
{
	this->hits = hits;
}

void Pitcher::setWalks(int walks)
{
	this->walks = walks;
}

double Pitcher::calculateERA()
{
	double era;

	if (getInningsPitched() == 0) {
		return -1;
	}
	else {
		era = (double)getEarnedRuns() / (double)getInningsPitched() * INNINGS_PER_GAME;
		return era;
	}
}

double Pitcher::calculateWHIP()
{
	if (getInningsPitched() == 0) {
		return -1;
	}
	else {
		return (getWalks() + getHits()) / (double)getInningsPitched();
	}
}

void Pitcher::loadData(istream &in) {
	getline(in, name);
	while (name == "") {
		getline(in, name);
	}
	in >> wins >> saves >> inningsPitched >> earnedRuns >> hits >> walks;
}

void Pitcher::display(ostream & out)
{
	out << setw(2) << left << getPosition() 
		<< setw(19) << right << getName() 
		<< setw(11) << getWins() 
		<< setw(14) << getSaves() 
		<< setw(8) << setprecision(3) << calculateERA() 
		<< setw(9) << setprecision(3) << calculateWHIP() << endl;
}
