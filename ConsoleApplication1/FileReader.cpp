#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "FileReader.h"
#include "Person.h"
#include "Utils.h"

using namespace std;

vector<std::string> lines{};
Person* person = new Person();
vector<Person> persons2{};

void FileReader::readFile(string path) {
	ifstream file(path);
	string str;
	Utils* utils = new Utils();
	vector<std::string> splitted = utils->split(path, '.');
	if (splitted[splitted.size()- 1] != "txt") {
		throw "FILE FORMAT ERROR";
	}
	else if (file.is_open()) {
		while (getline(file, str)) {
			lines.push_back(str);
		}
	}
	else {
		throw "NO FILE";
	}
}
double FileReader::toDouble(string txt){
	try {
		return stod(txt);
	}
	catch(int newDouble) {
		throw "TO DOUBLE BUG";
		return 0;
	}
}
void FileReader::getPerson(string line) {
	char del = '#';    //delimiter around which string is to be split
	Utils* utils = new Utils();
	vector<std::string> splitted = utils->split(line, del);
	if(splitted.size()==4){
		person->fullName = splitted[0];
		person->money = stod(splitted[1]);
		person->bettOdd = stod(splitted[2]);
		person->bettNumber = stod(splitted[3]);
	}
	else {
		person->fullName = "";
		person->money = 0;
		person->bettOdd = 0;
		person->bettNumber = 0;
		throw "WRONG FORMAT";
	}
	
}
void FileReader::run(string path) {
	readFile(path);
	if (lines.size() == 0) {
		throw "NOT ENOUGH PLAYER";
	}
	else {
		for (int i = 0; i < lines.size(); i++) {
			getPerson(lines[i]);
			persons2.push_back(*person);
		}
	}

}