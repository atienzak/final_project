/**
  Keith Atienza - Defend the Den
  Date Finished: December 14, 2017
  Submitted as the final project for PIC 10C, Fall 2017
*/

#ifndef PLAYER_H
#define PLAYER_H

// this class will be used as an external variuable to hold the game's data

class Player
{
public:
    Player();
    void subtractLives();
    void addZombiesKilled();
    void addMoney(int m);
    void subtractMoney(int m);
    void increaseZombieSpeed();
    int getMoney() const;
    int getZombiesKilled() const;
    int getLives() const;
    int getzombieSpeed() const;

private:

    int lives;
    int zombiesKilled;
    int money;
    int zombieSpeed;


};

#endif // PLAYER_H
