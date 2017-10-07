#ifndef ENTITYCREATOR_H
#define ENTITYCREATOR_H
#include "Clock.h"
#include "movingEntity.h"
#include "Enemy.h"
#include "EntityList.h"
#include "Asteroid.h"
#include "Satellite.h"
#include "Player.h"

class entityCreator
{
public:
	entityCreator(std::shared_ptr <Clock> gameClock, int maxEnemies, std::shared_ptr <Player> playerPtr);
	~entityCreator();
	void create();

private:
//Clock entityClock;
	std::shared_ptr <Clock> _entityClock;
	std::shared_ptr <Player> _playerPtr;
	float _timeEnemy;
	float _timeAsteroid;
	float _timeSatellite;
	float generateAsteroid;
	float generateEnemy;
	
	void createEnemies();
	void CreateAsteroid();
	void CreateSatellite();
	int MAXENEMIES;
};

#endif // ENTITYCREATOR_H
