#include "TollTheDead.h"
#include <utility>

TollTheDead::TollTheDead(Stats *a, int level, string targ) {
    name = "Toll the Dead";
    mainDamage.diceType = 12;
    mainDamage.modifier = a->calcVersatility() + a->calcMod(MAINMODIFIER);
    duration = 1;
    mainDamage.damageType = "necrotic";
    if (level >= 5) mainDamage.diceAmount++;
    if (level >= 11) mainDamage.diceAmount++;
    if (level >= 17) mainDamage.diceAmount++;
    target = std::move(targ);
    masteryStack = false;
}
