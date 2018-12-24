#include "Hare.h"


namespace Engine
{
	Hare::Hare(GameDataRef data) : Animal(data)
	{

	}

	void Hare::Spawn(int x, int y)
	{
		sf::Sprite sprite(_data->assets.GetTexture("Hare Texture"));
		sprite.setPosition(x, y);
		animalSprites.push_back(sprite);
	}

	void Hare::SpawnRandom()
	{

	}


	Hare::~Hare()
	{
	}
}