#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "GameEntity.h"

class Game;
class Laser;

class Player : public GameEntity
{
private:

public:
	int dirX = 0;
	std::vector<Laser*> lasers;

	float fShootTimer = 0.0f;
	float fShootInterval = 0.5f;
	bool canShoot = true;

	float fVel = 50.0f;

	Player(int nWidth, int nHeight, std::string textureName);
	~Player();

	void shoot();
	void update(float fElapsed) override;
	void render(sf::RenderTarget& target) override;
};