//game.h
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <set>
#include "RPG.h"

class Game {
public:
    Game();
    ~Game();

    void generatePlayers(int n);         // make NPC_0 ... NPC_(n-1)
    int  selectPlayer();                 // pick a live player's index
    void endRound(RPG *winner, RPG *loser, int loserIndex);
    void battleRound();                  // make two random players fight
    void gameLoop();                     // keep battling until one alive
    void printFinalResults();            // print stats of all players

private:
    std::vector<RPG*> players;           // pool of RPG pointers
    std::set<int>     live_players;      // indices into players that are alive
};

#endif
