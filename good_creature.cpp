#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Good_creature::Good_creature(string &name, Creature_society *society, int lifetime, int threshold, int creat_pos) 
    : Creature(name, society, lifetime, threshold, creat_pos) {
    cout << "Created a good creature" << endl;
}

Good_creature::Good_creature(const Good_creature& creature) 
    : Creature(creature) {
    cout << "Created a good creature by copying" << endl;
}

bool Good_creature::is_a_good() const { 
    return true; 
}

void Good_creature::clone(int clone_pos) const {
    my_society->good_clone(clone_pos, *this);
    cout << "Good creature " << name << " was cloned." << endl;
    cout << "\t--------------------" << endl;
}

void Good_creature::bless() {
    cout << "\t--------------------" << endl;
    if (lifetime > 0) {        // is_a_zobie == false
        if (++lifetime > threshold) {
            my_society->clone_next(society_pos);    // clone creature from society_pos
        }
        cout << "--> Good creature: " << name << " has been blessed." << endl;
    }
    else {
        cout << "Creature: " << name << " is a zobie." << endl;
    }
}

void Good_creature::beat() {
    cout << "\t--------------------" << endl;
    if (lifetime > 0) {
        cout << "--> Good creature: " << name << " has been beated." << endl;
    }
    else {
        cout << "Creature: " << name << " is a zobie." << endl;
    }
    lifetime--;
}

Good_creature::~Good_creature() {
    if (is_a_zompie() == false) {
        cout << "Destruction of a good creature" << endl;
    }
    else {
        cout << "Destruction of a zobie" << endl;
    }
}