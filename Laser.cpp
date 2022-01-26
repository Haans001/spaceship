#include <iostream>
#include "Laser.h"
#include "ResourceLoader.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


Laser::Laser(float fPlayerX, float fPlayerY, int nWidth, int nHeight) : GameEntity("laser", 24, 36, "laser")
{
	this->sprite.setPosition(fPlayerX - (nWidth / 2), fPlayerY - nHeight);
}

Laser::~Laser()
{
}

void Laser::update(float fElapsed)
{
	this->sprite.move(0, -1 * this->fVel * fElapsed);
}

void Laser::render(sf::RenderTarget& target)
{
	if (this->bDestroyed) return;
	target.draw(this->sprite);
}
