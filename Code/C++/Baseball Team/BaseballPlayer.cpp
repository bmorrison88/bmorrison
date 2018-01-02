//Author: Brandon Morrison
//CS 240 - Intro to Computing III
//Date Completed: 10/5/15
//Descrption: Implementation of the BaseballPlayer class.

#include <iostream>
#include <iomanip>
#include <string>
#include "BaseBallPlayer.h"

using namespace std;

BaseballPlayer::BaseballPlayer() {
	name = "";
	position = "";
}

BaseballPlayer::BaseballPlayer(string name, string position) {
	setName(name);
	setPosition(position);
}

string BaseballPlayer::getName() const
{
	return name;
}

string BaseballPlayer::getPosition() const
{
	return position;
}

void BaseballPlayer::setName(string name)
{
	this->name = name;
}

void BaseballPlayer::setPosition(string position)
{
	this->position = position;
}

void BaseballPlayer::loadData(istream & in)
{
	getline(in, name);
	while (name == "") {
		getline(in, name);
	}
	in >> position;
}

void BaseballPlayer::display(ostream & out)
{
	out << setw(3) << left << position
		<< right << name<< endl;
}

