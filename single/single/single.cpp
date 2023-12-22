#include <iostream>
#include <vector>

using namespace std;

class Ability {
public:
    virtual void Use() const = 0;
};

class Flight : public Ability {
public:
    void Use() const override {
        cout << "can fly\n";
    }
};

class SuperStrength : public Ability {
public:
    void Use() const override {
        cout << " Has super strength\n";
    }
};

class HealingFactor : public Ability {
public:
    void Use() const override {
        cout << " Can heal himself\n";
    }
};

class ShapeShifting : public Ability {
public:
    void Use() const override {
        cout << " Can transform\n";
    }
};

class SuperSpeed : public Ability {
public:
    void Use() const override {
        cout << "Has superspeed\n";
    }
};

class Bulletproof : public Ability {
public:
    void Use() const override {
        cout << " Has good durable\n";
    }
};

class SpiderSense : public Ability {
public:
    void Use() const override {
        cout << " Has spider sense\n";
    }
};

class Web : public Ability {
public:
    void Use() const override {
        cout << " Can do THWEEP\n";
    }
};

enum Alignment {
    Good,
    Bad
};

class Superhero {
protected:
    string name;
    string race;
    Alignment alignment;
    vector<Ability*> abilities;

public:
    Superhero(const string& name, const string& race, Alignment alignment)
        : name(name), race(race), alignment(alignment) {}

    void AddAbility(Ability* ability) {
        abilities.push_back(ability);
    }

    void ShowAbilities() const {
        cout << name << " (" << race << "): ";
        for (const auto& ability : abilities) {
            ability->Use();
        }
    }

    bool CanFly() const {
        for (const auto& ability : abilities) {
            if (dynamic_cast<Flight*>(ability)) {
                return true;
            }
        }
        return false;
    }
};

class Mystique : public Superhero {
public:
    Mystique()
        : Superhero("Mistique ", " Mutant ", Bad) {
        AddAbility(new ShapeShifting);
    }
};

class Wolverine : public Superhero {
public:
    Wolverine()
        : Superhero("Wolwerine ", " Mutant ", Good) {
        AddAbility(new SuperStrength);
        AddAbility(new HealingFactor);
    }
};

class IronMan : public Superhero {
public:
    IronMan()
        : Superhero("Tony Kark ", " Human ", Good) {
        AddAbility(new Flight);
        AddAbility(new SuperStrength);
        AddAbility(new Bulletproof);
    }
};

class Silver : public Superhero {
public:
    Silver()
        : Superhero("Silver ", " Mutant ", Good) {
        AddAbility(new SuperSpeed);
    }
};

class SpiderMan : public Superhero {
public:
    SpiderMan()
        : Superhero("Spiderman ", " Mutant ", Good) {
        AddAbility(new SuperStrength);
        AddAbility(new SpiderSense);
        AddAbility(new Web);
    }
};


int main() {
    Mystique mystique;
    Wolverine wolverine;
    IronMan ironMan;
    Silver silver;
    SpiderMan spiderman;

    vector<Superhero*> superheroes;
    superheroes.push_back(&mystique);
    superheroes.push_back(&wolverine);
    superheroes.push_back(&ironMan);
    superheroes.push_back(&silver);
    superheroes.push_back(&spiderman);
    
    for (const auto& superhero : superheroes) {
        superhero->ShowAbilities();
        
    }

    cout << "Super hero that can fly: \n";
    for (const auto& superhero : superheroes) {
        if (superhero->CanFly()) {
            superhero->ShowAbilities();
        }
    }

    return 0;
}


