#include "Character.h"
#include "Firebender.h"
#include "Waterbender.h"
#include "Earthbender.h"
#include "Airbender.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void loadSavedCharacters(vector<Character> &characters)
{
    ifstream file;
    file.open("savedata.txt");
    string line;
    while (getline(file, line))
    {
        if (line == "NAME")
        {
            string name;
            string element;
            int health;
            int level;
            vector<string> inventory;
            getline(file, name);
            getline(file, element);
            getline(file, line);
            health = stoi(line);
            getline(file, line);
            level = stoi(line);
            getline(file, line);
            int playerID = stoi(line);
            while (getline(file, line) && line != " ")
            {
                inventory.push_back(line);
            }
            if (element == "Fire")
            {
                Firebender firebender(name, health, level, playerID, inventory);
                characters.push_back(firebender);
            }
            else if (element == "Water")
            {
                Waterbender waterbender(name, health, level, playerID, inventory);
                characters.push_back(waterbender);
            }
            else if (element == "Earth")
            {
                Earthbender earthbender(name, health, level, playerID, inventory);
                characters.push_back(earthbender);
            }
            else if (element == "Air")
            {
                Airbender airbender(name, health, level, playerID, inventory);
                characters.push_back(airbender);
            }
            else
            {
                Character character(name, element, health, level, playerID, inventory);
                characters.push_back(character);
            }
        }
    }
    file.close();
}

void createNewCharacter(int playerNum, vector<Character> &currentCharacters)
{
    string name;
    string element;
    int health;
    int level;
    bool bad = true;
    vector<string> inventory;
    while (bad)
    {
        cout << "Enter name: ";
        cin >> name;
        // cout << flush;
        cout << "Enter element: ";
        cin >> element;
        cout << endl;
        if (element == "Fire")
        {
            Firebender firebender(name, playerNum);
            // firebender.printCharacter();
            firebender.saveCharacter();
            currentCharacters.push_back(firebender);
            bad = false;
        }
        else if (element == "Water")
        {
            Waterbender waterbender(name, playerNum);
            // waterbender.printCharacter();
            waterbender.saveCharacter();
            currentCharacters.push_back(waterbender);
            bad = false;
        }
        else if (element == "Earth")
        {
            Earthbender earthbender(name, playerNum);
            // earthbender.printCharacter();
            earthbender.saveCharacter();
            currentCharacters.push_back(earthbender);
            bad = false;
        }
        else if (element == "Air")
        {
            Airbender airbender(name, playerNum);
            // airbender.printCharacter();
            airbender.saveCharacter();
            currentCharacters.push_back(airbender);
            bad = false;
        }
        else
        {
            cout << "Invalid element!" << endl;
        }
    }
}

void loadCharacter(vector<Character> &characters, int playerNum, vector<Character> &currentCharacters)
{
    cout << "Saved Characters: " << endl;
    for (int i = 0; i < characters.size(); i++)
    {
        cout << i + 1 << ". " << characters[i].getName() << ", " << characters[i].getElement() << endl;
    }
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    bool found = false;
    for (int i = 0; i < characters.size(); i++)
    {
        if (choice - 1 == i)
        {
            found = true;
            characters[i].setPlayerID(playerNum);
            currentCharacters.push_back(characters[i]);
        }
    }
    if (!found)
    {
        cout << "Invalid choice!" << endl;
    }
}

void showMainMenu(vector<Character> &characters, bool &running, vector<Character> &currentCharacters)
{
    cout << "Welcome to the Avatar 1v1 RPG!" << endl
         << "The goal of the game is to defeat your opponent by reducing their health to 0." << endl
         << "You can do this by attacking them, healing yourself, or evading their attacks." << endl
         << "Each character has a different amount of health, attack damage, and healing power." << endl
         << "Each character has an element they bend that changes how they play, such as giving them more health or dealing more damage" << endl
         << "You deal more damage and heal more health based on your level, which increases everytime your character wins a battle." << endl
         << "There are 4 elements: Water, Earth, Fire, and Air" << endl
         << "Waterbenders have can heal more, have lower Health, and are strong against Fire, but weak against Earth." << endl
         << "Earthbenders have very high defense and take less damage than usual, and are weak to Air but strong to Fire" << endl
         << "Firebenders have more attack damage and are strong against Air, but weak against Water." << endl
         << "Airbenders have very high speed and can evade attacks, and are weak to Earth but strong to Water" << endl
         << "Characters can be named and have their element chosen. They can also be saved and loaded to return to at a later time." << endl
         << "Enjoy the game and destroy your advisaries!" << endl
         << endl;
    cout << "Player 1: " << endl;
    cout << "1. Create new character" << endl;
    cout << "2. Load character" << endl;
    cout << "3. Exit" << endl
         << endl;
    ;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << endl
             << "Creating new character..." << endl;
        createNewCharacter(1, currentCharacters);
        break;
    case 2:
        cout << endl
             << "Loading character..." << endl;
        loadCharacter(characters, 1, currentCharacters);
        break;
    case 3:
        cout << "Exiting..." << endl;
        running = false;
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }
    if (running)
    {
        cout << endl;
        cout << "Player 2: " << endl;
        cout << "1. Create new character" << endl;
        cout << "2. Load character" << endl;
        cout << "3. Exit" << endl
             << endl;
        cout << "Enter your choice: ";
        // int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << endl
                 << "Creating new character..." << endl;
            createNewCharacter(2, currentCharacters);
            break;
        case 2:
            cout << endl
                 << "Loading character..." << endl;
            loadCharacter(characters, 2, currentCharacters);
            break;
        case 3:
            cout << "Exiting..." << endl;
            running = false;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
}

