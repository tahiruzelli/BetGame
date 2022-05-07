#include "pch.h"
#include <iostream>
#include <windows.h>
#include <cstring> 
#include "Scene.h"
#include "Utils.h"

using namespace std;

    Utils* utils = new Utils();
    static const int sceneHeight = 14;
    static const int sceneWidth = 50;
    char scene[sceneWidth][sceneHeight];

    void Scene::drawScreen() {
    for (int y = 0; y < sceneHeight; y++)
    {
        utils->changeCursorPosition(utils->getPadding(utils->getScreenWidth(), sceneWidth), y);
        for (int x = 0; x < sceneWidth; x++)
        {
            cout << scene[x][y];
        }
        cout << endl;

    }
}

    void Scene::drawStringLine(string str, int x, int y) {
          char* charStr = utils->strToCharArray(str);
          int length = utils->getCharArrayLength(charStr);
          int leftPadding = utils->getPadding(46, length);
          if (x >= leftPadding && leftPadding + length > x) {
              scene[x][y] = charStr[x - leftPadding];
          }
      }

    void Scene::prepareScreen(int luckyNumber,
    int currentRound,
    double tableBalance,
    string mostRichPersonName,
    double mostRichPersonMoney) {
          for (int y = 0; y < sceneHeight; y++)
          {
              for (int x = 0; x < sceneWidth; x++)
              {

                  //çerçeve
                  if (y == 0 || y == sceneHeight - 1 || x == 0 || x == sceneWidth - 1 || x == 1 || x == sceneWidth - 2 || y == 2 || y == 3) {
                      scene[x][y] = '#';
                  }
                  //boþluk 
                  else {
                      scene[x][y] = ' ';

                  }
                  //8. en zengin kiþi ayracý
                  if (y == 7 && x != 0 && x != 1 && x != sceneWidth - 1 && x != sceneWidth - 2) {

                      scene[x][y] = '-';
                  }
                  //yazýlar yazdýrýlýyor!
                  switch (y) {
                  case 1:
                      drawStringLine("SANSLI SAYI: " + to_string(luckyNumber), x, y);
                      break;
                  case 4:
                      drawStringLine("TUR: " + to_string(currentRound), x, y);
                      break;
                  case 5:
                      drawStringLine("MASA BAKIYE: " + to_string(tableBalance) + " TL", x, y);
                      break;
                  case 9:
                      drawStringLine("EN ZENGIN KISI", x, y);
                      break;
                  case 10:
                      drawStringLine(mostRichPersonName, x, y);
                      break;
                  case 11:
                      drawStringLine("BAKIYESI: " + to_string(mostRichPersonMoney) + " TL", x, y);
                      break;

                  }
              }
          }
      }
