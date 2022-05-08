#include "pch.h"
#include <iostream>
#include <random>
#include "Game.h"
#include <Windows.h>
#include "Scene.h"

using namespace std;

int currentRound;
int luckyNumber;
double tableBalance;
Person mostRichPerson;
Person luckyPerson;
vector<Person> persons{};

void Game::getMostRichPerson(){
    for (int i = 0; i < persons.size(); i++) {
        if (i == 0) {
            mostRichPerson = persons[i];
        }
        else {
            if (mostRichPerson.money < persons[i].money) {
                mostRichPerson = persons[i];
            }
        }
    }
}

void Game::playThisRound(){
    luckyNumber = getLuckyNumber();
    getLuckyPerson();
    int deletedCount = 0;
    for (int i = 0; i < persons.size(); i++) {
        if (getPersonMoney(luckyNumber, i) < 1000) {
            persons.erase(persons.begin()+i- deletedCount);
            deletedCount++;
       }
    }
    getMostRichPerson();
}

void Game::getLuckyPerson(){
    for (int i = 0; i < persons.size(); i++) {
        if (luckyNumber == persons[i].bettNumber) {
            luckyPerson = persons[i];
        }
    }
}

void Game::play(){
    Scene* scene = new Scene();
    while (true) {
      
        playThisRound();
        if (persons.size() <= 1) {
            scene->cleanScreen();
            scene->gameOverScreen(currentRound,tableBalance);
            scene->drawScreen();
            delete scene;
            break;
        }
        currentRound++;
    
        scene->prepareScreen(luckyNumber,currentRound,tableBalance,mostRichPerson.fullName,mostRichPerson.money);
        scene->drawScreen();
        Sleep(250); // Kullanýcý deneyimini arttýrmak adýna uygulamayý bekletiyorum.
    }
}

int Game::getLuckyNumber(){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist10(1, 10); // distribution in range [1, 10]
    return dist10(rng);
}

double Game::getTableBalance(double missingMoney) {
    tableBalance = tableBalance - missingMoney;
    return tableBalance;
}

double Game::getPersonMoney(int luckyNumber,int index){
    if (luckyNumber == persons[index].bettNumber) {
        double bettMoney = luckyPerson.money * luckyPerson.bettOdd;
        luckyPerson.money = luckyPerson.money - bettMoney;
        luckyPerson.money = bettMoney * 10;
        persons[index].money = luckyPerson.money;
        getTableBalance(bettMoney * 10);
        return luckyPerson.money;
    }
    else {
        double bettMoney = persons[index].money * persons[index].bettOdd;
        persons[index].money = persons[index].money - bettMoney;
        getTableBalance(bettMoney* -1);
        return persons[index].money;
    }
}
   