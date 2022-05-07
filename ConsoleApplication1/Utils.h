#pragma once
using namespace std;

class Utils {
public:
    void changeCursorPosition(int x, int y);
    int getScreenWidth();
    int getScreenHeight();
    int getPadding(int total, int size);
    int getCharArrayLength(char* charStr); 
    char* strToCharArray(string str);
    vector<string> split(string str, char del);
};

