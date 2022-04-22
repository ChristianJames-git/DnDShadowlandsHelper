#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include "Items.h"

#define STRENGTH 0
#define DEXTERITY 1
#define CONSTITUTION 2
#define INTELLIGENCE 3
#define WISDOM 4
#define CHARISMA 5

#define MASTERY 0
#define VERSATILITY 1
#define CRITCHANCE 2
#define HASTE 3

#define MAINMODIFIER WISDOM

using namespace std;

class Items;

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
    void changeMainStats(int stat, int change);
    void changeSubStats(int stat, int change);
    void changeAC(int change);
    int hasteTurns();
    int getHealth();
private:
    void InstantiateSlots(int level);
    void readIn();
    void printSlots();
    void printStats();
    ifstream inStream;
    int health{}, healthMax{};
    int stats[6]{}; //Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma
    int substats[4]{}; //mastery, vers, haste, crit chance
    int AC{};
};