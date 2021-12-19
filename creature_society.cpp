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
        if (x == 0) {       // creating a good creature
            string temp_str = good[rand() % 5];
            temp_str.append(to_string(i));      // making the name unique
            creatures[i] = new Good_creature(temp_str, l, good_thrsh);
        }
        else {      // creating a bad creature
            string temp_str = bad[rand() % 5];
            temp_str.append(to_string(i));    // making the name unique
            creatures[i] = new Bad_creature(temp_str, l, bad_thrsh);
        }
    }

    Creature_society::creature_sum = n;
    Creature_society::good_creatures = n;
    Creature_society::zobies = 0;
}

void Creature_society::bless(int pos) {
    cout << "Society bless." << endl;
    this->creatures[pos]->bless();
}

void Creature_society::beat(int pos) {
    cout << "Society beat." << endl;
    this->creatures[pos]->beat();
}

int Creature_society::no_of_good() {
    return this->good_creatures;
}

int Creature_society::no_of_zobies() {
    return this->zobies;
}

Creature_society::~Creature_society() {
    cout << "Destuction of the creature society" << endl;
}