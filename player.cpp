#include "player.h"

Player::Player() : lives(3), zombiesKilled(0), money(100)
{
}

void Player::subtractLives()
{
    lives--;
}

void Player::addZombiesKilled()
{
    zombiesKilled++;
}

void Player::addMoney()
{
    money += 25; // adds 25 everytime a zombie is killed; costs 50 to build a shooter
}

void Player::subtractMoney()
{
    if (money >= 50)
        money -= 50; // costs 50 to build a shooter
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




