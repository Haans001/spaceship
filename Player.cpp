#include <iostream>
#include <vector>
#include "Player.h"
#include "Game.h"
#include "Laser.h"
#include "ResourceLoader.h"

extern const int WIDTH;
extern const int HEIGHT;

void Player::shoot()
{
	if (!canShoot) return;
	float x = this->sprite.getPosition().x + (this->nWidth / 2);
	float y = this->sprite.getPosition().y;

	Laser* laser = new Laser(x, y, 24,32);
	this->lasers.push_back(laser);
	canShoot = false;
}

void Player::update(float fElapsed)
{
	float x = this->sprite.getPosition().x + this->dirX * this->fVel * fElapsed;
	float y = this->sprite.getPosition().y;

	this->fShootTimer += fElapsed;
	if ((fShootTimer / 10.0f) > fShootInterval) {
		canShoot = true;
		fShootTimer = 0.0f;
	}

	if (!(x < 0 || x > WIDTH - this->nWidth)) {
		sprite.setPosition(x, y);
	}

	int i = 0;
	for (auto& laser : this->lasers) {
		laser->update(fElapsed);
	}


	// usuwanie laserów które wylecia³y poza ekran
	auto it = this->lasers.begin();
	while (it != this->lasers.end())
	{
		Laser* laser = *it;
		if ((laser->getY() + laser->nHeight) < 0 || laser->bDestroyed) {
			it = this->lasers.erase(it);
		}
		else {
			it++;
		}
	}
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

	for (auto &laser : this->lasers) {
		laser->render(target);
	}
}

Player::Player(int nWidth, int nHeight, std::string textureName) : GameEntity("player", nWidth, nHeight, textureName) {
	this->sprite.setPosition((WIDTH / 2) - (nWidth / 2), HEIGHT - nHeight);
}

Player::~Player() 
{
	for (auto laser : this->lasers)
	{
		delete laser;
	}
	this->lasers.clear();
}