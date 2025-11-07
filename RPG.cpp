//rpg.cpp
#include "RPG.h"
#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

//default constructor
RPG::RPG()
{
    name="NPC";
    hits_taken = 0;
    luck = 0.1;
    exp = 50;
    level = 1;
}

// Overloaded contructor
RPG::RPG(string name, int hits_taken, float luck, float exp, int level)
{
    this ->name = name;
    this ->hits_taken = hits_taken;
    this ->exp = exp;
    this ->level = level; 
}

// ---------- destructor ----------
RPG::~RPG() { /* empty per lab instructions */ }

// ---------- accessors ----------
string RPG::getName() const       { return name; }
int    RPG::getHitsTaken() const  { return hits_taken; }
float  RPG::getLuck() const       { return luck; }
float  RPG::getExp() const        { return exp; }
int    RPG::getLevel() const      { return level; }

// ---------- core methods ----------
bool RPG::isAlive() const {
    return hits_taken < MAX_HITS_TAKEN;
}

void RPG::setHitsTaken(int new_hits){
    if (new_hits < 0) new_hits = 0;
    hits_taken = new_hits;
}

void RPG::setName(string new_name){ //new
    name = new_name;
}

/*
 * increase exp by 50.
 * if exp >= 100, level up by 1, reset exp to 0, and increase luck by 0.1
 */
void RPG::updateExpLevel(){
    exp += 50.0f;
    if (exp >= 100.0f) {
        level += 1;
        exp = 0.0f;
        luck += 0.1f;
        if (luck > 1.0f) luck = 1.0f; // simple cap
    }
}

/*
 * Try to hit the opponent. Higher opponent luck ⇒ harder to hit.
 * If we hit, opponent's hits_taken increases by 1.
 */
void RPG::attack(RPG *opponent){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    float random_num = static_cast<float>(dis(gen));

    // hit happens when random number beats opponent's luck “shield”
    bool hit = random_num > (HIT_FACTOR * opponent->getLuck());

    if (hit) {
        opponent->setHitsTaken(opponent->getHitsTaken() + 1);
    }
}

/*
 * Print exactly like the example:
 * Name: NPC_X  Hits Taken: X  Luck: 0.100000  Exp: 50.000000  Level: 1  Status: Alive/Dead
 */
void RPG::printStats() const {
    cout << "Name: " << name
         << "\tHits Taken: " << hits_taken
         << "\tLuck: "  << fixed << setprecision(6) << luck
         << "\tExp: "   << fixed << setprecision(6) << exp
         << "\tLevel: " << level
         << "\tStatus: " << (isAlive() ? "Alive" : "Dead")
         << "\n";
}
