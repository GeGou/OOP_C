// header file
using namespace std;

////////////////////////////////
class Creature_society;

////////////////////////////////
class Creature {
protected:
    string name;
    int expected_lifetime;
    int threshold;
    Creature_society* my_society;
private:
    int society_pos;
public:
    Creature(string&, Creature_society, int, int);    // name, lifetime, threshold
    Creature(const Creature&);
    virtual ~Creature();

    bool is_a_zompie() const;
    virtual bool is_a_good() const = 0;
    virtual void clone() const {}
    virtual void bless() const {}
    virtual void beat() const {}
};

////////////////////////////////
class Good_creature : public Creature {
private:
    int threshold;
public:
    Good_creature(string&, Creature_society, int, int);
    ~Good_creature();

    bool is_a_good() const { return true; }
    void clone() const;
    void bless();
    void beat();
};

////////////////////////////////
class Bad_creature : public Creature {
private:
    int threshold;
public:
    Bad_creature(string&, Creature_society, int, int);
    ~Bad_creature();

    bool is_a_good() const { return false; }
    void clone() const;
    void bless() const;
    void beat() const;
};

////////////////////////////////
class Creature_society {
private:
    int no_of_creatures;       // summary of creatures
    int good_creatures;
    int zobies;
    Creature** creatures;       // array of creatures
public:
    Creature_society(int, int, int, int);       // creatures, lifetime, good_thrsh, bad_thrsh
    ~Creature_society();
    
    void bless(int);
    void beat(int);
    void clone_next();
    void clone_zobies();
    int no_of_good();
    int no_of_zobies();
};