#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Good_creature::Good_creature(string &name, Creature_society society, int lifetime, int threshold) 
    : Creature(name, society, lifetime, threshold) {
    cout << "Creation of a good creature" << endl;
}

void Good_creature::clone() const {

}

void Good_creature::bless() {
    if (expected_lifetime > 0) {
        expected_lifetime++;
        if (expected_lifetime > threshold) {
            my_society->clone_next();
        }
        cout << "Good creature: " << name << " has been blessed." << endl;
    }
    else {
        cout << "Creature: " << name << " is a zobie." << endl;
    }
}

void Good_creature::beat() {
    if (expected_lifetime > 0) {
        expected_lifetime--;
        cout << "Good creature: " << name << " has been beat." << endl;
    }
    else {
        cout << "Creature: " << name << " is a zobie." << endl;
    }
}

Good_creature::~Good_creature() {
    cout << "Destruction of a good creature" << endl;
}