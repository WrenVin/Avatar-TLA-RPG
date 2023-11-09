#ifndef AIRBENDER_H
#define AIRBENDER_H
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class Airbender : public Character
{
private:
    string bendingStrength;
    string bendingWeakness;

public:
    Airbender(string name, int playerID);
    Airbender(string name, int health, int level, int playerID, vector<string> inventory);
    ~Airbender();
    string getBendingStrength();
    string getBendingWeakness();
    void printCharacter();
    // void getAttacked(int damage, string bendingType) override;
};

Airbender::Airbender(string name, int playerID) : Character(name, "Air", playerID)
{
    bendingStrength = "Water";
    bendingWeakness = "Earth";
}

Airbender::Airbender(string name, int health, int level, int playerID, vector<string> inventory) : Character(name, "Air", health, level, playerID, inventory)
{
    bendingStrength = "Water";
    bendingWeakness = "Earth";
}

Airbender::~Airbender()
{
}

string Airbender::getBendingStrength()
{
    return bendingStrength;
}

string Airbender::getBendingWeakness()
{
    return bendingWeakness;
}

void Airbender::printCharacter()
{
    cout << "Name: " << getName() << endl;
    cout << "Element: " << getElement() << endl;
    cout << "Health: " << getHealth() << endl;
    cout << "Level: " << getLevel() << endl;
    cout << "Bending Strength: " << bendingStrength << endl;
    cout << "Bending Weakness: " << bendingWeakness << endl;
    cout << "Inventory: " << endl;
    if (inventory.size() == 0)
    {
        cout << "Empty" << endl;
    }
    for (int i = 0; i < getInventory().size(); i++)
    {
        cout << getInventory(i) << endl;
    }
}
/*
void Airbender::getAttacked(int damage, string bendingType)
{

    if (bendingType == bendingStrength)
    {
        damage = damage * 0.5;
    }
    else if (bendingType == bendingWeakness)
    {
        damage = damage * 1.5;
    }
    bool evaded = Character::evade();
    if (evaded)
    {
        cout << getName() << " evaded the attack!" << endl;
        return;
    }
    cout << "HERE" << endl;
    Character::getAttacked(damage, bendingType);
}
*/

#endif // !AIRBENDER_H