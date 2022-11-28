#pragma once

#include "Stats.h"

class Stats;

class Items {
public:
    static void InstantiateSubStats(Stats* s);
    static int FrozenHeartRockSolid(int damage, Stats* s);
    static int WeaponBonus();
private:
    static void Head(Stats* s);
    static void Shoulder(Stats* s);
    static void Chest(Stats* s);
    static void Wrist(Stats* s);
    static void Hands(Stats* s);
    static void Waist(Stats* s);
    static void Legs(Stats* s);
    static void Feet(Stats* s);
    static void Neck(Stats* s);
    static void Back(Stats* s);
    static void Ring1(Stats* s);
    static void Ring2(Stats* s);
    static void Trinket1(Stats* s);
    static void Trinket2(Stats* s);
    static void Weapon(Stats* s);
    static void Offhand(Stats* s);
    static void Race(Stats* s); //Blood elf crit chance
    static void Renown(Stats* s);
    static void Torghast(Stats* s);
};
