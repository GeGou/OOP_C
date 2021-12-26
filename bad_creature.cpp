#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Bad_creature::Bad_creature(string &name, Creature_society *society, int lifetime, int threshold, int creat_pos)
    : Creature(name, society, lifetime, threshold, creat_pos) {
    cout << "Created a bad creature" << endl;
}

Bad_creature::Bad_creature(const Bad_creature& creature) 
    : Creature(creature) {
    cout << "Created a bad creature by copying" << endl;
}

bool Bad_creature::is_a_good() const { 
    return false; 
}

void Bad_creature::clone(int clone_pos) const {
    my_society->bad_clone(clone_pos, *this);
    cout << "Bad creature " << name << " was cloned." << endl;
    cout << "\t--------------------" << endl;
}

void Bad_creature::bless() {
    cout << "\t--------------------" << endl;
    if (lifetime > 0) {
        if (++lifetime > threshold) {
            my_society->clone_zobies(society_pos);
        }
        cout << "--> Bad creature: " << name << " has been blessed." << endl;
    }
    else {
        cout << "Creature: " << name << " is a zobie." << endl;
    }
}

void Bad_creature::beat() {
    cout << "\t--------------------" << endl;
    if (lifetime > 0) {
        cout << "--> Bad creature: " << name << " has been beated." << endl;
    }
    else {
        cout << "Creature: " << name << " is a zobie." << endl;
    }
    lifetime--;
}

Bad_creature::~Bad_creature() {
    if (is_a_zompie() == false) {
        cout << "Destruction of a bad creature" << endl;
    }
    else {
        cout << "Destruction of a zobie" << endl;
    }
}