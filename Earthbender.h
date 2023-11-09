#ifndef EARTHBENDER_H
#define EARTHBENDER_H
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class Earthbender : public Character
{
private:
    string bendingStrength;
    string bendingWeakness;
public:
    Earthbender(string name, int playerID);
    Earthbender(string name, int health, int level, int playerID, vector<string> inventory);
    ~Earthbender();
    string getBendingType();
    string getBendingStrength();
    string getBendingWeakness();
    void printCharacter();
};

Earthbender::Earthbender(string name, int playerID) : Character(name, "Earth", playerID)
{
    bendingStrength = "Fire";
    bendingWeakness = "Air";
}

Earthbender::Earthbender(string name, int health, int level, int playerID, vector<string> inventory) : Character(name, "Earth", health, level, playerID, inventory)
{
    bendingStrength = "Fire";
    bendingWeakness = "Air";
}

Earthbender::~Earthbender()
{
}

string Earthbender::getBendingStrength()
{
    return bendingStrength;
}

string Earthbender::getBendingWeakness()
{
    return bendingWeakness;
}

void Earthbender::printCharacter()
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