#include "SWPain.h"

#include <utility>

/**
 * First level spell.
 * 40 foot range.
 * Your target makes a Wisdom saving throw, or takes 2d6 Necrotic damage.
 * If the target succeeds, they take no damage, but Shadow Word:Pain stays on the target.
 * Repeat again for the next 12 seconds.
 * This spell’s damage increases by 1d6 per level cast after first level.
 * @param a
 * @param level
 * @param targ
 */
SWPain::SWPain(Stats* a, int level, string targ) {
    name = "Shadow Word:Pain";
    duration = 3;
    mainDamage.damageType = "necrotic";
    mainDamage.diceAmount = 1+level;
    mainDamage.modifier = a->calcVersatility();
    target = std::move(targ);
}
