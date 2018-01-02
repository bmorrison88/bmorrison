// Author: Brandon Morrison
// CS 240 - Intro to Computing III
// Date Completed: 10/5/15
// Descrption: Implementation of the Batter class.

#include <string>
#include <iomanip>
#include "BaseBallPlayer.h"
#include "Batter.h"

using namespace std;

//constants:

Batter::Batter(): BaseballPlayer()
{
	name = "";
	position = "";
	atBats = 0;
	hits = 0;
	hr = 0;
	rbi = 0;
	sb = 0;
}

Batter::Batter(int atBats, int hits, int hr, int rbi, int sb) : BaseballPlayer(name,position)
{
	setName(name);
	setPosition(position);
	setAtBats(atBats);
	setHits(hits);
	setHR(hr);
	setRBI(rbi);
	setSB(sb);
}

int Batter::getAtBats() const
{
	return atBats;
}

int Batter::getHits() const
{
	return hits;
}

int Batter::getHR() const
{
	return hr;
}

int Batter::getRBI() const
{
	return rbi;
}

int Batter::getSB() const
{
	return sb;
}

void Batter::setAtBats(int atBats)
{
	this->atBats = atBats;
}

void Batter::setHits(int hits)
{
	this->hits = hits;
}

void Batter::setHR(int hr)
{
	this->hr = hr;
}

void Batter::setRBI(int rbi)
{
	this->rbi = rbi;
}

void Batter::setSB(int sb)
{
	this->sb = sb;
}

double Batter::calculateBattingAvg()
{
	if (atBats == 0) {
		return -1;
	}
	else {
		return hits / (double)atBats;
	}
}

void Batter::loadData(istream & in)
{
	getline(in, name);
	while (name == "") {
		getline(in, name);
	}
	in >> position >> atBats >> hits >> hr >> rbi >> sb;
}

void Batter::display(ostream & out)
{
	out <<setw(2)<< left << getPosition() 
		<< setw(19) << right << getName() 
		<< setw(10)<<setprecision(3) << calculateBattingAvg()
		<< setw(11) << getHR() 
		<< setw(11) << getRBI()
		<< setw(8) << getSB()<< endl;
}
