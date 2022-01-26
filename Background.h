#pragma once
#include <SFML/Graphics.hpp>

class Background
{
private:

	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Texture	texture;

	int nWidth = 0;
	int nHeight = 0;

	float fVel = 25.0f;

public:
	Background(int nWidth, int nHeight);
	~Background();

	void update(float fElapsed);
	void render(sf::RenderTarget& target) ;
};

