#pragma once
#include <SFML/Graphics.hpp>

class GameEntity
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;

public:
	std::string sName;
	int nWidth = 0;
	int nHeight = 0;
	bool bDestroyed = false;


	virtual void update(float fElapsed) {}
	virtual void render(sf::RenderTarget& target) {}

	float getX() {
		return this->sprite.getPosition().x;
	}

	float getY() {
		return this->sprite.getPosition().y;
	}

	bool colideWith(GameEntity* otherEntity);

	GameEntity(std::string sName, int nWidth, int nHeight, std::string textureName);
	~GameEntity();
};

