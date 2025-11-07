//main.cpp
#include <iostream>
#include "RPG.h"
#include "Game.h"
using namespace std;

int main() {
    Game g;

    int num_players = 10;           
    g.generatePlayers(num_players); 

    g.gameLoop();

    
      //  while(live_players.size()>1){
        //    battleRound();

      //  }
    
    
    
    
    g.printFinalResults();          
    return 0;
}
