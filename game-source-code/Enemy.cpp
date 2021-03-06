#include "Enemy.h"

int Enemy::_NumberEnemiesAlive = 0;
int Enemy::_TotalNumberOfEnemies = 0;
int Enemy::_NumberEnemiesKilled = 0;

Enemy::Enemy()
    : MovingShootingEntity(40.0, 80.0, 1, 255,255,255, "voldy.png")
    , _radius{ 0.0 }
    , _entityType{ EntityList::EnemyEntity }
    , _time{ 0.0 }
	, _tolerance{1}
{
    _randomAngle = rand() % 360;
    _theta = _randomAngle * M_PI / 180;
    _NumberEnemiesAlive++;
    _TotalNumberOfEnemies++;
	_scaleX=1.0;
	_scaleY=1.0;
    _spawnBullet = rand() % 5 + 1;
}

Enemy::~Enemy()
{
    _NumberEnemiesAlive--;
    _NumberEnemiesKilled++;
    if(_NumberEnemiesAlive < 0) {
	_NumberEnemiesAlive = 0;
    }
}

void Enemy::calculatePosition(const bool& direction, float factor)
{
    floatVector movement;
    _radius += factor;
	getPosition();
	return;
}

void Enemy::Update(int direction, float timeElapsed)
{
    floatVector movement;
    float factor = _speed * timeElapsed;
    _time += timeElapsed;
	
    if(_radius >= _MAX_RADIUS) {
	_randomAngle = rand() % 360;
	_theta = _randomAngle * M_PI / 180;
	_radius = 0.0;
	_scaleX=1.0;
	_scaleY=1.0;
    }

    if(_time > (_spawnBullet - _tolerance) && _time < (_spawnBullet + _tolerance)) {
	createBullets();
	_spawnBullet = fmod(rand(), _time) + 5;
    }

   calculatePosition(true, factor);
	_scaleX+=0.0009*factor;
	_scaleY+=0.0009*factor;
}

float Enemy::getAngle()
{
    return _theta;
}

floatVector Enemy::getPosition()
{
    floatVector currentPosition;
    currentPosition.push_back(_radius * cosf(_theta) + _x_center);
    currentPosition.push_back(_radius * sinf(_theta) + _y_center);
    return currentPosition;
}

float Enemy::getRadius()
{
    return _radius;
}

EntityList Enemy::getEntityType()
{
    return _entityType;
}

int Enemy::getNumberofEnemiesAlive()
{
    return _NumberEnemiesAlive;
}

int Enemy::getTotalNumberofEnemies()
{
    return _TotalNumberOfEnemies;
}

int Enemy::getNumberofEnemiesKilled()
{
    return _NumberEnemiesKilled;
}

void Enemy::ResetEnemies()
{
    _TotalNumberOfEnemies = 0;
    _NumberEnemiesKilled = 0;
    _NumberEnemiesAlive = 0;
}

void Enemy::createBullets()
{
    std::shared_ptr<EnemyBullet> bulletPtr{ new EnemyBullet(_theta, _radius, _x_center, _y_center) };
    movingEntity::entityList.push_back(bulletPtr);
    return;
}