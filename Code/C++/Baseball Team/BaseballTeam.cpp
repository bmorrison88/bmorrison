// Author: Brandon Morrison
// CS 240 - Intro to Computing III
// Date Completed: 10/5/15
// Descrption: Implementation of the BaseballTeam class.

#include "BaseballTeam.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "BaseBallPlayer.h"
#include "Pitcher.h"
#include "Batter.h"

BaseballTeam::BaseballTeam()
{
}

BaseballTeam::BaseballTeam(const BaseballTeam & t)
{
}

BaseballTeam & BaseballTeam::operator=(const BaseballTeam & t)
{
	return *this;
}

BaseballTeam::~BaseballTeam()
{
	for (int i = 0; i < TEAM_SIZE; i++)
	{
		delete team[i];
	}
}

void BaseballTeam::loadTeam(istream & in)
{
	for (int i = 0; i < NUMBER_PITCHERS; i++)
	{
		Pitcher *p = new Pitcher;
		team[i] = p;
		static_cast<Pitcher*> (team[i])->loadData(in);
	}
	for (int i = 10; i < NUMBER_BATTERS + NUMBER_BATTERS; i++)
	{
		Batter *b = new Batter;
		team[i] = b;
		static_cast<Batter*> (team[i])->loadData(in);
	}
	for (int i = 20; i < TEAM_SIZE; i++)
	{
		BaseballPlayer *bp = new BaseballPlayer;
		team[i] = bp;
		(*team[i]).loadData(in);
	}
}

void BaseballTeam::displayTeam(ostream & out)
{
	out << "				Team Data		" << endl << endl;
	out << "			    Individual Stats		" << endl;
	out << "Pitchers:" << endl;
	out << "Pos:		Name:	   Wins:	Saves:	  ERA:	  WHIP:" << endl;
	out << "------------------------------------------------------------------------" << endl;
	
	for (int i = 0; i < NUMBER_PITCHERS; i++)
	{
		static_cast<Pitcher*> (team[i])->display(out);
	}
	
	out << endl;
	out << "Batters:" << endl;
	out << "Pos:		Name:	   Bavg:	HR:	  RBI:	  SB:" << endl;
	out << "------------------------------------------------------------------------" << endl;

	for (int i = 10; i < NUMBER_BATTERS + NUMBER_PITCHERS; i++)
	{
		static_cast<Batter*> (team[i])->display(out);
	}

	out << endl;
	out << "Subs:" << endl;
	out << "Pos:		Name:	   " << endl;
	out << "------------------------------------------------------------------------" << endl;
	
	for (int i = 20; i < TEAM_SIZE; i++)
	{
		(*team[i]).display(out);
	}
	out << endl;
	showTotals(out);
}

void BaseballTeam::showTotals(ostream & out)
{
	out << "Team Totals:" << endl << endl;
	out << "Pitchers:" << endl << endl;
	out << "Wins:	Saves:	ERA:	WHIP:	" << endl;
	out << "----------------------------------------------" << endl;
	out << setw(3) <<calculateTeamWins() 
		<< setw(8) << calculateTeamSaves() 
		<< setw(8) << setprecision(3) << calculateTeamERA() 
		<< setw(8) << setprecision(4) << calculateTeamWHIP() << endl <<endl;

	out << "Batters:" << endl << endl;
	out << "BatAvg:    HR:    RBI:     SB:" << endl;
	out << "----------------------------------------------" << endl;
	out << setw(3) << calculateTeamBA()
		<< setw(8) << calculateTeamHomeRuns()
		<< setw(8) << calculateTeamRBI()
		<< setw(8) << calculateTeamSB() << endl << endl;
}

void BaseballTeam::deleteTeam()
{
	for (int i = 0; i < TEAM_SIZE; i++)
	{
		delete team[i];
		team[i] = NULL;
	}
}

int BaseballTeam::calculateTeamWins() const
{
	int totalWins = 0;
	for (int i = 0; i < NUMBER_PITCHERS; i++){
		totalWins += static_cast<Pitcher*>(team[i])->getWins();
	}
	return totalWins;
}

int BaseballTeam::calculateTeamSaves() const
{
	int totalSaves = 0;
	for (int i = 0; i < NUMBER_PITCHERS; i++) {
		totalSaves += static_cast<Pitcher*>(team[i])->getSaves();
	}
	return totalSaves;
}

double BaseballTeam::calculateTeamERA() const
{
	double totER = 0;
	double totInn = 0;
	
	for (int i = 0; i < NUMBER_PITCHERS; i++) {
		totER += static_cast<Pitcher*>(team[i])->getEarnedRuns();
		totInn += static_cast<Pitcher*>(team[i])->getInningsPitched();
	}
	return totER / totInn * INNINGS_PER_GAME;
}

double BaseballTeam::calculateTeamWHIP() const
{
	double totHits = 0;
	double totWalks = 0;
	double totInn = 0;

	for (int i = 0; i < NUMBER_PITCHERS; i++) {
		totHits += static_cast<Pitcher*>(team[i])->getHits();
		totWalks += static_cast<Pitcher*>(team[i])->getWalks();
		totInn += static_cast<Pitcher*>(team[i])->getInningsPitched();
	}
	return (totHits + totWalks) / totInn;
}

double BaseballTeam::calculateTeamBA() const
{
	double totHits = 0;
	double totAtBats = 0;
	for (int i = 10; i < NUMBER_BATTERS + NUMBER_PITCHERS; i++) {
		totHits += static_cast<Batter*>(team[i])->getHits();
		totAtBats += static_cast<Batter*>(team[i])->getAtBats();
	}
	return totHits / totAtBats;
}

int BaseballTeam::calculateTeamHomeRuns() const
{
	int totalHR = 0;
	for (int i = 10; i < NUMBER_BATTERS + NUMBER_PITCHERS; i++) {
		totalHR += static_cast<Batter*>(team[i])->getHR();
	}
	return totalHR;
}

int BaseballTeam::calculateTeamRBI() const
{
	int totalRBI = 0;
	for (int i = 10; i < NUMBER_BATTERS + NUMBER_PITCHERS; i++) {
		totalRBI += static_cast<Batter*>(team[i])->getRBI();
	}
	return totalRBI;
}

int BaseballTeam::calculateTeamSB() const
{
	int totalSB = 0;
	for (int i = 10; i < NUMBER_BATTERS + NUMBER_PITCHERS; i++) {
		totalSB += static_cast<Batter*>(team[i])->getSB();
	}
	return totalSB;
}
