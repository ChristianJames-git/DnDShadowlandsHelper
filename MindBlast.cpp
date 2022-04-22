#include "MindBlast.h"
#include <utility>

MindBlast::MindBlast(Stats* a, int level, string targ) {
    name = "Mind Blast";
    mainDamage.diceType = 8;
    mainDamage.modifier = a->calcVersatility() + a->calcMod(MAINMODIFIER);
    duration = 1;
    mainDamage.damageType = "psychic";
    if (level >= 5) mainDamage.diceAmount++;
    if (level >= 11) mainDamage.diceAmount++;
    if (level >= 17) mainDamage.diceAmount++;
    damageReduction.diceAmount = mainDamage.diceAmount; //TODO implement secondary damage
    damageReduction.modifier = a->calcVersatility();
    damageReduction.damageType = "reduction";
    target = std::move(targ);
    masteryStack = false;
}
