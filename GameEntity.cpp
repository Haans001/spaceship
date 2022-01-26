#include "GameEntity.h"
#include "ResourceLoader.h"
#include <SFML/System.hpp>
#include <iostream>


bool GameEntity::colideWith(GameEntity* otherEntity)
{
	sf::FloatRect bounds1 = this->sprite.getGlobalBounds();
	sf::FloatRect bounds2 = otherEntity->sprite.getGlobalBounds();

	return bounds1.intersects(bounds2);
}

GameEntity::GameEntity(std::string sName, int nWidth, int nHeight, std::string textureName)
{
	this->sName = sName;
	this->nWidth = nWidth;
	this->nHeight = nHeight;

	this->texture = *ResourceLoader::get().GetTexture(textureName);
	this->sprite.setTexture(this->texture);

	float scaleX = this->nWidth / texture.getSize().x;
	float scaleY = this->nHeight / texture.getSize().y;

	this->sprite.setScale(scaleX, scaleY);

}

GameEntity::~GameEntity()
{
}
