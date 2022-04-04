#include <iostream>
#include <fstream>

using namespace std;

#ifndef Stats_H
#define Stats_H

class Stats {
public:
    Stats();
    void printSlots();
    void printStats();
    void takeDamage(int damage);
    int calcMod(int index);
    int calcVersatility();
    int calcMastery();
    int health{};
    int spellSlots[9]{};
    int damageDealt{};
    int level{};
private:
    void InstantiateSlots(int level);
    void readIn();
    ifstream inStream;
    int stats[6]{}; //Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma
    int substats[4]{}; //mastery, vers, haste, crit chance
};

#endif