# OOP_C
3rd excercise in OPP / 2021-2022


Εντολη μεταγλωτισης και συνδεσης προγραμματος:

g++ -o myprog main.cpp creature.cpp good_creature.cpp bad_creature.cpp creature_society.cpp

Εντολη εκτελεσης προγραμματος:

./myprog 

Εντολη για ελεχνος leaks και errors:

valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./myprog 