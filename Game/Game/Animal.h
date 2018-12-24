#pragma once
#include <SFML\Graphics.hpp>
#include "Game.h"
#include <vector>
#include "Collision.h"

namespace Engine 
{
	class Animal
	{
	public:
		
		Animal(GameDataRef data);
		void DrawAnimals();
		void Move(float dt);
		 std::vector<sf::Sprite> &GetSprite() ;
		~Animal();
	protected:
		GameDataRef _data;
		std::vector<sf::Sprite> animalSprites;
		
	};
}



