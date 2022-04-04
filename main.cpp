#include "MindBlast.h"
#include "SWPain.h"
#include <vector>

int main() {
    auto *a = new Stats();
    vector<Spell*> actives;
    string input, input2;
    int input3, input4;
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    while (true) {
        printf("Next Instruction: ");
        cin >> input;

        if (input == "next") { //next turn
            for (int i = 0 ; i < actives.size() ; i++) {
                printf("%s %dd%d+%d\n", actives[i]->target.c_str(), actives[i]->mainDamage.diceAmount, actives[i]->mainDamage.diceType, actives[i]->mainDamage.modifier);
                if (--actives[i]->duration == 0) actives.erase(actives.begin()+(i--));
            }
        }
        else if (input == "cast") {
            printf("Target: ");
            cin >> input;
            cout << "Spell Number: " << flush;
            cin >> input3;
            if (input3 == 0)
                actives.push_back(new MindBlast(a, a->level, input));
            else {
                cout << "Level: " << flush;
                cin >> input4;
                if (a->spellSlots[input4-1] > 0)
                    a->spellSlots[input4-1]--;
                else {
                    cout << "No spell slots of level " << input4 << " left!" << endl;
                    continue;
                }
                switch (input3) {
                    case 1:
                        actives.push_back(new SWPain(a, input3, input));
                        break;
                    default:
                        cout << "Invalid spell" << endl;
                }
            }
        }
        else if (input == "spells") {
            cout << "0-Mind Blast ; 1-Shadow Word:Pain ; MORE" << endl;
        }
        else if (input == "active") { //TODO print active list
            for (Spell* spell : actives) {
                cout << spell->target << ":" << spell->name << " ";
            }
            cout << endl;
        }
        else if (input == "endspell") {
            cout << "Remove #: " << flush;
            cin >> input3;
            actives.erase(actives.begin()+input3);
        }
        else if (input == "damage") { //DONE
            cout << "Damage: " << flush;
            cin >> input;
            a->takeDamage(stoi(input));
        }
        else if (input == "roll") { //TODO add random
            cout << "Type: " << flush;
            cin >> input;
            cout << "Roll d" << input << endl;
        }
        else if (input == "modifier") {
            cout << "Stat: " << flush;
            cin >> input;
            cout << a->calcMod(stoi(input)) << endl;
        }
        else if (input == "exit") {
            exit(EXIT_SUCCESS);
        }
    }
#pragma clang diagnostic pop
}
