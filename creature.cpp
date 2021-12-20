#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Creature::Creature(string &name, Creature_society society, int lifetime, int threshold) {
    cout << "Creature constructor" << endl;
    this->name = name;
    this->expected_lifetime = lifetime;
    this->threshold = threshold;
    this->my_society = &society;
    cout << "Creature's name: " << name << 
    " /Creature's lifetime: " << expected_lifetime << endl;
}

bool Creature::is_a_zompie() const {
    if (expected_lifetime == 0) {
        return true;
    }
    return false;
}

Creature::~Creature() {
    cout << " Creature destructor" << endl;
}