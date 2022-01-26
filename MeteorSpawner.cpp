#include "MeteorSpawner.h"
#include <random>
#include "Meteoroid.h"
#include <iostream>

extern const int WIDTH;
extern const int HEIGHT;

void MeteorSpawner::spawnMeteor()
{
	int column = std::rand() % this->nColumns;
	int meteorSize = WIDTH / this->nColumns;

	Meteoroid* meteor = new Meteoroid(column * meteorSize, -meteorSize, meteorSize, meteorSize, this->fMeteorVelocity);
	this->meteors.push_back(meteor);

}

MeteorSpawner::MeteorSpawner(int nColumns, float fInterval, float fInitialVelocity)
{
	this->nColumns = nColumns;
	this->fInterval = fInterval;
	this->fMeteorVelocity = fInitialVelocity;
}

MeteorSpawner::~MeteorSpawner()
{
	for (auto meteor : this->meteors)
	{
		delete meteor;
	}
	this->meteors.clear();
}

void MeteorSpawner::update(float fElapsed)
{
	fSpawnTimer += fElapsed;
	fVelocityIncreaseTimer += fElapsed;

	if ((fSpawnTimer / 10.0f) > fInterval) {
		spawnMeteor();
		fSpawnTimer = 0.0f;
	}

	if ((fVelocityIncreaseTimer / 10.0f) > 10.0f) {
		this->fMeteorVelocity += 5.0f;
		fVelocityIncreaseTimer = 0.0f;
	}

	for (auto& meteor : this->meteors)
	{
		meteor->update(fElapsed);
	}

	auto it = this->meteors.begin();
	while (it != this->meteors.end())
	{
		Meteoroid* meteor = *it;
		if ((meteor->getY()) > HEIGHT || meteor->bDestroyed) {
			it = this->meteors.erase(it);
		}
		else {
			it++;
		}
	}
}

void MeteorSpawner::render(sf::RenderTarget& target)
{
	for (auto& meteor : this->meteors)
	{
		meteor->render(target);
	}
}
