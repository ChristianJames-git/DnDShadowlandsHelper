#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#ifndef Stats_H
#define Stats_H

class Stats {
public:
    Stats();
    void testStats();
    int takeDamage(int damage);
    int getHealed(int healing);
    int calcMod(int index);
    int calcVersatility();
    int calcMastery();
    int spellSlots[9]{};
    int damageDealt{};
    int level{};
    int proficiencyBonus{};
    int masteryStacks{};
private:
    void InstantiateSlots(int level);
    void readIn();
    void printSlots();
    void printStats();
    ifstream inStream;
    int health{}, healthMax{};
    int stats[6]{}; //Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma
    int substats[4]{}; //mastery, vers, haste, crit chance
};

#endif