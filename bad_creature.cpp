#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Bad_creature::Bad_creature(string &name, Creature_society society, int lifetime, int threshold, int creat_pos)
    : Creature(name, society, lifetime, threshold, creat_pos) {
    cout << "Creation of a bad creature" << endl;
}

bool Bad_creature::is_a_good() const { 
    return false; 
}

void Bad_creature::clone(Creature *creature) {

}

void Bad_creature::bless() {
    if (lifetime > 0) {
        lifetime++;
        if (lifetime > threshold) {
            my_society->clone_zobies(society_pos);
        }
        cout << "Bad creature: " << name << " has been blessed." << endl;
    }
    else {
        cout << "Creature: " << name << " is a zobie." << endl;
    }
}

void Bad_creature::beat() {

}

Bad_creature::~Bad_creature() {
    cout << "Destruction of a bad creature" << endl;;
}