//game.cpp
#include "Game.h"
#include <iostream>
#include <random>
#include <iterator>   // advance
using namespace std;

Game::Game() {}

Game::~Game() {}

/*
 * Create n players, name them NPC_0 ... NPC_(n-1), and mark all alive.
 */
void Game::generatePlayers(int n){
    for (int i = 0; i < n; ++i) {
        players.push_back(new RPG());           // default RPG
        string new_name = "NPC_" + to_string(i);
        players[i]->setName(new_name);
        live_players.insert(i);
    }
}

/*
 * Pick a random index from the set of live players.
 */
int Game::selectPlayer(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, static_cast<int>(live_players.size()) - 1);

    int randomIndex = dist(gen);

    set<int>::iterator it = live_players.begin();
    advance(it, randomIndex);  // move iterator to that position
    return *it;                // actual players[] index
}

/*
 * Winner gets reset hits, gains exp/level, loser is removed from live_players.
 * Also print "NPC_X won against NPC_Y".
 */
void Game::endRound(RPG *winner, RPG *loser, int loserIndex){
    winner->setHitsTaken(0);
    live_players.erase(loserIndex);
    winner->updateExpLevel();

    cout << winner->getName() << " won against " << loser->getName() << "\n";
}

/*
 * Pick two different live players.
 * They take turns attacking until one dies.
 * Then we call endRound with the proper pointers and loser index.
 */
void Game::battleRound(){
    int idx1 = selectPlayer();
    int idx2 = selectPlayer();

    if (idx1 == idx2) {         // avoid fighting self; try again
        battleRound();
        return;
    }

    RPG *p1 = players[idx1];
    RPG *p2 = players[idx2];

    while (p1->isAlive() && p2->isAlive()) {
        p1->attack(p2);
        if (!p2->isAlive()) break;
        p2->attack(p1);
    }

    if (p1->isAlive())
        endRound(p1, p2, idx2);
    else
        endRound(p2, p1, idx1);
}

/*
 * Keep running rounds until only one index is left in live_players.
 */
void Game::gameLoop(){
   while (live_players.size() > 1) {
        battleRound();
    }
}

/*
 * Print stats for every player.
 */
void Game::printFinalResults(){
    for (RPG* p : players) {
        p->printStats();
    }
}