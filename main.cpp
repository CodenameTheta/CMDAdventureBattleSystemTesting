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
};

class player {
public:
    int playerHealth = 100;
    int playerStamina = 120;
    int playerESP = 120;
    int playerESPAttackPoints = 60;
    int playerESPLoss = 60;
    int playerAttackPoints = 30;
    int playerStaminaLoss = 60;

};

enemy enemyObj;
player playerObj;
int Answer;

void playerStaminaCheckAndRecovery();
void chooseYourMethod();
void playerESPCheckAndRecovery();

int &postPlayerStamina = playerObj.playerStamina;
int &postPlayerMagic = playerObj.playerESP;

void battleFunctionPlayerPhysicalAttack() {
    postPlayerStamina = postPlayerStamina - playerObj.playerStaminaLoss;
    bool swordSlash = PlaySound(TEXT("swordSoundEffect.wav"), NULL, SND_ASYNC);
    cout << "you attack the enemy.." << endl;
    int enemyDamageTaken;
    enemyDamageTaken = (rand() % playerObj.playerAttackPoints);
    int enemyNewHealth;
    enemyNewHealth = enemyObj.Health - enemyDamageTaken;
    Sleep(2000);
    bool bloodSplatter = PlaySound(TEXT("bloodSplatterSound.wav"), NULL, SND_ASYNC);
    cout << "player inflicts " << enemyDamageTaken << " damage points on enemy.." << endl;
    Sleep(2000);
    cout << "the enemy is now at " << enemyNewHealth << " health points.." << endl;
    enemyObj.Health = enemyNewHealth;
    if(playerObj.playerHealth <= 0) {
        cout << "you don't have any more health, GAME OVER" << endl;
        abort();
    } else if(enemyObj.Health <= 0) {
        cout << "the enemy doesn't have any more health, YOU WIN" << endl;
        abort();
    } else {
        Sleep(2000);
    }

}

void battleFunctionEnemyPhysicalAttack() {
    int playerDamageTaken;
    bool swordSlashByEnemy = PlaySound(TEXT("swordSoundEffect.wav"), NULL, SND_ASYNC);
    cout << "the enemy swings it's sword at you.." << endl;
    playerDamageTaken = (rand() % enemyObj.attackPoints);
    int playerNewHealth;
    playerNewHealth = playerObj.playerHealth - playerDamageTaken;
    Sleep(2000);
    bool bloodSplatter2 = PlaySound(TEXT("bloodSplatterSound.wav"), NULL, SND_ASYNC);
    cout << "the enemy inflicts " << playerDamageTaken << " damage points to you" << endl;
    Sleep(2000);
    cout << "you are now at " << playerNewHealth << " health points" << endl;
    playerObj.playerHealth = playerNewHealth;
    if(playerObj.playerHealth <= 0) {
        cout << "you don't have any more health, GAME OVER" << endl;
        abort();
    } else if(enemyObj.Health <= 0) {
        cout << "the enemy doesn't have any more health, YOU WIN" << endl;
        abort();
    } else {
        Sleep(2000);
    }

}

void battleFunctionPlayerMagicAttack() {
    postPlayerMagic = postPlayerMagic - playerObj.playerESPLoss;
    bool magicAttack = PlaySound(TEXT("magicSoundEffect.wav"), NULL, SND_ASYNC);
    cout << "you strike the enemy with magic.." << endl;
    Sleep(4000);
    bool bloodSplatter3 = PlaySound(TEXT("bloodSplatterSound.wav"), NULL, SND_ASYNC);
    int enemyMagicDamageTaken;
    enemyMagicDamageTaken = (rand() % playerObj.playerESPAttackPoints);
    int enemyNewHealthAfterMagic;
    enemyNewHealthAfterMagic = enemyObj.Health - enemyMagicDamageTaken;
    cout << "the player inflicts " << enemyMagicDamageTaken << " damage points to the enemy.." << endl;
    Sleep(2000);
    cout << "the enemy is now at " << enemyNewHealthAfterMagic << " health points.." << endl;
    enemyObj.Health = enemyNewHealthAfterMagic;
    if(playerObj.playerHealth <= 0) {
        cout << "you don't have any more health, GAME OVER" << endl;
        abort();
    } else if(enemyObj.Health <= 0) {
        cout << "the enemy doesn't have any more health, YOU WIN" << endl;
        abort();
    } else {
        Sleep(2000);
    }

}

void battleFunctionEnemyMagicAttack() {
    bool magicAttack2 = PlaySound(TEXT("magicSoundEffect.wav"), NULL, SND_ASYNC);
    cout << "the enemy attacks you with magic.." << endl;
    Sleep(4000);
    int playerMagicDamageTaken;
    playerMagicDamageTaken = (rand() % enemyObj.ESPPoints);
    int playerNewHealthAfterMagic;
    playerNewHealthAfterMagic = playerObj.playerHealth - playerMagicDamageTaken;
    bool bloodSplatter4 = PlaySound(TEXT("bloodSplatterSound.wav"), NULL, SND_ASYNC);
    cout << "then enemy inflicts " << playerMagicDamageTaken << " damage points to you.." << endl;
    Sleep(2000);
    cout << "you are now at " << playerNewHealthAfterMagic << " health points" << endl;
    playerObj.playerHealth = playerNewHealthAfterMagic;
    if(playerObj.playerHealth <= 0) {
        cout << "you don't have any more health, GAME OVER" << endl;
        abort();
    } else if(enemyObj.Health <= 0) {
        cout << "the enemy doesn't have any more health, YOU WIN" << endl;
        abort();
    } else {
        Sleep(2000);
    }

}


void enemyAttackChoiceFunction() {
    int enemyAttackChoice;
    enemyAttackChoice = rand() % 2;
    if(enemyAttackChoice == 0) {
        battleFunctionEnemyPhysicalAttack();
    } else if (enemyAttackChoice == 1) {
        battleFunctionEnemyMagicAttack();
    } else {
        cout << "SOMETHING IS FUCKED WITH YOUR CODE!!!" << endl;
    }
}


void chooseYourMethod() {
    do {
        cout << "[1]: attack with your sword" << endl;
        cout << "[2]: attack with magic" << endl;
        cin >> Answer;
        if(Answer == 1) {
            playerStaminaCheckAndRecovery();
            battleFunctionPlayerPhysicalAttack();
            playerObj.playerESP = playerObj.playerESP + 60;
            enemyAttackChoiceFunction();
        } else if(Answer == 2)  {
            playerESPCheckAndRecovery();
            battleFunctionPlayerMagicAttack();
            playerObj.playerStamina = playerObj.playerStamina + 60;
            enemyAttackChoiceFunction();
        } else {
            cout << "command not understood.." << endl;
        }
    } while(playerObj.playerHealth > 0 || enemyObj.Health > 0);

}


void playerStaminaCheckAndRecovery() {
    if(playerObj.playerStamina <= 0) {
        cout << "you are out of stamina! you must catch your breath!" << endl;
        chooseYourMethod();
    } 
}


void playerESPCheckAndRecovery() {
    if(playerObj.playerESP <= 0) {
        cout << "you are out of magic! your need time to recover your ESP!" << endl;
        chooseYourMethod();
    } 
}


int main() {
    srand(static_cast<unsigned int>(time(0)));
    Sleep(2000);
    cout << "an enemy appears in your way, what will you do?.." << endl;
    Sleep(2000);
    chooseYourMethod();
    return 0;
}

