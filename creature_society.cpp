#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Creature_society::Creature_society(int n, int l, int good_thrsh, int bad_thrsh) {
    cout << "Creation of the creature society" << endl;

    // arrays with names for good and bad creatures
    string good[5] = {"Ga", "Gb", "Gc", "Gd", "Ge"};
    string bad[5] = {"Ba", "Bb", "Bc", "Bd", "Be"}; 

    // creation of the society
    creatures = new Creature*[n];
    for (int i = 0 ; i < n ; i++) {
        int x = rand() % 2;     // choose for good/bad creature
        if (x == 0) {
            string temp_str = good[rand() % 5];
            temp_str.append(to_string(i));      // making the name unique
            creatures[i] = new Good_creature(temp_str, *this, l, good_thrsh);
        }
        else {
            string temp_str = bad[rand() % 5];
            temp_str.append(to_string(i));    // making the name unique
            creatures[i] = new Bad_creature(temp_str, *this, l, bad_thrsh);
        }
    }
    no_of_creatures = n;
    good_creatures = n;
    zobies = 0;
}

void Creature_society::bless(int pos) {
    creatures[pos]->bless();
}

void Creature_society::beat(int pos) {
    creatures[pos]->beat();
}

void Creature_society::clone_next() {

}

void Creature_society::clone_zobies() {

}

int Creature_society::no_of_good() {
    return good_creatures;
}

int Creature_society::no_of_zobies() {
    return zobies;
}

Creature_society::~Creature_society() {
    // for (int i = 0 ; i < this->no_of_creatures ; i++) {
    //     delete this->creatures[i];
    // }
    // delete[] this->creatures;

    cout << "Destuction of the creature society" << endl;
}