#include "Stats.h"

Stats::Stats() {
    readIn();
    InstantiateSlots(level);
}

void Stats::InstantiateSlots(int currLevel) {
    if (level < 1 || level > 20)
        cout << "Wrong Level Value" << endl;
    else {
        if (currLevel >= 1) spellSlots[0] = 2;
        if (currLevel >= 2) spellSlots[0]++;
        if (currLevel >= 3) spellSlots[0]++; spellSlots[1] = 2;
        if (currLevel >= 4) spellSlots[1]++;
        if (currLevel >= 5) spellSlots[2] = 2;
        if (currLevel >= 6) spellSlots[2]++;
        if (currLevel >= 7) spellSlots[3] = 1;
        if (currLevel >= 8) spellSlots[3]++;
        if (currLevel >= 9) spellSlots[3]++; spellSlots[4] = 1;
        if (currLevel >= 10) spellSlots[4]++;
        if (currLevel >= 11) spellSlots[5] = 1;
        if (currLevel >= 13) spellSlots[6] = 1;
        if (currLevel >= 15) spellSlots[7] = 1;
        if (currLevel >= 17) spellSlots[8] = 1;
        if (currLevel >= 18) spellSlots[4]++;
        if (currLevel >= 19) spellSlots[5]++;
        if (currLevel >= 20) spellSlots[6]++;
    }
}

void Stats::printSlots() {
    int count = 1;
    for (auto & slot : spellSlots) {
        cout << "Level " << count++ << ": " << slot << endl;
    }
}

void Stats::readIn() {
    inStream.open("stats.txt");
    string temp;
    int line = 1;
    while(inStream.good()) {
        getline(inStream, temp);
        if (temp.empty())
            continue;
        if (line == 1)
            level = stoi(temp);
        else if (line == 2)
            for (int i = 0 ; i < 6 ; i++) {
                stats[i] = stoi(temp.substr(3 * i, 2));
            }
        else if (line == 3)
            for (int i = 0 ; i < 4 ; i++)
                substats[i] = stoi(temp.substr(3*i, 2));
        else if (line == 4)
            health = stoi(temp);
        line++;
    }
    inStream.close();
}

void Stats::printStats() {
    cout << "Strength: " << stats[0] << endl;
    cout << "Dexterity: " << stats[1] << endl;
    cout << "Constitution: " << stats[2] << endl;
    cout << "Intelligence: " << stats[3] << endl;
    cout << "Wisdom: " << stats[4] << endl;
    cout << "Charisma: " << stats[5] << endl;
    cout << endl;
    cout << "Mastery: " << substats[0] << endl;
    cout << "Versatility: " << substats[1] << endl;
    cout << "Haste: " << substats[2] << endl;
    cout << "Crit Chance: " << substats[3] << endl;
    cout << endl;
    cout << "Health: " << health << endl;
}

void Stats::takeDamage(int damage) {
    damage -= substats[1]/5; //versatility
    if (damage < 0) damage = 0;
    health -= damage;
    if (health <= 0) {
        health = 0;
        cout << "Downed" << endl;
    } else
        cout << "Health Left: " << health << endl;
}

int Stats::calcMod(int index) {
    int temp = stats[index]-10;
    if (temp >= 0)
        return temp/2;
    return --temp;
}

int Stats::calcVersatility() {
    return substats[1]/5;
}

int Stats::calcMastery() {
    return substats[0]/5*3;
}
