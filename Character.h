#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Character
{
private:
    string name;
    string element;
    int health;
    int level;
    int playerID;

public:
    vector<string> inventory;
    Character(string name, string element, int playerID);
    Character(string name, string element, int health, int level, int playerID, vector<string> inventory);
    ~Character();
    void setName(string name);
    void setElement(string element);
    void setHealth(int health);
    void setLevel(int level);
    void setPlayerID(int playerID);
    string getName();
    string getElement();
    int getHealth();
    int getLevel();
    virtual void getAttacked(int damage);
    int getPlayerID();
    bool evade(); // chance is a 20% chance of evading damage
    void heal();
    void saveCharacter(); // saves character to savadata.txt based on character name
    void addItem(string item);
    void removeItem(string item);
    void fight(Character *enemy); // fight function for the game
    vector<string> getInventory();
    string getInventory(int i);
    virtual void printCharacter();
};

Character::Character(string name, string element, int playerID)
{
    this->name = name;
    this->element = element;
    this->health = 100;
    this->level = 1;
    this->playerID = playerID;
}

Character::Character(string name, string element, int health, int level, int playerID, vector<string> inventory)
{
    this->name = name;
    this->element = element;
    this->health = health;
    this->level = level;
    this->inventory = inventory;
    this->playerID = playerID;
}

Character::~Character()
{
}

void Character::setName(string name)
{
    this->name = name;
}

void Character::setElement(string element)
{
    this->element = element;
}

void Character::setHealth(int health)
{
    this->health = health;
}

void Character::setLevel(int level)
{
    this->level = level;
}

void Character::setPlayerID(int playerID)
{
    this->playerID = playerID;
}

string Character::getName()
{
    return this->name;
}

int Character::getPlayerID()
{
    return this->playerID;
}

string Character::getElement()
{
    return this->element;
}

int Character::getHealth()
{
    return this->health;
}

int Character::getLevel()
{
    return this->level;
}

void Character::addItem(string item)
{
    this->inventory.push_back(item);
}

void Character::fight(Character *enemy)
{
    // deal damage to enemy from 10-30 + level
    enemy->getAttacked((rand() % 20 + 10) + this->level);
}

bool Character::evade()
{
    bool evaded = false;
    int chance = rand() % 5 + 1;
    if (chance > 2)
    {
        evaded = true;
        return evaded;
    }
    else
    {
        return evaded;
    }
}

void Character::removeItem(string item)
{
    for (int i = 0; i < this->inventory.size(); i++)
    {
        if (this->inventory[i] == item)
        {
            this->inventory.erase(this->inventory.begin() + i);
        }
    }
}

void Character::saveCharacter()
{
    // first check if character is already in the file and update values
    ifstream file;
    file.open("savedata.txt");
    string line;
    vector<string> lines;
    while (getline(file, line))
    {
        lines.push_back(line);
    }
    file.close();
    for (int i = 0; i < lines.size(); i++)
    {
        if (lines[i] == "NAME")
        {
            if (lines[i + 1] == this->name)
            {
                lines[i + 2] = this->element;
                lines[i + 3] = to_string(this->health);
                lines[i + 4] = to_string(this->level);
                lines[i + 5] = to_string(this->playerID);
                for (int j = 0; j < this->inventory.size(); j++)
                {
                    lines[i + 6 + j] = this->inventory[j];
                }
                ofstream file;
                file.open("savedata.txt");
                for (int k = 0; k < lines.size(); k++)
                {
                    file << lines[k] << endl;
                }
                file.close();
                return;
            }
        }
    }

    ofstream file2;
    file.open("savedata.txt", ios::app);
    file2 << "NAME" << endl;
    file2 << this->name << endl;
    file2 << this->element << endl;
    file2 << this->health << endl;
    file2 << this->level << endl;
    file2 << this->playerID << endl;
    for (int i = 0; i < this->inventory.size(); i++)
    {
        file2 << this->inventory[i] << endl;
    }
    file2 << " " << endl;
    file2.close();
}

vector<string> Character::getInventory()
{
    return this->inventory;
}
string Character::getInventory(int i)
{
    return this->inventory[i];
}

void Character::getAttacked(int damage)
{
    int oldHealth = this->health;
    this->health -= damage;
    if (this->health < 0)
    {
        this->health = 0;
    }
    cout << getName() << " took " << oldHealth - this->health << " damage!" << endl
         << endl;
}

void Character::heal()
{
    // add random health value from 10-25 + current level
    int healthAddition = rand() % 15 + 10;
    this->health += (healthAddition) + this->level;
    cout << getName() << " healed for " << (healthAddition) + this->level << " health!" << endl
         << endl;
}

void Character::printCharacter()
{

    cout << "Name: " << this->name << endl;
    cout << "Element: " << this->element << endl;
    cout << "Health: " << this->health << endl;
    cout << "Level: " << this->level << endl;
    cout << "Inventory: " << endl;
    // cout<<"Player ID: " << this->playerID << endl;
    if (this->inventory.size() == 0)
    {
        cout << "Empty" << endl;
    }
    for (int i = 0; i < this->inventory.size(); i++)
    {
        cout << this->inventory[i] << endl;
    }
    cout << endl;
}

#endif