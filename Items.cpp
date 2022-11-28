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
    Race(s);
    Renown(s);
    Torghast(s);
    Head(s); //CALL THIS LAST
}

void Items::Torghast(Stats *s) {
    s->changeMainStats(MAINMODIFIER, 10); //
}

int Items::FrozenHeartRockSolid(int damage, Stats* s) {
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
 * +12 (Was 6) Intelligence, Wisdom, or Charisma
 * +8 (Was 4) Constitution
 * Passive- Dark
 * Pact: Gain Intelligence, Wisdom, or Charisma equal to 4% (Was 2) of your maximum health (rounded up) (4)
 * Passive- Azakana Gaze: Dealing magic damage curses enemies, causing them to take additional damage equal to 35% (Was 25) of the damage dealt.
 *
 * Complete Upgrade: 1
 */
void Items::Head(Stats *s) {
    s->changeMainStats(MAINMODIFIER, 12);
    s->changeMainStats(CONSTITUTION, 8);
    s->changeMainStats(MAINMODIFIER, (s->getHealth()+24)/25); //Dark Pact Passive
}

/**
 * Plague-Licked Amice
 * +2 (was 1) Wisdom
 * +4 (was 2) Constitution
 * +10% (was 5) Versatility
 * +6% (was 3) Mastery
 *
 * Complete Upgrade: 1
 */
void Items::Shoulder(Stats* s) {
    s->changeMainStats(WISDOM, 2);
    s->changeMainStats(CONSTITUTION, 4);
    s->changeSubStats(VERSATILITY, 10);
    s->changeSubStats(MASTERY, 6);
}

/**
 * Soulsewn Vestments(Chest)
 * Magic Half Plate Armor
 * AC = 18 (was 15) + DEX(max 2)
 * +2 (was 1) Wisdom
 * +4 (was 2) Constitution
 * +8% (was 4) Critical Strike Chance
 * +12% (was 6) Mastery
 *
 * Complete Upgrade: 1
 */
void Items::Chest(Stats *s) {
    int dexACMod = s->calcMod(DEXTERITY);
    if (dexACMod > 2)
        dexACMod = 2;
    if (dexACMod < 0)
        dexACMod = 0;
    s->changeAC(18 + dexACMod);
    s->changeMainStats(WISDOM, 2);
    s->changeMainStats(CONSTITUTION, 4);
    s->changeSubStats(CRITCHANCE, 8);
    s->changeSubStats(MASTERY, 12);
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
 * Tricksprite Gloves (Hands)
 * +2 Wisdom
 * +2 Constitution
 * +4% Critical Strike Chance
 * +6% Haste
 */
void Items::Hands(Stats *s) {
    s->changeMainStats(WISDOM, 2);
    s->changeMainStats(CONSTITUTION, 2);
    s->changeSubStats(CRITCHANCE, 4);
    s->changeSubStats(HASTE, 6);
}

/**
 * Viller’s Traveling Chain
 * +1 AC
 * +2 Dexterity, Wisdom, Charisma, or Intelligence
 * +2 Constitution
 * +5% Haste
 * +6% Mastery
 */
void Items::Waist(Stats *s) {
    s->changeAC(1);
    s->changeMainStats(MAINMODIFIER, 2);
    s->changeMainStats(CONSTITUTION, 2);
    s->changeSubStats(HASTE, 5);
    s->changeSubStats(MASTERY, 6);
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
 * Trailspinner Pendant (Neck)
 * +4 (was 2) Constitution
 * +14% (was 7%)Critical Strike Chance
 * +24% (was 12%) Mastery
 *
 * Complete Upgrade: 1
 */
void Items::Neck(Stats *s) {
    s->changeMainStats(CONSTITUTION, 4);
    s->changeSubStats(CRITCHANCE, 14);
    s->changeSubStats(MASTERY, 24);
}

/**
 * Shadowflame Prism (Back):
 * +4 (was 2) Wisdom
 * +4 (was 2) Constitution
 * +20% (was 9) Vers
 * +20% (was 9) Mastery
 * Shadowflame Prism: Mind Blast and Shadow Word: Death cause a Shadowfiend to teleport behind a target.
 * This Shadowfiend slashes behind your target.
 * Up to 5 enemies (including the target) within 15 feet of your target must make Dexterity saving throws, taking 10d8 (was 5d8) Necrotic damage on a failed save,
 * or half on a success
 *
 * Complete Upgrade: 1
 * Substat Upgrade: 1
 **/
void Items::Back(Stats *s) {
    s->changeMainStats(WISDOM, 2);
    s->changeMainStats(CONSTITUTION, 2);
    s->changeSubStats(VERSATILITY, 9);
    s->changeSubStats(MASTERY, 9);
}

/**
 * Signet of the False Accuser
 * +2 Constitution
 * +14% (was 7) Haste
 * +22% (was 16) Mastery
 *
 * Substat Upgrade: 1
 */
void Items::Ring1(Stats *s) {
    s->changeMainStats(CONSTITUTION, 2);
    s->changeSubStats(HASTE, 14);
    s->changeSubStats(MASTERY, 22);
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
 * +2 (was 1) Intellect While Equipped
 * Your damaging spells have a chance to draw a minion from the satchel (on a 17-20 (was 19-20) for attack roll or 1-4 (was 1-2) for saving throw). //TODO implement Satchel Passive
    * This minion will charge towards the enemy that triggered it at a speed of 30 feet per six seconds.
    * This minion cannot be targeted or damaged.
    * Upon reaching the enemy, the minion explodes, and all enemies in a 15 foot radius must make a Constitution saving throw or take 6d6 (was 3d6) Necrotic damage.
    * The total damage is increased by 1d6 for each additional enemy in the blast radius besides the target, increasing by a maximum of 4d6.
    *
    * Complete Upgrade: 1
 */
void Items::Trinket1(Stats *s) {
    s->changeMainStats(MAINMODIFIER, 2);
}

/**
 * Frozen Heart (Trinket)
 * +30% (was 20) Haste
 * +4 spell points //TODO spell points
 * +8 AC
 * Passive - Rock Solid: Every incoming instance of physical damage is reduced by (7+Your Versatility)%
 * Passive - Winter’s Caress: The haste of enemies within 10 feet of you is reduced by 5% //TODO implement this passive
 *
 * Substat Upgrade: 1
 */
void Items::Trinket2(Stats *s) {
    s->changeSubStats(HASTE, 20);
    s->changeAC(8);
}

/**
 * Wand of Wandiness (one-hand)
 * +10 Wisdom
 * +25 Constitution
 * +20 to Initiative
 * +6.5 AC
 * +10 spell points
 * +5% Mastery, Versatility, Crit Chance, and Haste
  * This Wand has 5 empty rune slots
 **/
void Items::Weapon(Stats *s) {
    s->changeMainStats(MAINMODIFIER, 10);
    s->changeMainStats(CONSTITUTION, 25);
    s->changeSubStats(CRITCHANCE, 5);
    s->changeSubStats(VERSATILITY, 5);
    s->changeSubStats(MASTERY, 5);
    s->changeSubStats(HASTE, 5);
    s->changeAC(6);
}

/**
 * Encrusted Canopic Lid
 * +2 AC
 * +9 (was 7) Magic Shield
 * +2 (was 1) Strength
 * +4 (was 2) Wisdom
 * +2 (was 1) Constitution
 * +6% (was 3) Critical Strike Chance
 * +4% (was 2) Versatility
 */
void Items::Offhand(Stats *s) {
    s->changeAC(11);
    s->changeMainStats(MAINMODIFIER, 4);
    s->changeMainStats(STRENGTH, 2);
    s->changeMainStats(CONSTITUTION, 2);
    s->changeSubStats(CRITCHANCE, 6);
    s->changeSubStats(VERSATILITY, 4);
}

void Items::Race(Stats *s) {
    s->changeSubStats(CRITCHANCE, 5);
}

void Items::Renown(Stats *s) {
    int con = s->getStats(0, CONSTITUTION);
    con = (con+49) * 2 / 100;
    s->changeMainStats(CONSTITUTION, con);
}
