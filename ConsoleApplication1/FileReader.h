#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include "Person.h"

using namespace std;

class FileReader {
private:
public:
	vector<string> lines{};
	vector<Person> persons2{};
	Person* person = new Person();
	void readFile(string path);
	void getPerson(string line);
	void run(string path);
	double toDouble(string txt);
};