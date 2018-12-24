#pragma once
#include <SFML\Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Animal.h"
#include "Wolf.h"
#include "SheWolf.h"
#include "Hare.h"
#include "Grid.h"
namespace Engine {
	class GameState :public State
	{
	public:
		GameState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	private:
		GameDataRef _data;
		
		sf::Sprite _background;
		Grid *grid;
		Grid *chaseGrid;
		std::vector<GridCell*> collisionCells;
		Wolf *wolf;
		SheWolf *sheWolf;
		Hare *hare;
	};
}