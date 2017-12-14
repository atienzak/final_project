/**
  Keith Atienza - Defend the Den
  Date Finished: December 14, 2017
  Submitted as the final project for PIC 10C, Fall 2017
*/

#include "shooter.h"

Shooter::Shooter(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent),
    bullets({}),
    bulletTimeDelay(49),//,
    shooting(false)
{
    setPixmap(QPixmap(":/images/Cute Brown Monster-256x256 (1)").scaled(133,130));

}

Shooter::Shooter(const Shooter &other) : bullets(other.bullets), bulletTimeDelay(other.bulletTimeDelay), shooting(other.shooting)
{
    setPixmap(QPixmap(":/images/Cute Brown Monster-256x256 (1)").scaled(133,130));
}

Shooter& Shooter::operator=(Shooter rhs)
{
    this->swap(rhs);
    return *this;
}

Shooter::~Shooter()
{
    for (size_t i = 0, n = bullets.size(); i < n; i++) // bullets might have already been deleted
    {
        if (bullets[i] != nullptr)
            delete bullets[i];
    }
}

//for copy-swap functionality
void Shooter::swap(Shooter &rhs)
{
    std::swap(bullets, rhs.bullets);
    std::swap(bulletTimeDelay, rhs.bulletTimeDelay);
    std::swap(shooting, rhs.shooting);
}

/**
 * @brief Shooter::spawnBullet makes another bullet by the shooters
 * @param shoot checks if the shooter is in the state of shooting
 */

void Shooter::spawnBullet(bool shoot)
{
    if (shoot)
    {
        bulletTimeDelay++;
        if (bulletTimeDelay % 50 != 0)
        {
            return;
        }

        bullets.push_back(new Bullet);
        bullets[bullets.size() - 1]->setParentItem(this); // have to parent these items
        bulletTimeDelay = 0;
    }
}

/**
 * @brief Shooter::advance called by the scene to activate the shooters
 * @param phase 0 to prepare for scene change, 1 to activate
 */
void Shooter::advance(int phase)
{
    if (!phase)
        return;

    spawnBullet(shooting);
}

/**
 * @brief Shooter::isShooting checks if shooter is already shooting
 * @return true if shooter is shooting, false otherwise
 */
bool Shooter::isShooting()
{
    return shooting;
}

/**
 * @brief Shooter::activate sets shooting to true, meaning it is currently shooting
 */
void Shooter::activate()
{
    shooting = true;
}

/**
 * @brief Shooter::deactivate sets shooting to false, to turn off shooters
 */
void Shooter::deactivate()
{
    shooting = false;
}

