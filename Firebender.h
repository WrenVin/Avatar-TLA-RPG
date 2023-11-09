#ifndef FIREBENDER_H
#define FIREBENDER_H
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class Firebender : public Character
{
private:
    string bendingStrength;
    string bendingWeakness;
public:
    Firebender(string name, int playerID);
    Firebender(string name, int health, int level, int playerID, vector<string> inventory);
    ~Firebender();
    string getBendingType();
    string getBendingStrength();
    string getBendingWeakness();
    void printCharacter();
};

Firebender::Firebender(string name, int playerID) : Character(name, "Fire", playerID)
{
    bendingStrength = "Air";
    bendingWeakness = "Water";
}

Firebender::Firebender(string name, int health, int level, int playerID, vector<string> inventory) : Character(name, "Fire", health, level, playerID, inventory)
{
    bendingStrength = "Air";
    bendingWeakness = "Water";
}

Firebender::~Firebender()
{
}

string Firebender::getBendingStrength()
{
    return bendingStrength;
}

string Firebender::getBendingWeakness()
{
    return bendingWeakness;
}

void Firebender::printCharacter()
{
    cout << "Name: " << getName() << endl;
    cout << "Element: " << getElement() << endl;
    cout << "Health: " << getHealth() << endl;
    cout << "Level: " << getLevel() << endl;
    cout << "Bending Strength: " << bendingStrength << endl;
    cout << "Bending Weakness: " << bendingWeakness << endl;
    cout << "Inventory: " << endl;
    if(inventory.size() == 0)
    {
        cout << "Empty" << endl;
    }
    for (int i = 0; i < getInventory().size(); i++)
    {
        cout << getInventory(i) << endl;
    }
}

#endif
