// Author: Brandon Morrison
// CS 240 - Intro to Computing III
// Date Completed: 10/5/15
// Descrption: BaseBallPlayer header file.

/* BaseBallPlayer.h */
#ifndef BASEBALLPLAYER_H
#define BASEBALLPLAYER_H

#include <string>
using namespace std;

class BaseballPlayer {

protected:
	string name;
	string position;
public:
	BaseballPlayer();
	BaseballPlayer(string name, string position);

	string getName() const;
	string getPosition() const;
	void setName(string name);
	void setPosition(string position);
	virtual void display(ostream &out);
	virtual void loadData(istream &in);
};
#endif