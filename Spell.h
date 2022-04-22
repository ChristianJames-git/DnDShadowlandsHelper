#include "Stats.h"
#include <vector>

#ifndef Spell_H
#define Spell_H

#define STRENGTH 0
#define DEXTERITY 1
#define CONSTITUTION 2
#define INTELLIGENCE 3
#define WISDOM 4
#define CHARISMA 5

#define MAINMODIFIER WISDOM

struct spellStats {
    int diceAmount = 1;
    int diceType = 6;
    int modifier = 0;
    string damageType;
};

class Spell {
public:
    spellStats mainDamage;
    string name;
    int duration{};
    int differentDice = 1;
    bool hasSpecialOut = false;
    string specialOut;
    string target;
    vector<spellStats*> q;
    bool masteryStack = true;
};

#endif