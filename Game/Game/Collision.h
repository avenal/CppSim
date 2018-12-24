#pragma once
#include <SFML\Graphics.hpp>
#include "DEFINITIONS.h"
#include "GridCell.h"
namespace Engine
{
	class Collision
	{
	public:
		Collision();
		bool CheckCollision(sf::Sprite *sprite1, sf::Sprite *sprite2);
		int CheckBorderCollision(sf::Sprite sprite);
		int CheckTerrainCollision(sf::Sprite *sprite, std::vector<GridCell*> collider);
		~Collision();
	};
}
