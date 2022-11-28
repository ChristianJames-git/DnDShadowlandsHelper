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

        if (nextInstruction == "next") {
            int mastery = a->calcMastery();
            int modifier, diceAmount, damage;
            bool hit;
            for (int i = 0 ; i < actives.size() ; i++) {
                modifier = actives[i]->mainDamage.modifier + mastery + Items::WeaponBonus();
                diceAmount = actives[i]->mainDamage.diceAmount;
                if (actives[i]->attackRoll)
                    hit = controller->attackRoll(actives[i], &diceAmount);
                else {
                    hit = controller->spellSave(actives[i]);
                    if (hit) modifier += 15; //Zack's Sword
                }
                if (hit) {
                    damage = controller->rollDice(diceAmount, actives[i]->mainDamage.diceType) + modifier;
                    damage = (int)(damage * 1.35);
                    printf("%s: %dd%d+%d = %d %s damage\n", actives[i]->target.c_str(), diceAmount,
                           actives[i]->mainDamage.diceType, modifier, damage,
                           actives[i]->mainDamage.damageType.c_str());
                    a->damageDealt += damage;
                }
                else
                    printf("%s on %s misses\n", actives[i]->name.c_str(), actives[i]->target.c_str());
                if (--actives[i]->duration == 0) {
                    if (actives[i]->masteryStack && a->masteryStacks > 0) a->masteryStacks--;
                    actives.erase(actives.begin()+(i--));
                }
            }
            cout << "Next Turn: " << 2 + a->hasteTurns(controller->getRoll(20)) << " actions" << endl;
        }
        else if (nextInstruction == "cast") { //TODO add more spells and simplify in Controller
            cin >> strInput2; //Target
            cin >> intInput1; //Spell Number
            cin >> intInput2; //Level
            if (intInput1 == 0)
                actives.push_back(new MindBlast(a, a->level, strInput2));
            else if (intInput1 == 1)
                actives.push_back(new TollTheDead(a, a->level, strInput2));
            else {
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
        else if (nextInstruction == "qcast") {
            cin >> intInput1; //Turn
            if (intInput1 < 1)
                intInput1 = 1;
            else if (intInput1 > 5)
                intInput1 = 5;
            a->masteryStacks = 3;
            int mastery = a->calcMastery()*3 + a->calcVersatility() + a->calcMod(MAINMODIFIER);
            int avgDice = 6;
            int avgDiceNum = 8;
            int attacks = 2 + a->hasteTurns(controller->getRoll(20)) + intInput1;

            int damageTot = 0;
            cout << "Round: " << intInput1 << endl;
            for (int i = 0 ; i < attacks ; i++) {
                double damage = (controller->rollDice(avgDice, avgDiceNum) + mastery) * 1.35;
                cout << "Attack #" << i + 1 << ": " << ceil(damage) << endl;
                damageTot += ceil(damage);
            }
            cout << "Total Damage: " << damageTot << endl;
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
            cin >> intInput1;
            controller->changeHealth(nextInstruction,intInput1);
        } //DONE
        else if (nextInstruction == "roll") {
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
//TODO implement +1d6 per attack