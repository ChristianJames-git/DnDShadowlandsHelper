#include "MindFlay.h"

#include <utility>

/**
 * Third level spell.
 * 40 foot range.
 * Make a spell attack.
 * On a hit, deal 5d8 + WIS Psychic damage, and the target’s speed is reduced to 0.
 * In addition, you can continue casting mind flay for free each turn after this one until you miss an attack or take another action.
 * This spell’s damage increases by 1d8 per level cast after third level.
 * @param a Stats pointer
 * @param level spell level
 * @param targ target
 */
MindFlay::MindFlay(Stats *a, int level, string targ) {
    name = "Mind Flay";
    duration = 100;

    mainDamage.diceAmount = 2+level;
    mainDamage.diceType = 8;
    mainDamage.modifier = a->calcMod(MAINMODIFIER) + a->calcVersatility();
    mainDamage.damageType = "psychic";

    target = std::move(targ);

    hasSpecialOut = true;
    specialOut = target + "'s speed is reduced to 0!";

    attackRoll = true;
}
