#include "Meteoroid.h"
#include "SFML/System.hpp"
#include <iostream>

void Meteoroid::update(float fElapsed)
{
	this->rotation += this->fVel * fElapsed;
	this->rotation = std::fmod(this->rotation, 360);
	this->sprite.move(0, this->fVel * fElapsed);
}

void Meteoroid::render(sf::RenderTarget& target)
{
	if (this->bDestroyed) return;

	//sf::RectangleShape rect(sf::Vector2f(this->nWidth, this->nHeight));
	//rect.setOutlineColor(sf::Color::Red);
	//rect.setPosition(this->getX(), this->getY());
	//rect.setFillColor(sf::Color::Transparent);
	//rect.setOutlineThickness(3);
	//target.draw(rect);
	sf::Transform transform;
	/*transform.rotate(this->rotation, this->getX() + nWidth / 2, this->getY() + nHeight / 2);*/
	target.draw(this->sprite, transform);
}

Meteoroid::Meteoroid(float x, float y, int nWidth, int nHeight, float fVel) : GameEntity("meteoroid", nWidth, nHeight, "meteor")
{
	this->fVel = fVel;
	this->sprite.setPosition(sf::Vector2f(x, y));
}

Meteoroid::~Meteoroid()
{
}
