#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "MMSystem.h"
#include <ctime>
using namespace std;

class enemy {
public:
    int attackPoints = 20;
    int ESPPoints = 60;
    int Health = 100;
    int stamina = 500;
};

class player {
public:
    int playerHealth = 499;
    int playerStamina = 699;
    int playerESP = 23;
    int playerAttackPoints = 15;
};

enemy enemyObj;
player playerObj;
string Answer;

void battleFunction() {
    
    getline(cin, Answer);
    if(Answer == "1" || "attack with sword") {
        bool swordSlash = PlaySound(TEXT("swordSoundEffect.wav"), NULL, SND_ASYNC);
        cout << "you attack the enemy" << endl;
        int enemyDamageTaken;
        enemyDamageTaken = (rand() % 30);
        int newHealth;
        newHealth = enemyObj.Health - enemyDamageTaken;
        Sleep(2000);
        bool bloodSplatter = PlaySound(TEXT("bloodSplatterSound.wav"), NULL, SND_ASYNC);
        cout << "player inflicts " << enemyDamageTaken << " damage points on enemy" << endl;
        Sleep(1000);
        cout << "the enemy is now at " << newHealth << " health points" << endl;
        if(playerObj.playerHealth <= 0){
            cout << "you don't have any more health, GAME OVER" << endl;
        } else if(newHealth <= 0){
            cout << "the enemy doesn't have any more health, YOU WIN" << endl;
        }
        enemyDamageTaken = 0;
        enemyObj.Health = newHealth;

        Sleep(2000);
        int playerDamageTaken;
        bool swordSlash2 = PlaySound(TEXT("swordSoundEffect.wav"), NULL, SND_ASYNC);
        cout << "The enemy now attacks you.. " << endl;
        playerDamageTaken = (rand() % 25);
        int playerNewHealth;
        playerNewHealth = playerObj.playerHealth - playerDamageTaken;
        Sleep(2000);
        bool bloodSplatter2 = PlaySound(TEXT("bloodSplatterSound.wav"), NULL, SND_ASYNC);
        cout << "enemy inflicts " << playerDamageTaken << " damage points to you" << endl;
        Sleep(1000);
        cout << "you are now at " << playerNewHealth << " health points" << endl;
        if(playerObj.playerHealth <= 0){
            cout << "you don't have any more health, GAME OVER" << endl;
        } else if(newHealth <= 0){
            cout << "the enemy doesn't have any more health, YOU WIN" << endl;
        }
            cout << "" << endl;
            Sleep(2000);

            
        if(playerObj.playerHealth <= 0){
            cout << "you don't have any more health, GAME OVER" << endl;
        } else if(newHealth <= 0){
            cout << "the enemy doesn't have any more health, YOU WIN" << endl;
        }

        cout << "" << endl;
        cout << "what will you do now?" << endl;
        cout << "" << endl;
        cout << "[1]: attack with sword" << endl;
        cout << "[2]: attack with magic" << endl;
        cout << "[3]: stand there and take it like a bitch" << endl;
            
        
    } else if (Answer == "2" || "attack with magic"){
        bool magicAttack = PlaySound(TEXT("magicSoundEffect.wav"), NULL, SND_ASYNC);
        cout << "you strike the enemy with magic.." << endl;
        Sleep(4000);
        bool bloodSplatter3 = PlaySound(TEXT("bloodSplatterSound.wav"), NULL, SND_ASYNC);
        int enemyMagicDamageTaken;
        enemyMagicDamageTaken = rand() % 50;
        int newHealth2;
        newHealth2 = enemyObj.Health - enemyMagicDamageTaken;
        cout << "the player inflicts " << enemyMagicDamageTaken << " damage point to enemy" << endl;
        Sleep(1000);
        cout << "the enemy is now at " << newHealth2 << " health points" << endl;
        if(playerObj.playerHealth <= 0){
            cout << "you don't have any more health, GAME OVER" << endl;
                
        } else if(newHealth2 <= 0){
            cout << "the enemy doesn't have any more health, YOU WIN" << endl;
                
        }

        enemyMagicDamageTaken = 0;
        enemyObj.Health = newHealth2;

        bool magicAttack2 = PlaySound(TEXT("magicSoundEffect.wav"), NULL, SND_ASYNC);
        cout << "enemy attacks you with magic.." << endl;
        Sleep(4000);
        int playerMagicDamageTaken;
        playerMagicDamageTaken = rand() % 45;
        int playerNewHealth2;
        playerNewHealth2 = playerObj.playerHealth - playerMagicDamageTaken;
        bool bloodSplatter4 = PlaySound(TEXT("bloodSplatterSound.wav"), NULL, SND_ASYNC);
        cout << "the enemy inflicts " << playerMagicDamageTaken << " damage points on you" << endl;
        Sleep(1000);
        cout << "you are now at " << playerObj.playerHealth << " health points" << endl;
        if(playerObj.playerHealth <= 0){
            cout << "you don't have any more health, GAME OVER" << endl;
        } else if(newHealth2 <= 0){
            cout << "the enemy doesn't have any more health, YOU WIN" << endl;
        }

        playerMagicDamageTaken = 0;
        playerObj.playerHealth = playerNewHealth2;

        cout << "what will you do now?" << endl;
        cout << "" << endl;
        cout << "[1]: attack with sword" << endl;
        cout << "[2]: attack with magic" << endl;
        cout << "[3]: stand there and take it like a bitch" << endl;
            

    } else {
        cout << "fix your code dipshit" << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    Sleep(2000);
    cout << "an enemy appears in your way, what will you do?" << endl;
    cout << "[1]: attack with sword" << endl;
    cout << "[2]: attack with magic" << endl;
    cout << "[3]: stand there and take it like a bitch" << endl;
    battleFunction(); 

    return 0;
}

    