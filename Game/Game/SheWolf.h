#pragma once
#include "Animal.h"
#include "Grid.h"
#include <stdlib.h>    
#include <time.h>  

namespace Engine
{
	class SheWolf : public Animal
	{
	public:
		SheWolf(GameDataRef data);
		virtual void Move(float dt, Grid *chaseGrid, std::vector<GridCell*> collisionCells, std::vector<sf::Sprite> *hare);
		void ChaseHare(float dt, Grid *chaseGrid, std::vector<sf::Sprite> *hare);
		void AvoidColliders(float dt, std::vector<GridCell*> collisionCells);
		void AvoidBoundaryAndMoveRandomly(float dt);
		sf::Vector2f normalize(const sf::Vector2f& source);
		void Spawn(int x, int y);
		void SpawnRandom();
		~SheWolf();
	private:


	};

}
