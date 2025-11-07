//rpg.h
#ifndef RPG_H
#define RPG_H

#include <string>
using namespace std;

const int INVENTORY_SIZE = 10;   // (not used, kept from spec)
const float HIT_FACTOR = 0.05f;  // luck makes you harder to hit
const int MAX_HITS_TAKEN = 3;    // 3 hits = dead

class RPG {
public:
    // constructors / destructor
    RPG();
    RPG(string name, int hits_taken, float luck, float exp, int level);
    ~RPG(); //new

    // accessors
    string getName()  const;
    int    getHitsTaken() const;
    float  getLuck()  const;
    float  getExp()   const;
    int    getLevel() const;

    // mutators / actions
    bool isAlive() const;
    void setHitsTaken(int new_hits);
    void setName(string name); //NEW
    void updateExpLevel();     //NEW
    void attack(RPG *opponent); //NEW
    void printStats() const;    //NEW

private:
    string name;
    int    hits_taken;
    float  luck;
    float  exp;
    int    level;
};

#endif
