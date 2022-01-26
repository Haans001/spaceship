#pragma once
#include <SFML/Graphics.hpp>
#include "GameEntity.h"

class Laser : public GameEntity
{

public:
	float fVel = 100.0f;

	Laser(float x, float y, int nWidth, int nHeight);
	~Laser();

	void update(float fElapsed) override;
	void render(sf::RenderTarget& target) override;
};

