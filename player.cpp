#include "player.h"

Player::Player() : lives(3), zombiesKilled(0), money(250), zombieSpeed(10)
{
}

void Player::subtractLives()
{
    if (lives != 0)
        lives--;
}

void Player::addZombiesKilled()
{
    zombiesKilled++;
}

void Player::addMoney(int m)
{
    money += m
            ; // adds 10 everytime a zombie is killed; costs 50 to build a shooter
}

void Player::subtractMoney()
{
    if (money >= 50)
        money -= 50; // costs 50 to build a shooter
}

void Player::increaseZombieSpeed()
{
    //these statements ensure that zombie's speed only increases once per interval of zombies killed
    if (zombiesKilled >= 10 && zombiesKilled < 20 && zombieSpeed == 10)
        zombieSpeed = 15;
    else if (zombiesKilled >= 20 && zombiesKilled < 30 && zombieSpeed == 15)
        zombieSpeed = 20;
    else if (zombiesKilled >= 30 && zombiesKilled < 40 && zombieSpeed == 20)
        zombieSpeed = 25;
    else if (zombiesKilled >= 40 && zombiesKilled < 50 && zombieSpeed == 25)
        zombieSpeed = 30;
    else if (zombiesKilled >= 50 && zombiesKilled < 60 && zombieSpeed == 30)
        zombieSpeed = 35;
    else if (zombiesKilled >= 60 && zombiesKilled < 70 && zombieSpeed == 35)
        zombieSpeed = 40;
    else if (zombiesKilled >= 70 && zombiesKilled < 80 && zombieSpeed == 40)
        zombieSpeed = 45;
    else if (zombiesKilled >= 80 && zombiesKilled < 90 && zombieSpeed == 45)
        zombieSpeed = 50;
    else if (zombiesKilled >= 90 && zombiesKilled < 100 && zombieSpeed == 50)
        zombieSpeed = 55;

}

int Player::getMoney() const
{
    return money;
}

int Player::getZombiesKilled() const
{
    return zombiesKilled;
}

int Player::getLives() const
{
    return lives;
}

int Player::getzombieSpeed() const
{
    return zombieSpeed;
}




