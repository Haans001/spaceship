#pragma once
#include <vector>
#include "Meteoroid.h"
#include <SFML/System.hpp>

class MeteorSpawner
{
public:
	std::vector<Meteoroid*> meteors;
	float fSpawnTimer = 0.0f;
	float fVelocityIncreaseTimer = 0.0f;
	float fInterval = 0.0f;
	float fMeteorVelocity = 20.0f;

	int nColumns;

	void spawnMeteor();

	MeteorSpawner(int nColumns, float fInterval, float fInitialVelocity);
	~MeteorSpawner();

	void update(float fElapsed) ;
	void render(sf::RenderTarget& target) ;
};

