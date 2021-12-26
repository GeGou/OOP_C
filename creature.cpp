#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Creature::Creature(string &name, Creature_society *society, int lifetime, int threshold, int creat_pos) {
    this->name = name;
    this->lifetime = lifetime;
    this->threshold = threshold;
    this->my_society = society;
    this->society_pos = creat_pos;
    cout << "Created a creature with name: " << name << 
    " /lifetime: " << lifetime << endl;
}

Creature::Creature(const Creature& c) {
    this->name = c.name;
    this->lifetime = c.lifetime;
    this->threshold = c.threshold;
    this->my_society = c.my_society;
    this->society_pos = c.society_pos+1;
    cout << "Created a creature by copy with name: " << name << 
    " lifetime: " << lifetime << endl;
}

bool Creature::is_a_zompie() const {
    if (lifetime <= 0) {
        return true;
    }
    return false;
}

Creature::~Creature() {
    cout << "Creature destructor" << endl;
}