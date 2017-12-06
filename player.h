#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
    Player();
    void subtractLives();
    void addZombiesKilled();
    void addMoney();
    void subtractMoney();
    int getMoney() const;
    int getZombiesKilled() const;
    int getLives() const;

private:

    int lives;
    int zombiesKilled;
    int money;


};

#endif // PLAYER_H
