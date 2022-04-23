#include "MindBlast.h"
#include "SWPain.h"
#include "MindFlay.h"
#include "TollTheDead.h"
#include "Controller.h"

int main() {
    auto *a = new Stats();
    auto *controller = new Controller(a);
    vector<Spell*> actives;
    string nextInstruction, strInput2;
    int intInput1, intInput2;
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    while (true) {
        printf("Next Instruction: ");
        cin >> nextInstruction;

        if (nextInstruction == "next") { //TODO simplify in Controller, implement rolling
            int mastery = a->calcMastery();
            int modifier;
            int diceAmount;
            for (int i = 0 ; i < actives.size() ; i++) {
                modifier = actives[i]->mainDamage.modifier + mastery + Items::WeaponBonus();
                diceAmount = actives[i]->mainDamage.diceAmount;
                if (actives[i]->attackRoll) {
                    bool hit = true;
                    cout << actives[i]->target << ":" << actives[i]->name << " advantage/disadvantage: " << flush;
                    cin >> strInput2;
                    int roll = controller->getRoll(20);
                    if (strInput2 == "advantage" or strInput2 == "a") {
                        int roll2 = controller->getRoll(20);
                        roll = max(roll, roll2);
                    } else if (strInput2 == "disadvantage" or strInput2 == "d") {
                        int roll2 = controller->getRoll(20);
                        roll = min(roll, roll2);
                    }
                    if (roll >= a->calcCritChance())
                        diceAmount *= 2;
                    else if (roll == 1)
                        hit = false;
                    else {
                        roll += a->calcMod(MAINMODIFIER) + a->proficiencyBonus;
                        cout << "Does a " << roll << " hit? " << flush;
                        cin >> strInput2;
                        if (strInput2 == "no")
                            hit = false;
                    }

                    if (!hit) {
                        printf("%s on %s misses\n", actives[i]->name.c_str(), actives[i]->target.c_str());
                        if (actives[i]->masteryStack && a->masteryStacks > 0) a->masteryStacks--;
                        actives.erase(actives.begin()+(i--));
                        continue;
                    }
                }
                printf("%s: %dd%d+%d = %d %s damage\n", actives[i]->target.c_str(), diceAmount, actives[i]->mainDamage.diceType, modifier, controller->rollDice(diceAmount, actives[i]->mainDamage.diceType) + modifier, actives[i]->mainDamage.damageType.c_str());
                if (--actives[i]->duration == 0) {
                    if (actives[i]->masteryStack && a->masteryStacks > 0) a->masteryStacks--;
                    actives.erase(actives.begin()+(i--));
                }
            }
            cout << "Next Turn: " << 2 + a->hasteTurns(controller->getRoll(20)) << " actions" << endl;
        }
        else if (nextInstruction == "cast") { //TODO add more spells and simplify in Controller
            printf("Target: ");
            cin >> strInput2;
            cout << "Spell Number: " << flush;
            cin >> intInput1;
            if (intInput1 == 0)
                actives.push_back(new MindBlast(a, a->level, strInput2));
            else if (intInput1 == 1)
                actives.push_back(new TollTheDead(a, a->level, strInput2));
            else {
                cout << "Level: " << flush;
                cin >> intInput2;
                if (a->spellSlots[intInput2-1] > 0)
                    a->spellSlots[intInput2-1]--;
                else {
                    cout << "No spell slots of level " << intInput2 << " left!" << endl;
                    continue;
                }
                a->masteryStacks++;
                switch (intInput1) {
                    case 2:
                        actives.push_back(new SWPain(a, intInput2, strInput2));
                        break;
                    case 3:
                        actives.push_back(new MindFlay(a, intInput2, strInput2));
                        break;
                    default:
                        cout << "Invalid spell" << endl;
                }
            }
        }
        else if (nextInstruction == "help") { //TODO add commands
            cout << "help cast spelllist active endspell damage heal roll check save modifier initiative test exit next" << endl;
        }
        else if (nextInstruction == "spelllist") { //TODO expand spelllist
            cout << "0-Mind Blast ; 1-Toll the Dead ; 2-Shadow Word:Pain ; 3-Mind Flay ; MORE" << endl;
        }
        else if (nextInstruction == "active") {
            for (Spell* spell : actives) {
                cout << spell->target << ":" << spell->name << " ";
            }
            cout << endl;
        } //DONE
        else if (nextInstruction == "endspell") {
            cout << "Remove #: " << flush;
            cin >> intInput1;
            if (intInput1 < 0 or intInput1 >= actives.size())
                cout << "Not a valid spell" << endl;
            else {
                if (actives[intInput1]->masteryStack)
                    a->masteryStacks--;
                actives.erase(actives.begin() + intInput1);
            }
        } //DONE
        else if (nextInstruction == "damage" || nextInstruction == "heal") {
            cout << "Amount: " << flush;
            cin >> intInput1;
            controller->changeHealth(nextInstruction,intInput1);
        } //DONE
        else if (nextInstruction == "roll") {
            cout << "die: " << flush;
            cin >> intInput1;
            cout << controller->getRoll(intInput1) << endl;
        } //DONE
        else if (nextInstruction == "check" || nextInstruction == "save") {
            cout << "Stat: " << flush;
            cin >> intInput1;
            cout << "Proficient: " << flush;
            cin >> strInput2;
            cout << controller->getRoll(20) + a->calcMod(intInput1) + (strInput2 == "yes" ? a->proficiencyBonus : 0) << endl;
        } //DONE
        else if (nextInstruction == "modifier") {
            cout << "Stat: " << flush;
            cin >> intInput1;
            cout << a->calcMod(intInput1) << endl;
        } //DONE
        else if (nextInstruction == "initiative") {
            controller->rollInitiative();
        } //DONE
        else if (nextInstruction == "test") {
            a->testStats();
        } //DONE
        else if (nextInstruction == "exit") {
            exit(EXIT_SUCCESS);
        } //DONE
    }
#pragma clang diagnostic pop
}
//TODO implement Channel Divinity
//TODO implement +12 damage per failed Wis Save
//TODO implement +1d6 per attack