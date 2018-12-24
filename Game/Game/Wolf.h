#pragma once
#include "Animal.h"
#include "Grid.h"
#include <stdlib.h>    
#include <time.h>  

namespace Engine
{
	class Wolf: public Animal
	{
	public:
		Wolf(GameDataRef data);
		void Spawn(int x, int y);
		virtual void Move(float dt, Grid *chaseGrid, std::vector<GridCell*> collisionCells, std::vector<sf::Sprite>* sheWolf, std::vector<sf::Sprite> *hare);
		void ChaseSheWolfOrHare(float dt, Grid *chaseGrid, std::vector<sf::Sprite>* sheWolf, std::vector<sf::Sprite> *hare);
		void AvoidColliders(float dt, std::vector<GridCell*> collisionCells);
		void AvoidBoundaryAndMoveRandomly(float dt);
		sf::Vector2f normalize(const sf::Vector2f& source);
		void SpawnRandom();
		~Wolf();
	private:

		
	};

}


