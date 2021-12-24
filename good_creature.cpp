#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Good_creature::Good_creature(string &name, Creature_society society, int lifetime, int threshold, int creat_pos) 
    : Creature(name, society, lifetime, threshold, creat_pos) {
    cout << "Creation of a good creature" << endl;
}

Good_creature::Good_creature(const Good_creature& creature) 
    : Creature(creature) {
    cout << "Created a good creature by copying" << endl;
}

bool Good_creature::is_a_good() const { 
    return true; 
}

void Good_creature::clone(Creature *creature) {
    int temp_pos = 1;     //getting the position before that in order to copy it
    delete creature;
    // delete my_society->external_access(temp_pos);
    // my_society->external_access(temp_pos) = new Good_creature(*this);
    creature = new Good_creature(*this);
    cout << "Good creature " << name << " was cloned." << endl;
}

void Good_creature::bless() {
        // cout << "BLESSSS" << endl;
    if (lifetime > 0) {        // is_a_zobie == false
        if (++lifetime > threshold) {
            my_society->clone_next(society_pos);    // clone creature from society_pos
        }
        cout << "Good creature: " << name << " has been blessed." << endl;
    }
    else {
        cout << "Creature: " << name << " is a zobie." << endl;
    }
}

void Good_creature::beat() {
    if (lifetime > 0) {
        lifetime--;
        cout << "Good creature: " << name << " has been beated." << endl;
    }
    else {
        cout << "Creature: " << name << " is a zobie." << endl;
    }
}

Good_creature::~Good_creature() {
    cout << "Destruction of a good creature" << endl;
}