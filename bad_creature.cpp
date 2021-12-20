#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Bad_creature::Bad_creature(string &name, Creature_society society, int lifetime, int threshold)
    : Creature(name, society, lifetime, threshold) {
    cout << "Creation of a bad creature" << endl;
}

void Bad_creature::clone() const {

}

void Bad_creature::bless() const {

}

void Bad_creature::beat() const {

}

Bad_creature::~Bad_creature() {
    cout << "Destruction of a bad creature" << endl;;
}