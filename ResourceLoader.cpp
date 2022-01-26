#include "ResourceLoader.h"
#include <iostream>

void ResourceLoader::LoadSprites()
{
	auto load = [&](std::string sName, std::string sFileName) {
		sf::Texture* texture = new sf::Texture();
		texture->loadFromFile(sFileName);

		if (!texture->loadFromFile(sFileName)) {
			std::cout << "ERROR::LASER::Couldnt load texture from file" << std::endl;
		}

		textures[sName] = texture;
	};


	load("ship", "textures/ship_1.png");
	load("laser", "textures/laser.png");
	load("background", "textures/stars.png");
	load("meteor", "textures/meteor2.png");
}

ResourceLoader::~ResourceLoader()
{
}
ResourceLoader::ResourceLoader()
{
}