#include "Spell.h"
#include <queue>
#include <random>
#include <functional>
#include <chrono>

class Controller {
public:
    explicit Controller(Stats* s);
    int getRoll(int d);

    void changeHealth(const string& direction, int amount);
    void rollInitiative();
private:
    Stats* stats;
    queue<int> d4;
    queue<int> d6;
    queue<int> d8;
    queue<int> d10;
    queue<int> d12;
    queue<int> d20;
    queue<int> d100;
};