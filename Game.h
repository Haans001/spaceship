#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Background.h"
#include "Meteoroid.h"
#include "MeteorSpawner.h"
class Game
{
private:
	sf::RenderWindow* window;

	Player* player;
	Background* background;
	MeteorSpawner* meteorSpawner;
	sf::Font font;


	void initWindow();
	void update(float fElapsed);
	void render();
	void initPlayer();
	void reset();
	int score = 0;

	void drawString(std::string s, float x, float y, sf::Color color, int fontSize, bool bCenter = false);

public:
	int width;
	int height;


	//Constructors and Destructors
	Game(int width, int height);
	~Game();

	void run();

};
