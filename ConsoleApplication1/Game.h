#pragma once
#include "pch.h"
#include "Person.h"

using namespace std;

class Game {
private:
public:
	int currentRound;
	int luckyNumber;
	double tableBalance;
	Person mostRichPerson;
	vector<Person> persons{};
	void getMostRichPerson();
	void playThisRound();
	void play();
	void getLuckyPerson();
	int getLuckyNumber();
	double getTableBalance(double missingMoney);
	double getPersonMoney(int luckyNumber,int index);

};