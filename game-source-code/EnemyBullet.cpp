#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(float currentEnemyAngle, float currentEnemyRadius, float x_center, float y_center):
movingEntity(10.0,20.0, 1),
_bulletRadius{currentEnemyRadius},
_angle{currentEnemyAngle},
_x_center{x_center},
_y_center{y_center},
_entityType{EntityList::EnemyBulletEntity}
{
}

void EnemyBullet::Update(int direction, float timeElapsed)
{
	float factor = _speed*timeElapsed;
	calculatePosition(true, factor);
	
		if (getPosition()[0] > 4000)
		{
		setLives(0);
		}
}

floatVector EnemyBullet::getPosition()
{
	floatVector currentPosition;
	currentPosition.push_back(_bulletRadius*cosf(_angle) + _x_center);
	currentPosition.push_back(_bulletRadius*sinf(_angle) + _y_center);
	return currentPosition;
}

void EnemyBullet::calculatePosition(const bool &direction, float factor)
{
	floatVector movement;
	_bulletRadius+=factor;
	if (_bulletRadius>=_MAXIMUM_RADIUS)
	{
	setLives(0);
	}
	getPosition();
	return;
}

float EnemyBullet::getAngle()
{
	return _angle;
}

float EnemyBullet::getRadius()
{
	return _bulletRadius;
}

EntityList EnemyBullet::getEntityType()
{
	return _entityType;
}