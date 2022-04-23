#include "Controller.h"

Controller::Controller(Stats* s) {
    stats = s;
    default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> die;
    auto dice = bind(die,engine);
    for (int i = 0 ; i < 1000 ; i++) {
        d4.push(dice()%4+1);
        d6.push(dice()%6+1);
        d8.push(dice()%8+1);
        d10.push(dice()%10+1);
        d12.push(dice()%12+1);
        d20.push(dice()%20+1);
        d100.push(dice()%100+1);
    }
//    int total4 = 0, total6 = 0, total8 = 0, total10 = 0, total12 = 0, total20 = 0, total100 = 0;
//    while (!d4.empty()) {
//        total4 += d4.front();
//        d4.pop();
//        total6 += d6.front();
//        d6.pop();
//        total8 += d8.front();
//        d8.pop();
//        total10 += d10.front();
//        d10.pop();
//        total12 += d12.front();
//        d12.pop();
//        total20 += d20.front();
//        d20.pop();
//        total100 += d100.front();
//        d100.pop();
//    }
//    cout << total4 / 1000.0 << endl;
//    cout << total6 / 1000.0 << endl;
//    cout << total8 / 1000.0 << endl;
//    cout << total10 / 1000.0 << endl;
//    cout << total12 / 1000.0 << endl;
//    cout << total20 / 1000.0 << endl;
//    cout << total100 / 1000.0 << endl;
}

int Controller::rollDice(int num, int d) {
    int sum = 0;
    for (int i = 0 ; i < num ; i++)
        sum += getRoll(d);
    return sum;
}

int Controller::getRoll(int d) {
    int toReturn;
    switch (d) {
        case 4:
            toReturn = d4.front();
            d4.pop();
            break;
        case 6:
            toReturn = d6.front();
            d6.pop();
            break;
        case 8:
            toReturn = d8.front();
            d8.pop();
            break;
        case 10:
            toReturn = d10.front();
            d10.pop();
            break;
        case 12:
            toReturn = d12.front();
            d12.pop();
            break;
        case 20:
            toReturn = d20.front();
            d20.pop();
            break;
        case 100:
            toReturn = d100.front();
            d100.pop();
            break;
        default:
            toReturn = -1;
    }
    return toReturn;
}

void Controller::changeHealth(const string& direction, int amount) {
    if (direction == "damage")
        amount = stats->takeDamage(amount);
    else
        amount = stats->getHealed(amount);
    if (amount == 0)
        cout << "DOWNED!" << endl; //TODO empty vector of active spells
    else
        cout << "Health: " << amount << endl;
}

void Controller::rollInitiative() {
    cout << getRoll(20) + stats->calcMod(DEXTERITY) << endl;
}
//TODO flesh out Controller