void gameOver(vector<Character> &currentCharacters, bool &running, bool &fighting)
{

    if (currentCharacters[0].getHealth() <= 0)
    {
        cout << currentCharacters[0].getName() << " has been defeated!" << endl;
        cout << currentCharacters[1].getName() << " wins!" << endl;
        currentCharacters[1].setLevel(currentCharacters[1].getLevel() + 1);
    }
    else
    {
        cout << currentCharacters[1].getName() << " has been defeated!" << endl;
        cout << currentCharacters[0].getName() << " wins!" << endl;
        currentCharacters[0].setLevel(currentCharacters[0].getLevel() + 1);
    }
    cout << "Exiting..." << endl;
    currentCharacters[0].setHealth(100);
    // currentCharacters[0].setLevel(1);
    currentCharacters[1].setHealth(100);
    // currentCharacters[1].setLevel(1);
    currentCharacters[0].saveCharacter();
    currentCharacters[1].saveCharacter();
    running = false;
    fighting = false;
    exit(0);
}

void fight(vector<Character> &currentCharacters, bool &running)
{
    bool fighting = true;
    while (fighting)
    {
        for (int i = 0; i < currentCharacters.size(); i++)
        {
            cout << "Player " << i + 1 << "'s turn!" << endl;
            cout << "1. Attack" << endl;
            cout << "2. Heal" << endl;
            cout << "3. Save & Quit" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            cout << endl;
            switch (choice)
            {
            case 1:
                if (i == 0)
                {
                    cout << currentCharacters[i].getName() << " attacked " << currentCharacters[i + 1].getName() << endl;
                    currentCharacters[i].fight(&currentCharacters[i + 1]);
                    if (currentCharacters[i + 1].getHealth() <= 0)
                    {
                        gameOver(currentCharacters, running, fighting);
                    }
                }
                else
                {
                    cout << currentCharacters[i].getName() << " attacked " << currentCharacters[i - 1].getName() << endl;
                    currentCharacters[i].fight(&currentCharacters[i - 1]);
                    if (currentCharacters[i + 1].getHealth() <= 0)
                    {
                        gameOver(currentCharacters, running, fighting);
                    }
                }
                break;
            case 2:
                currentCharacters[i].heal();
                break;
            case 3:
                if (i == 0)
                {
                    currentCharacters[i].saveCharacter();
                    currentCharacters[i + 1].saveCharacter();
                }
                else
                {
                    currentCharacters[i].saveCharacter();
                    currentCharacters[i - 1].saveCharacter();
                }

                fighting = false;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }
        }
        cout << endl;
        cout << "----------------------------------------" << endl;
        cout << "Summary of characters: " << endl;
        for (int i = 0; i < currentCharacters.size(); i++)
        {
            currentCharacters[i].printCharacter();
        }
        cout << "----------------------------------------" << endl;
    }
    running = false;
}

void startGame(vector<Character> &currentCharacters, bool &running)
{
    cout << endl
         << endl;
    for (int i = 0; i < currentCharacters.size(); i++)
    {
        cout << "Player " << i + 1 << "'s character: " << endl;
        currentCharacters[i].printCharacter();
    }
    cout << "----------------------------------------" << endl
         << "Fight!" << endl;
    fight(currentCharacters, running);
}

int main()
{

    vector<Character> characters;
    vector<Character> currentCharacters;
    loadSavedCharacters(characters);

    bool running = true;
    while (running)
    {
        showMainMenu(characters, running, currentCharacters);
        startGame(currentCharacters, running);
    }

    return 0;
}