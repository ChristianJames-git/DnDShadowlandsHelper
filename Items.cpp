#include "Items.h"

void Items::InstantiateSubStats(Stats *s) {
    Head(s); //CALL THIS LAST
}

int Items::FrozenHeart(int damage, Stats* s) {
    int vers = 7 + s->calcVersatility();
    double mitigated = (double)damage * vers / 100.00;
    vers = ceil(mitigated);
    return vers;
}

int Items::WeaponBonus() {
    return 3;
}

/**
 * Demonic Embrace
 * Legendary Item
 * +6 Intelligence, Wisdom, or Charisma
 * +4 Constitution
 * Passive- Dark Pact: Gain Intelligence, Wisdom, or Charisma equal to 2% of your maximum health (rounded up) (4)
 * Passive- Azakana Gaze: Dealing magic damage curses enemies, causing them to take additional damage equal to 30% of the damage dealt.
 */
void Items::Head(Stats *s) {
    s->changeMainStats(MAINMODIFIER, 6);
    s->changeMainStats(CONSTITUTION, 4);
    s->changeMainStats(MAINMODIFIER, (s->getHealth()+49)/50); //Dark Pact Passive
    //Azakana Gaze Passive Elsewhere
}

static void Shoulders(Stats* s) {
    
}
