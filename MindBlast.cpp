#include "MindBlast.h"
#include <utility>

/**
 * At first level, you get access to the cantrip mind blast.
 * 40 foot range. Make a spell attack.
 * On a hit, deal 1d8 psychic damage, and you subtract 1d6 damage from their next attack.
 * This spell’s damage increases by 1d8 and its damage reduction increases by 1d6 at 5th level(2d8, 2d6), 11th level(3d8, 3d6), and 17th level(4d8, 4d6).
 * @param a
 * @param level
 * @param targ
 */
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
    attackRoll = true;
}
