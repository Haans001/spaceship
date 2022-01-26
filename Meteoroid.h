#pragma once
#include "GameEntity.h"

class Meteoroid : public GameEntity
{
private:
	float fVel = 0.0f;
	float rotation = 0.0f;
public:

	Meteoroid(float x, float y, int nWidth, int nHeight, float fVel);
	~Meteoroid();

	void update(float fElapsed) override;
	void render(sf::RenderTarget& target) override;
};

