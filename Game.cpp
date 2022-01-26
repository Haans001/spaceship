#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Laser.h"
#include "ResourceLoader.h"
#include "Background.h"
#include "Meteoroid.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(this->width, this->height), "Space Ship!", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);

	this->background = new Background(this->width, this->height);
	this->meteorSpawner = new MeteorSpawner(8, 0.2f, 50.0f);
}


void Game::initPlayer()
{
	this->player = new Player(96,96, "ship");
}

void Game::reset()
{
	this->initPlayer();
	this->score = 0;
	this->meteorSpawner = new MeteorSpawner(8, 0.2f, 50.0f);
}

void Game::drawString(std::string s, float x, float y, sf::Color color, int fontSize, bool bCenter)
{

	sf::Text text(s, this->font, fontSize);
	float nWidth = text.getLocalBounds().width;

	if (bCenter) {
		text.setPosition((this->width / 2 - nWidth / 2), y);
	}
	else {
		text.setPosition(x, y);
	}
	text.setFillColor(color);
	this->window->draw(text);
}

void Game::run() {
	sf::Clock clock;
	while (this->window->isOpen()) 
	{
		sf::Time elapsed = clock.restart();
		this->update(elapsed.asSeconds() * 10);
		this->render();
	}
}

void Game::update(float fElapsed) {
	sf::Event event;

	

	while (this->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->window->close();

		if (!player->bDestroyed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player->dirX = -1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player->dirX = 1;

			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D)
					player->dirX = 0;

				if (event.key.code == sf::Keyboard::Space) {
					player->shoot();
				}
			}
		}
		else {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) this->reset();
		}




	}

	if (!this->player->bDestroyed) {
		this->background->update(fElapsed);
		this->meteorSpawner->update(fElapsed);
		this->player->update(fElapsed);


		// collision between lasers and meteors
		std::vector<Laser*> lasers = this->player->lasers;
		std::vector<Meteoroid*> meteors = this->meteorSpawner->meteors;

		for (auto& meteor : meteors) {
			for (auto& laser : lasers) {
				if (meteor->colideWith((GameEntity*)(laser)))
				{
					meteor->bDestroyed = true;
					laser->bDestroyed = true;
					this->score++;

				}
			}

			if (meteor->colideWith(this->player)) {
				this->player->bDestroyed = true;	
			}
		}

	}

}
void Game::render()
{
	this->window->clear();
	this->background->render(*this->window);
	if (!this->player->bDestroyed) {
		this->meteorSpawner->render(*this->window);
		this->player->render(*this->window);
		this->drawString("Score : " + std::to_string(this->score), 5, 0, sf::Color::Red, 50);
		
	}
	else {
		this->drawString("YOU DIED!", 0, 250, sf::Color::Red, 70, true);
		this->drawString("Your score : " + std::to_string(this->score), 0, 330, sf::Color::Red, 70, true);
		this->drawString("Press Enter to restart" , 0, 410, sf::Color::Red, 70, true);
	}
	this->window->display();
}





Game::Game(int width, int height)
{
	this->width = width;
	this->height = height;
	this->initWindow();
	this->initPlayer();

	if (!font.loadFromFile("textures/Khronopix.ttf")) {
		std::cout << "Error loading font... " << std::endl;
	}
}

Game::~Game()
{
	delete this->window;
}
