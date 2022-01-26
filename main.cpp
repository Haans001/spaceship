#include "Game.h"
#include "ResourceLoader.h"

extern const int WIDTH = 960;
extern const int HEIGHT = 960;

int main()
{
	std::srand(std::time(nullptr));

	ResourceLoader::get().LoadSprites();
	Game* game = new Game(WIDTH, HEIGHT);

	game->run();

	return 0;
}