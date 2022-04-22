#include "MindFlay.h"

#include <utility>

MindFlay::MindFlay(Stats *a, int level, string targ) { //TODO implement spell ending on a miss
    name = "Mind Flay";
    duration = 100;

    mainDamage.diceAmount = 2+level;
    mainDamage.diceType = 8;
    mainDamage.modifier = a->calcMod(MAINMODIFIER) + a->calcVersatility();

    target = std::move(targ);

    hasSpecialOut = true;
    specialOut = target + "'s speed is reduced to 0!";
}
