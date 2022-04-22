#pragma once

#include "Stats.h"

class Stats;

class Items {
public:
    static void InstantiateSubStats(Stats* s);
    static int FrozenHeart(int damage, Stats* s);
    static int WeaponBonus();
private:
    static void Head(Stats* s);
    static void Shoulders(Stats* s);
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
};
