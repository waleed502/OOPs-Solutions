#include <iostream>
using namespace std;


class Hero {
protected:
    string name;
    string type;
    int health;
    double power;
    int experience;

public:

    Hero(string n, string t, int h, double p, int e) {
        name = n;
        type = t;
        health = h;
        power = p;
        experience = e;
    }

    
    void showGameMessage() {
        cout << "Welcome to Fantasy Battle Arena\n";
        cout << "Each hero has its unique attacking style and defense abilities!\n";
        cout << "Let the battle begin!\n";
    }

    
    void displayBasicInfo() {
        cout << "\nHero Name: " << name;
        cout << "\nHero Type: " << type;
        cout << "\nHealth: " << health;
        cout << "\nPower Level: " << power;
        cout << "\nExperience: " << experience << endl;
    }

    
    virtual double attack() = 0;
    virtual double defend() = 0;
};


class Warrior : public Hero {
private:
    string weapon;
    int armor;
    double rage;

public:
	
    Warrior(string n, int h, double p, int e, string w, int a, double r) : Hero(n, "Warrior", h, p, e){ 
        weapon = w;
        armor = a;
        rage = r;
    }

    void display() {
        displayBasicInfo();
        cout << "Weapon: " << weapon;
        cout << "\nArmor Strength: " << armor;
        cout << "\nRage Level: " << rage << endl;
    }

    double attack() override {
        return power * rage + experience;
    }

    double defend() override {
        return armor * 1.5 + health * 0.2;
    }
};


class Mage : public Hero {
private:
    string spell;
    int mana;
    double multiplier;

public:
    Mage(string n, int h, double p, int e, string s, int m, double mul): Hero(n, "Mage", h, p, e) {
        spell = s;
        mana = m;
        multiplier = mul;
    }

    void display() {
        displayBasicInfo();
        cout << "Spell: " << spell;
        cout << "\nMana Points: " << mana;
        cout << "\nMagic Multiplier: " << multiplier << endl;
    }

    double attack() override {
        return power * multiplier + mana * 0.5;
    }

    double defend() override {
        return mana * 0.8 + health * 0.1;
    }
};


class Archer : public Hero {
private:
    string bow;
    int arrows;
    double accuracy;

public:
    Archer(string n, int h, double p, int e, string b, int ar, double acc): Hero(n, "Archer", h, p, e) {
        bow = b;
        arrows = ar;
        accuracy = acc;
    }

    void display() {
        displayBasicInfo();
        cout << "Bow Type: " << bow;
        cout << "\nArrows: " << arrows;
        cout << "\nAccuracy: " << accuracy << endl;
    }

    double attack() override {
        return power * accuracy + arrows * 0.3;
    }

    double defend() override {
        return accuracy * 50 + health * 0.15;
    }
};


int main() {

    
    Warrior w("Thor", 120, 50.5, 40, "Hammer", 80, 1.5);
    Mage m("Merlin", 90, 60.0, 50, "Fireball", 100, 2.0);
    Archer a("Robin", 100, 45.0, 35, "Longbow", 60, 0.9);

    
    w.showGameMessage();

    
    cout << "\nHERO PROFILES";
    w.display();
    m.display();
    a.display();

    
    double wattk = w.attack();
    double wdef = w.defend();

    double mattk = m.attack();
    double mdef = m.defend();

    double aattk = a.attack();
    double aadef = a.defend();

    cout << "\nBATTLE RESULTS";

    cout << "\nWarrior Attack: " << wattk;
    cout << "\nWarrior Defense: " << wdef << endl;

    cout << "\nMage Attack: " << mattk;
    cout << "\nMage Defense: " << mdef << endl;

    cout << "\nArcher Attack: " << aattk;
    cout << "\nArcher Defense: " << aadef << endl;

    
    cout << "SUMMARY\n";

    double maxAttack = wattk;
    string bestHero = "Warrior";

    if (mattk > maxAttack) {
        maxAttack = mattk;
        bestHero = "Mage";
    }

    if (aattk > maxAttack) {
        maxAttack = aattk;
        bestHero = "Archer";
    }

    cout << "Highest Attack Hero: " << bestHero;
    cout << "\nAttack Value: " << maxAttack ;

    return 0;
}