#include "Stats.h"

#ifndef Spell_H
#define Spell_H

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
    string target;
};

#endif