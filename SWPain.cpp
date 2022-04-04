#include "SWPain.h"

#include <utility>

SWPain::SWPain(Stats* a, int level, string targ) {
    name = "Shadow Word:Pain";
    duration = 3;
    mainDamage.damageType = "necrotic";
    mainDamage.diceAmount = 1+level;
    mainDamage.modifier = a->calcVersatility() + a->calcMastery();
    target = std::move(targ);
}
