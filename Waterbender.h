#ifndef WATERBENDER_H
#define WATERBENDER_H
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class Waterbender : public Character
{
private:
    string bendingStrength;
    string bendingWeakness;
public:
    Waterbender(string name, int playerID);
    Waterbender(string name, int health, int level, int playerID, vector<string> inventory);
    ~Waterbender();
    string getBendingType();
    string getBendingStrength();
    string getBendingWeakness();
    void printCharacter();
};

Waterbender::Waterbender(string name, int playerID) : Character(name, "Water", playerID)
{
    bendingStrength = "Earth";
    bendingWeakness = "Fire";
}

Waterbender::Waterbender(string name, int health, int level, int playerID, vector<string> inventory) : Character(name, "Water", health, level, playerID, inventory)
{
    bendingStrength = "Earth";
    bendingWeakness = "Fire";
}

Waterbender::~Waterbender()
{
}

string Waterbender::getBendingStrength()
{
    return bendingStrength;
}

string Waterbender::getBendingWeakness()
{
    return bendingWeakness;
}

void Waterbender::printCharacter()
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