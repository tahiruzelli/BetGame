#pragma once
#include "pch.h"
#include <iostream>

using namespace std;

class Scene {
private : 
public: 
	char scene[sceneWidth][sceneHeight];
	void drawScreen();
	void drawStringLine(string str, int x, int y);
	void prepareScreen(int luckyNumber,
		int currentRound,
		double tableBalance,
		string mostRichPersonName,
		double mostRichPersonMoney);
	void gameOverScreen(int currentRound,double tableBalance);
	void cleanScreen();
};