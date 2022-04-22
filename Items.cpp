#include "Items.h"

void Items::InstantiateSubStats(Stats *s) {
    Shoulder(s);
    Chest(s);
    Wrist(s);
    Hands(s);
    Waist(s);
    Legs(s);
    Feet(s);
    Neck(s);
    Back(s);
    Ring1(s);
    Ring2(s);
    Trinket1(s);
    Trinket2(s);
    Weapon(s);
    Offhand(s);
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
 * Passive- Azakana Gaze: Dealing magic damage curses enemies, causing them to take additional damage equal to 30% of the damage dealt. //TODO implement 1.3x
 */
void Items::Head(Stats *s) {
    s->changeMainStats(MAINMODIFIER, 6);
    s->changeMainStats(CONSTITUTION, 4);
    s->changeMainStats(MAINMODIFIER, (s->getHealth()+49)/50); //Dark Pact Passive
    //Azakana Gaze Passive Elsewhere
}

/**
 * Plague-Licked Amice
 * +1 Wisdom
 * +2 Constitution
 * +5% Versatility
 * +3% Mastery
 */
void Items::Shoulder(Stats* s) {
    s->changeMainStats(WISDOM, 1);
    s->changeMainStats(CONSTITUTION, 2);
    s->changeSubStats(VERSATILITY, 5);
    s->changeSubStats(MASTERY, 3);
}

/**
 * Soulsewn Vestments(Chest)
 * Magic Half Plate Armor
 * +1 Wisdom
 * +2 Constitution
 * +4% Critical Strike Chance
 * +6% Mastery
 */
void Items::Chest(Stats *s) {
    s->changeMainStats(WISDOM, 1);
    s->changeMainStats(CONSTITUTION, 2);
    s->changeSubStats(CRITCHANCE, 4);
    s->changeSubStats(MASTERY, 6);
}

/**
 * Necropolis Lord’s Shackles
 * +1 Wisdom
 * +1 Constitution
 * +3% Versatility
 * +4% Mastery
 */
void Items::Wrist(Stats *s) {
    s->changeMainStats(WISDOM, 1);
    s->changeMainStats(CONSTITUTION, 1);
    s->changeSubStats(VERSATILITY, 3);
    s->changeSubStats(MASTERY, 4);
}

/**
 * Grips of Overwhelming Beatings
 * +1 AC
 * +1 Wisdom
 * +2 Constitution
 * +5% Critical Strike Chance
 * +3% Haste
 */
void Items::Hands(Stats *s) {
    s->changeMainStats(WISDOM, 1);
    s->changeMainStats(CONSTITUTION, 2);
    s->changeSubStats(CRITCHANCE, 5);
    s->changeSubStats(HASTE, 3);
}

/**
 * Bloodskin Cord
 * +1 Wisdom
 * +1 Constitution
 */
void Items::Waist(Stats *s) {
    s->changeMainStats(WISDOM, 1);
    s->changeMainStats(CONSTITUTION, 1);
}

/**
 * Purge Protocol Legwraps
 * +1 Wisdom
 * +2 Constitution
 * +4% Haste
 * +6% Mastery
 */
void Items::Legs(Stats *s) {
    s->changeMainStats(WISDOM, 1);
    s->changeMainStats(CONSTITUTION, 2);
    s->changeSubStats(HASTE, 4);
    s->changeSubStats(MASTERY, 6);
}

/**
 * Stradama’s Misplaced Slippers
 * +1 Wisdom
 * +2 Constitution
 * +3% Critical Strike Chance
 * +5% Mastery
 */
void Items::Feet(Stats *s) {
    s->changeMainStats(WISDOM, 1);
    s->changeMainStats(CONSTITUTION, 2);
    s->changeSubStats(CRITCHANCE, 3);
    s->changeSubStats(MASTERY, 5);
}

/**
 * Valeshroud Torque
 * +1 Constitution
 * +5% Critical Strike Chance
 * +5% Haste
 */
void Items::Neck(Stats *s) {
    s->changeMainStats(CONSTITUTION, 1);
    s->changeSubStats(CRITCHANCE, 5);
    s->changeSubStats(HASTE, 5);
}

/**
 * Grim-Veiled Cloak (Back):
 * +1 Wisdom
 * +1 Constitution
 * +5% Vers
 * +5% Mastery
 * Passive - Memory of Cauterizing Shadows: //TODO implement Back Passive
    * When Shadow Word: Pain expires on a target, 3 allies within 30 feet of the target are healed for half of the damage done on the last tick of damage (rounded up)
 */
void Items::Back(Stats *s) {
    s->changeMainStats(WISDOM, 1);
    s->changeMainStats(CONSTITUTION, 1);
    s->changeSubStats(VERSATILITY, 5);
    s->changeSubStats(MASTERY, 5);
}

/**
 * Ritual Commander’s Ring
 * +1 Constitution
 * +5% Critical Strike Chance
 * +7% Versatility
 */
void Items::Ring1(Stats *s) {
    s->changeMainStats(CONSTITUTION, 1);
    s->changeSubStats(CRITCHANCE, 3);
    s->changeSubStats(VERSATILITY, 7);
}

/**
 * Stitchflesh’s Misplaced Signet
 * +1 Constitution
 * +7% Haste
 * +4% Versatility
 */
void Items::Ring2(Stats *s) {
    s->changeMainStats(CONSTITUTION, 1);
    s->changeSubStats(HASTE, 7);
    s->changeSubStats(VERSATILITY, 4);
}

/**
 * Satchel of Misbegotten Minions
 * Trinket
 * +1 Intellect While Equipped
 * Your damaging spells have a chance to draw a minion from the satchel (on a 19-20 for attack roll or 1-2 for saving throw). //TODO implement Satchel Passive
    * This minion will charge towards the enemy that triggered it at a speed of 30 feet per six seconds.
    * This minion cannot be targeted or damaged.
    * Upon reaching the enemy, the minion explodes, and all enemies in a 15 foot radius must make a Constitution saving throw or take 3d6 Necrotic damage.
    * The total damage is increased by 1d6 for each additional enemy in the blast radius besides the target, increasing by a maximum of 4d6.
 */
void Items::Trinket1(Stats *s) {
    s->changeMainStats(MAINMODIFIER, 1);
}

/**
 * Frozen Heart (Trinket)
 * +20% Haste
 * +4 spell points //TODO spell points
 * +8 AC
 * Passive: Rock Solid- Every incoming instance of physical damage is reduced by (7+Your Versatility)%
 * Winter’s Caress: The haste of enemies within 10 feet of you is reduced by 5% //TODO implement this passive
 */
void Items::Trinket2(Stats *s) {
    s->changeSubStats(HASTE, 20);
}

void Items::Weapon(Stats *s) {

}

void Items::Offhand(Stats *s) {

}

void Items::Race(Stats *s) {
    s->changeSubStats(CRITCHANCE, 5);
}