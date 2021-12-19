// header file
using namespace std;

////////////////////////////////
// class Good_creature;
// class Bad_creature;
class Creature_society;

////////////////////////////////
class Creature {
protected:
    string name;
    int expected_lifetime;
private:
    int society_pos;
    Creature_society* society;
public:
    Creature();
    Creature(string&, int);
    Creature(const Creature&);
    virtual ~Creature();

    bool is_a_zompie() const;
    virtual bool is_a_good() const;
    virtual void clone() const {}
    virtual void bless() const {}
    virtual void beat() const {}
};

////////////////////////////////
class Good_creature : public Creature {
private:
    int threshold;
public:
    Good_creature(string&, int, int);
    ~Good_creature();

    bool is_a_good() const;
    void clone() const;
    void bless() const;
    void beat() const;
};

////////////////////////////////
class Bad_creature : public Creature {
private:
    int threshold;
public:
    Bad_creature(string&, int, int);
    ~Bad_creature();

    bool is_a_good() const;
    void clone() const;
    void bless() const;
    void beat() const;
};

////////////////////////////////
class Creature_society {
private:
    int creature_sum;       // summary of creatures
    int good_creatures;
    int zobies;
    Creature** creatures;       // array of creatures (side by side)
public:
    Creature_society(int, int, int, int);
    ~Creature_society();
    
    virtual void bless(int);
    virtual void beat(int);
    void clone_next();
    void clone_zobies();
    int no_of_good();
    int no_of_zobies();
};