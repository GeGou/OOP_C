#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Bad_creature::Bad_creature(string &name, int lifetime, int threshlod)
    : Creature(name, lifetime) {
    cout << "Creation of a bad creature" << endl;
}

bool Bad_creature::is_a_good() const {
    return false;
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