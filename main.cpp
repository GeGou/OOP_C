#include <iostream>
#include "classes.h"
using namespace std;

int main (int argc, char* argv[]) {
    if (argc == 6) { 
        int n = atoi(argv[1]);       // amount of creatures
        int m = atoi(argv[2]);       // repeats
        int l = atoi(argv[3]);       // lifetime
        int good_thrsh = atoi(argv[4]);
        int bad_thrsh = atoi(argv[5]);
        
        if (n < 1) {
            cout << "There must be at least one creature." << endl;
            return 0;
        }
        if (l <= 0) {
            cout << "The lifetime of creatures must be more than 0." << endl;
            return 0;
        }
        if ((m < 0) || (good_thrsh < 0) || (bad_thrsh < 0)) {
            cout << "The value of some argument must be more than or equal to 0." << endl;
            return 0;
        }

        // creating a society

        Creature_society *my_society;
        my_society = new Creature_society(n, l, good_thrsh, bad_thrsh);

        // Creature_society my_society(n, l, good_thrsh, bad_thrsh);
        srand(time(NULL));      // the start of the generator
        // change the society via beat/bless
        for (int i = 0 ; i < m ; i++) {
            int rand_pos = rand() % n;       // selection of the position (creature)
            int rand_action = rand() % 2;        // 0 -> beat / 1 -> bless
            if (rand_action == 0) {
                my_society->beat(rand_pos);
            }
            else {
                my_society->bless(rand_pos);
            }
            cout << "MAIN: " << i << endl;
        }
        // results
        if (my_society->no_of_good() == n) {
            cout << "Good Dominates in the World" << endl;
        }
        else if (my_society->no_of_zobies() == n) {
            cout << "This is a dead society" << endl;
        }
        else {
            cout << "Try again to improve the world" << endl;
        }
    }
    else {
        cout << "Wrong given arguments" << endl;
    }
    return 0;
}