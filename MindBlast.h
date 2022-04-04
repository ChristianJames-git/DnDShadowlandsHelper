#include "Spell.h"

class MindBlast : public Spell {
public:
    MindBlast(Stats* a, int level, string targ);
    spellStats damageReduction;
};
