#include "GridCell.h"

namespace Engine 
{
	GridCell::GridCell(int posX, int posY, bool isCollider, GameDataRef data) :_data(data)
	{
		gridCellSprite.setTexture(_data->assets.GetTexture("Grass Texture"));
		gridCellSprite.setPosition(posX * 32, posY * 32);
		this->isCollider = isCollider;
	}

	void GridCell::ClearCell()
	{
		wolfSprites.clear();
		sheWolfSprites.clear();
		hareSprites.clear();
	}

	void GridCell::ChangeTextureToBrick()
	{
		if (isCollider == false)
		{
		gridCellSprite.setTexture(_data->assets.GetTexture("Brick Texture"));
		}		
		isCollider = true;
	}

	void GridCell::ChangeTextureToGrass()
	{
		if (isCollider == true)
		{
			gridCellSprite.setTexture(_data->assets.GetTexture("Grass Texture"));
		}
		isCollider = false;
	}

	void GridCell::AddWolf(int index)
	{
		wolfSprites.push_back(index);
	}

	void GridCell::AddSheWolf(int index)
	{
		sheWolfSprites.push_back(index);
	}

	void GridCell::AddHare(int index)
	{
		hareSprites.push_back(index);
	}

	std::vector<int> GridCell::GetWolfSprites()
	{
		return wolfSprites;
	}

	std::vector<int> GridCell::GetSheWolfSprites()
	{
		return sheWolfSprites;
	}

	std::vector<int> GridCell::GetHareSprites()
	{
		return hareSprites;
	}

	bool GridCell::IsCollider()
	{
		return isCollider;
	}

	sf::Sprite GridCell::GetCellSprite()
	{
		return gridCellSprite;
	}

	GridCell::~GridCell()
	{
	}
	
}
