#include "GameState.h"
#include <sstream>
#include <iostream>
#include "DEFINITIONS.h"

namespace Engine {
	GameState::GameState(GameDataRef data) :_data(data)
	{

	}
	void GameState::Init()
	{
		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		this->_data->assets.LoadTexture("Wolf Texture", WOLF_FILEPATH);
		
		this->_data->assets.LoadTexture("She Wolf Texture", SHE_WOLF_FILEPATH);
		
		this->_data->assets.LoadTexture("Hare Texture", HARE_FILEPATH);
		
		this->_data->assets.LoadTexture("Grass Texture", GRASS_FILEPATH);
		this->_data->assets.LoadTexture("Brick Texture", BRICK_FILEPATH);
		grid = new Grid(_data);
		grid->InitializeCells(20,25);
		grid->SetBoundaryCells(20, 25);
		chaseGrid = new Grid(_data);
		chaseGrid->InitializeCells(12, 16);
		wolf = new Wolf(_data);
		sheWolf = new SheWolf(_data);
		hare = new Hare(_data);
		grid->Insert(wolf->GetSprite(), sheWolf->GetSprite(), hare->GetSprite(),32,32,20);
		chaseGrid->Insert(wolf->GetSprite(), sheWolf->GetSprite(), hare->GetSprite(), 50, 50, 12);
		collisionCells = grid->GetColliderCells();
	}
	void GameState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
			{
				wolf->Spawn(sf::Mouse::getPosition(_data->window).x, sf::Mouse::getPosition(_data->window).y);
			}
			else if (this->_data->input.IsSpriteClicked(_background, sf::Keyboard::A, _data->window))
			{
				sheWolf->Spawn(sf::Mouse::getPosition(_data->window).x, sf::Mouse::getPosition(_data->window).y);
			}
			else if (this->_data->input.IsSpriteClicked(_background, sf::Mouse::Right, _data->window))
			{
				hare->Spawn(sf::Mouse::getPosition(_data->window).x, sf::Mouse::getPosition(_data->window).y);
			}
			for (int i = 0; i < grid->GetGridCells().size(); i++)
			{
				
				if (this->_data->input.IsSpriteClicked(grid->GetGridCells().at(i)->GetCellSprite(), sf::Keyboard::S, _data->window))
				{
					grid->GetGridCells().at(i)->ChangeTextureToBrick();
				}
				else if (this->_data->input.IsSpriteClicked(grid->GetGridCells().at(i)->GetCellSprite(), sf::Keyboard::D, _data->window))
				{
					grid->GetGridCells().at(i)->ChangeTextureToGrass();
				}
				collisionCells.clear();
			    collisionCells = grid->GetColliderCells();
			}
		}
	}
	void GameState::Update(float dt)
	{
	
		wolf->Move(dt, chaseGrid, collisionCells, &sheWolf->GetSprite() ,&hare->GetSprite());
		sheWolf->Move(dt, chaseGrid, collisionCells, &hare->GetSprite());
		hare->Move(dt);
		grid->WolfCollideWithHare(&wolf->GetSprite(),&hare->GetSprite());
		grid->ClearGrid();
		chaseGrid->ClearGrid();
		grid->Insert(wolf->GetSprite(), sheWolf->GetSprite(), hare->GetSprite(), 32, 32, 20);
		chaseGrid->Insert(wolf->GetSprite(), sheWolf->GetSprite(), hare->GetSprite(), 100, 100, 6);
		grid->SheWolfCollideWithHare(&sheWolf->GetSprite(), &hare->GetSprite());
		grid->ClearGrid();
		chaseGrid->ClearGrid();
		grid->Insert(wolf->GetSprite(), sheWolf->GetSprite(), hare->GetSprite(), 32, 32, 20);
		chaseGrid->Insert(wolf->GetSprite(), sheWolf->GetSprite(), hare->GetSprite(), 100, 100, 6);
		grid->WolfCollideWithSheWolf(&wolf->GetSprite(), &sheWolf->GetSprite());
		grid->HareCollideWithHare(&hare->GetSprite());
		grid->ClearGrid();
		chaseGrid->ClearGrid();
		grid->Insert(wolf->GetSprite(), sheWolf->GetSprite(), hare->GetSprite(), 32, 32, 20);
		chaseGrid->Insert(wolf->GetSprite(), sheWolf->GetSprite(), hare->GetSprite(), 100, 100, 6);
		
	}	
	void GameState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);
		this->_data->window.draw(this->_background);
		grid->DrawCells();
		wolf->DrawAnimals();
		sheWolf->DrawAnimals();
		hare->DrawAnimals();
		this->_data->window.display();
	}
}
/*
TODO: spatial grid for collision optimalisation, ai
*/