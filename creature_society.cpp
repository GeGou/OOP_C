#include <iostream>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Creature_society::Creature_society(int n, int l, int good_thrsh, int bad_thrsh) {
    cout << "Creation of the creature society" << endl;

    // arrays with names for good and bad creatures
    string good[5] = {"Ga", "Gb", "Gc", "Gd", "Ge"};
    string bad[5] = {"Ba", "Bb", "Bc", "Bd", "Be"}; 

    no_of_creatures = n;
    good_creatures = 0;
    zobies = 0;

    // creation of the society
    creatures = new Creature*[n];
    for (int i = 0 ; i < n ; i++) {
        int x = rand() % 2;     // choose for good/bad creature
        if (x == 0) {
            string new_name = good[rand() % 5];
            new_name.append(to_string(i));      // making the name unique
            creatures[i] = new Good_creature(new_name, *this, l, good_thrsh, i);
            good_creatures++;
        }
        else {
            string new_name = bad[rand() % 5];
            new_name.append(to_string(i));    // making the name unique
            creatures[i] = new Bad_creature(new_name, *this, l, bad_thrsh, i);
        }
    }
}

void Creature_society::bless(int pos) {
    creatures[pos]->bless();
}

void Creature_society::beat(int pos) {
    creatures[pos]->beat();
}

void Creature_society::clone_next(int pos) {
    int temp_pos;
    if (pos + 1 == no_of_creatures) {
        temp_pos = -1;
    }
    creatures[pos]->clone(creatures[++temp_pos]);
}

void Creature_society::clone_zobies(int pos) {

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