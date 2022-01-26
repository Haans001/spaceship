#pragma once
#include <map>
#include <SFML/Graphics.hpp>

class ResourceLoader
{
public:

	static ResourceLoader& get() {
		static ResourceLoader self;
		return self;
	}

	ResourceLoader(ResourceLoader const&) = delete;
	void operator=(ResourceLoader const&) = delete;

	sf::Texture* GetTexture(std::string name) {
		return textures[name];
	}

	void LoadSprites();

private:
	ResourceLoader();
	~ResourceLoader();

	std::map<std::string, sf::Texture*> textures;;
};

