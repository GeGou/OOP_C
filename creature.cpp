#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Creature::Creature(string &name, int lifetime) {
    cout << "Using creature class" << endl;
    this->name = name;
    this->expected_lifetime = lifetime;
    cout << "Creature's name: " << this->name << 
    " Creature's lifetime: " << this->expected_lifetime << endl;
}

bool Creature::is_a_zompie() const {
    if (Creature::expected_lifetime == 0) {
        return true;
    }
    return false;
}

bool Creature::is_a_good() const{
    cout << "virtual -> is_a_good" << endl;
    return true;
}

Creature::~Creature() {
    cout << " Using creature destructor" << endl;
}