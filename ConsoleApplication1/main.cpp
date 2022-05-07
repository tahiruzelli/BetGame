#include "pch.h"
#include <iostream>
#include "Scene.h"
#include "FileReader.h"
#include "Game.h"

using namespace std;


int main()
{   
    FileReader* fileReader = new FileReader();
    fileReader->run("C:/Users/Tahir Uzelli/source/repos/ConsoleApplication1/Kisiler.txt");
    
    Game* game = new Game();
    game->persons = fileReader->persons2;
    game->play();
    return 0;

}
