#include "Background.h"
#include "ResourceLoader.h"
#include <iostream>

Background::Background(int nWidth, int nHeight)
{
	this->nWidth = nWidth;
	this->nHeight = nHeight;

	this->texture = *ResourceLoader::get().GetTexture("background");
	this->sprite1.setTexture(this->texture);
	this->sprite2.setTexture(this->texture);


	float scaleX = (float)this->nWidth / this->texture.getSize().x;
	float scaleY = (float)this->nHeight / this->texture.getSize().y;

	std::cout << scaleX << std::endl;

	this->sprite1.setScale(scaleX, scaleY);
	this->sprite2.setScale(scaleX, scaleY);

	this->sprite2.setPosition(0, -nHeight);
}

Background::~Background()
{
}

void Background::update(float fElapsed)
{
	this->sprite1.move(0, this->fVel * fElapsed);
	this->sprite2.move(0, this->fVel * fElapsed);

	float sprite1Y = this->sprite1.getPosition().y;
	float sprite2Y = this->sprite2.getPosition().y;

	if (sprite1Y > this->nHeight) this->sprite1.setPosition(0, -this->nHeight);
	if (sprite2Y > this->nHeight) this->sprite2.setPosition(0, -this->nHeight);
}

void Background::render(sf::RenderTarget& target)
{
	target.draw(this->sprite1);
	target.draw(this->sprite2);
 
}
