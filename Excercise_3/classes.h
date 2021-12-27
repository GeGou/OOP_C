// header file
using namespace std;

////////////////////////////////
class Creature_society;

////////////////////////////////
class Creature {
protected:
    string name;
    int lifetime;
    int threshold;
    int society_pos;
    Creature_society* my_society;
public:
    Creature(string&, Creature_society*, int, int, int);    // name, society, lifetime, threshold, creat_pos
    Creature(const Creature&);
    virtual ~Creature();

    bool is_a_zompie() const;
    virtual bool is_a_good() const = 0;
    virtual void clone(int) const {}
    virtual void bless() {}
    virtual void beat() {}
};

////////////////////////////////
class Good_creature : public Creature {
private:
public:
    Good_creature(string&, Creature_society*, int, int, int);    // name, society, lifetime, threshold, creat_pos
    Good_creature(const Good_creature&);
    ~Good_creature();

    bool is_a_good() const;
    void clone(int) const;
    void bless();
    void beat();
};

////////////////////////////////
class Bad_creature : public Creature {
private:
public:
    Bad_creature(string&, Creature_society*, int, int, int);
    Bad_creature(const Bad_creature&);
    ~Bad_creature();

    bool is_a_good() const;
    void clone(int) const;
    void bless();
    void beat();
};

////////////////////////////////
class Creature_society {
private:
    int no_of_creatures;       // summary of creatures
    int good_creatures;
    int zobies;
    Creature** creatures;       // array of creatures
public:
    Creature_society(int, int, int, int);       // no_of_creatures, lifetime, good_thrsh, bad_thrsh
    ~Creature_society();
    
    void good_clone(int, const Good_creature&);
    void bad_clone(int, const Bad_creature&);
    void bless(int);
    void beat(int);
    void clone_next(int);   // pos of the creeature in society
    void clone_zobies(int);
    int no_of_cr(void) const;
    int no_of_good();
    int no_of_zobies();
};