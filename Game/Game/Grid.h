#pragma once
#include<vector>
#include<SFML\Graphics.hpp>
#include"GridCell.h"
#include"Game.h"
#include "Collision.h"
#include <vector>
#include<iostream>
namespace Engine
{
	class Grid
	{
	public:
		Grid(GameDataRef data);
		void InitializeCells(unsigned int x, unsigned int y);
		void SetBoundaryCells(unsigned int x, unsigned int y);
		void DrawCells();
		std::vector<GridCell*> GetGridCells();
		void Insert(std::vector<sf::Sprite> wolf, std::vector<sf::Sprite> sheWolf, std::vector<sf::Sprite> hare, int resX, int resY, int rows);
		void ClearGrid();
		void WolfCollideWithHare(std::vector<sf::Sprite> *wolf, std::vector<sf::Sprite> *hare);
		void SheWolfCollideWithHare(std::vector<sf::Sprite> *sheWolf, std::vector<sf::Sprite> *hare);
		void WolfCollideWithSheWolf(std::vector<sf::Sprite> *wolf, std::vector<sf::Sprite> *sheWolf);
		void HareCollideWithHare(std::vector<sf::Sprite> *hare);
		std::vector<GridCell*> GetColliderCells();
		~Grid();
	private:
		GameDataRef _data;
		std::vector<GridCell*> cells;
	};
}

