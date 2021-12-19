#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Good_creature::Good_creature(string &name, int lifetime, int threshlod) 
    : Creature(name, lifetime) {
    cout << "Creation of a good creature" << endl;
} 

bool Good_creature::is_a_good() const {
    return true;
}

void Good_creature::clone() const {

}

void Good_creature::bless() const {


}

void Good_creature::beat() const {

}

Good_creature::~Good_creature() {
    cout << "Destruction of a good creature" << endl;
}