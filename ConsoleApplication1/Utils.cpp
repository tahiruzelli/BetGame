#include "pch.h"
#include <iostream>
#include <windows.h>
#include <cstring> 
#include "Utils.h"
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

    void Utils::changeCursorPosition(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
    
    int Utils::getScreenWidth() {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int columns;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        return columns;
    }

    int Utils::getScreenHeight() {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int rows;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        return rows;
    }
    
    int Utils::getPadding(int total, int size) {
        int padding = (total - size) / 2;
        return padding;
    }
    
    char* Utils::strToCharArray(string str) {
        // assigning value to string s
        string s = str;

        int n = s.length();
        // declaring character array
        char* char_array = new char[n + 1];

        // copying the contents of the
        // string to char array
        strcpy(char_array, s.c_str());

        return char_array;
    }

    int Utils::getCharArrayLength(char* charStr) {
        return strlen(charStr);
    }

    vector<string> Utils::split(string test, char del) {
        test += del; //includes a delimiter at the end so last word is also read
        vector<string> splitted;
        string temp = "";
        for (int i = 0; i < test.length(); i++)
        {
            if (test[i] == del)
            {
                splitted.push_back(temp); //store words in "splitted" vector
                temp = "";
                i++;
            }
            temp += test[i];
        }
        return splitted;
    }