#include "Grid.h"

namespace Engine
{
	Grid::Grid(GameDataRef data): _data(data)
	{

	}

	void Grid::InitializeCells(unsigned int x, unsigned int y)
	{
		for (unsigned int i = 0; i < x; i++) {
			for (unsigned int j = 0; j < y; j++) {
				GridCell* c = new GridCell(j, i, false, _data);
				cells.push_back(c);
			}
		}
	}

	void Grid::SetBoundaryCells(unsigned int x, unsigned int y)
	{
		for (int i = 0; i < cells.size(); i++)
		{
			if (i < y)
			{
				cells.at(i)->ChangeTextureToBrick();
			}
			else if (i > (y*(x-2)) && i < (x*y))
			{
				cells.at(i)->ChangeTextureToBrick();
			}
			else if (i % y == 0)
			{
				cells.at(i)->ChangeTextureToBrick();
			}
			else if (i % y == (y-1))
			{
				cells.at(i)->ChangeTextureToBrick();
			}
		}
	}

	void Grid::DrawCells()
	{
		for (unsigned int i = 0; i < cells.size(); i++)
		{
			_data->window.draw(cells.at(i)->GetCellSprite());
		}
	}

	std::vector<GridCell*> Grid::GetGridCells()
	{
		return cells;
	}

	void Grid::Insert(std::vector<sf::Sprite> wolf, std::vector<sf::Sprite> sheWolf, std::vector<sf::Sprite> hare, int resX, int resY, int rows)
	{
		Collision collision;
		for (int i = 0; i < wolf.size(); i++)
		{
			int indexes[4] = { 0, 0, 0, 0};
			int x = wolf.at(i).getPosition().x/resX;
			int y = wolf.at(i).getPosition().y / resY;
			indexes[0] = x * rows + y;
			if(cells.size() - 1 >= indexes[0])
			{
			cells.at(indexes[0])->AddWolf(i);
			}
			x = (wolf.at(i).getPosition().x +16)/ resX;
			y = wolf.at(i).getPosition().y / resY;
			indexes[1] = x * rows + y;
			if (indexes[1] != indexes[0] && cells.size() - 1 >= indexes[1]) {
				cells.at(indexes[1])->AddWolf(i);
			}
			x = (wolf.at(i).getPosition().x ) / resX;
			y = (wolf.at(i).getPosition().y + 16)/ resY;
			indexes[2] = x * rows + y;
			if (indexes[2] != indexes[0] && indexes[2] != indexes[1] && cells.size() - 1 >= indexes[2]) {
				cells.at(indexes[2])->AddWolf(i);
			}
			x = (wolf.at(i).getPosition().x + 16) / resX;
			y = (wolf.at(i).getPosition().y + 16) /	resY;
			indexes[3] = x * rows + y;
			if (indexes[3] != indexes[0] && indexes[3] != indexes[1] && indexes[3] != indexes[2] && cells.size() - 1 >= indexes[3]) {
				cells.at(indexes[3])->AddWolf(i);
			}
		//	delete[] indexes;
		}
		for (int i = 0; i < sheWolf.size(); i++)
		{
			int indexes[4] = { 0, 0, 0, 0 };
			int x = sheWolf.at(i).getPosition().x / resX;
			int y = sheWolf.at(i).getPosition().y / resY;
			indexes[0] = x * rows + y;
			if (cells.size() - 1 >= indexes[0])
			{
			cells.at(indexes[0])->AddSheWolf(i);
			}
			x = (sheWolf.at(i).getPosition().x + 16) / resX;
			y = sheWolf.at(i).getPosition().y / resY;
			indexes[1] = x * rows + y;
			if (indexes[1] != indexes[0] && cells.size() - 1 >= indexes[1]) {
				cells.at(indexes[1])->AddSheWolf(i);
			}
			x = (sheWolf.at(i).getPosition().x) / resX;
			y = (sheWolf.at(i).getPosition().y + 16) / resY;
			indexes[2] = x * rows + y;
			if (indexes[2] != indexes[0] && indexes[2] != indexes[1] && cells.size() - 1 >= indexes[2]) {
				cells.at(indexes[2])->AddSheWolf(i);
			}
			x = (sheWolf.at(i).getPosition().x + 16) / resX;
			y = (sheWolf.at(i).getPosition().y + 16) / resY;
			indexes[3] = x * rows + y;
			if (indexes[3] != indexes[0] && indexes[3] != indexes[1] && indexes[3] != indexes[2] && cells.size() - 1 >= indexes[3]) {
				cells.at(indexes[3])->AddSheWolf(i);
			}
			//	delete[] indexes;
		}
		for (int i = 0; i < hare.size(); i++)
		{
			int indexes[4] = { 0, 0, 0, 0 };
			int x = hare.at(i).getPosition().x / resX;
			int y = hare.at(i).getPosition().y / resY;
			indexes[0] = x * rows + y;
			if (cells.size() - 1 >= indexes[0])
			{
			cells.at(indexes[0])->AddHare(i);
			}
			x = (hare.at(i).getPosition().x + 16) / resX;
			y = hare.at(i).getPosition().y / resY;
			indexes[1] = x * rows + y;
			if (indexes[1] != indexes[0] && cells.size() - 1 >= indexes[1]) {
				cells.at(indexes[1])->AddHare(i);
			}
			x = (hare.at(i).getPosition().x) / resX;
			y = (hare.at(i).getPosition().y + 16) / resY;
			indexes[2] = x * rows + y;
			if (indexes[2] != indexes[0] && indexes[2] != indexes[1] && cells.size() - 1 >= indexes[2]) {
				cells.at(indexes[2])->AddHare(i);
			}
			x = (hare.at(i).getPosition().x + 16) / resX;
			y = (hare.at(i).getPosition().y + 16) / resY;
			indexes[3] = x * rows + y;
			if (indexes[3] != indexes[0] && indexes[3] != indexes[1] && indexes[3] != indexes[2] && cells.size()-1>=indexes[3]) {
				cells.at(indexes[3])->AddHare(i);
			}
			//	delete[] indexes;
		}
		

	}

	void Grid::ClearGrid()
	{
		for (unsigned int i = 0; i < cells.size(); i++)
		{
			cells.at(i)->ClearCell();
		}
	}

	void Grid::WolfCollideWithHare(std::vector<sf::Sprite> *wolf, std::vector<sf::Sprite> *hare)
	{
		Collision collision;
		int k = 0;
		for (int i = 0; i < cells.size(); i++)
		{
		
			for (int j = 0; j < cells.at(i)->GetWolfSprites().size(); j++)
			{
				for (int z = 0; z < cells.at(i)->GetHareSprites().size(); z++)
				{
					//zamien to na wektor z numerami indeksow
					if (hare->size() > z-k) {
						if (collision.CheckCollision(&(*wolf).at(cells.at(i)->GetWolfSprites().at(j)), &(*hare).at(cells.at(i)->GetHareSprites().at(z-k))))
						{
							(*hare).erase(hare->begin() + cells.at(i)->GetHareSprites().at(z - k));
							//cells.at(i)->GetHareSprites().erase(cells.at(i)->GetHareSprites().begin() + z);
							if ((*wolf).at(cells.at(i)->GetWolfSprites().at(j)).getScale().x < 2.0f && (*wolf).at(cells.at(i)->GetWolfSprites().at(j)).getScale().y < 2.0f)
							{
							(*wolf).at(cells.at(i)->GetWolfSprites().at(j)).scale(1.03f, 1.03f);
							}
							k++;			
							
						}
					}
					
				}
			}
		}
	}

	void Grid::SheWolfCollideWithHare(std::vector<sf::Sprite>* sheWolf, std::vector<sf::Sprite>* hare)
	{
		Collision collision;
		int k = 0;
		for (int i = 0; i < cells.size(); i++)
		{

			for (int j = 0; j < cells.at(i)->GetSheWolfSprites().size(); j++)
			{
				for (int z = 0; z < cells.at(i)->GetHareSprites().size(); z++)
				{
					//zamien to na wektor z numerami indeksow
					if (hare->size() > z - k) {
						if (collision.CheckCollision(&(*sheWolf).at(cells.at(i)->GetSheWolfSprites().at(j)), &(*hare).at(cells.at(i)->GetHareSprites().at(z - k))))
						{
							(*hare).erase(hare->begin() + cells.at(i)->GetHareSprites().at(z - k));
							//cells.at(i)->GetHareSprites().erase(cells.at(i)->GetHareSprites().begin() + z);
							k++;
							if ((*sheWolf).at(cells.at(i)->GetSheWolfSprites().at(j)).getScale().x < 2.0f && (*sheWolf).at(cells.at(i)->GetSheWolfSprites().at(j)).getScale().y < 2.0f)
							{
							(*sheWolf).at(cells.at(i)->GetSheWolfSprites().at(j)).scale(1.03f, 1.03f);
							}
						}
					}

				}
			}
		}
	}


	void Grid::WolfCollideWithSheWolf(std::vector<sf::Sprite>* wolf, std::vector<sf::Sprite>* sheWolf)
	{
		Collision collision;
		for (int i = 0; i < cells.size(); i++)
			if (cells.at(i)->GetWolfSprites().size() > 0 && (cells.at(i)->GetWolfSprites().size()+ cells.at(i)->GetSheWolfSprites().size()) < 4 && (wolf->size()+sheWolf->size())  < MAX_WOLF)
			{
				for (int a = 0; a < cells.at(i)->GetWolfSprites().size(); a++)
				{
					for (int b = 0; b < cells.at(i)->GetSheWolfSprites().size(); b++)
					{

						int random = rand() % 1000;
						if (random < 4)
						{
							if (a < wolf->size() && b < sheWolf->size() && a < cells.at(i)->GetWolfSprites().size() && b < cells.at(i)->GetSheWolfSprites().size()) {

								if (collision.CheckCollision(&(*wolf).at(cells.at(i)->GetWolfSprites().at(a)), &(*sheWolf).at(cells.at(i)->GetSheWolfSprites().at(b))))
								{
									sf::Sprite sprite(_data->assets.GetTexture("Wolf Texture"));
									sprite.setPosition((*wolf).at(cells.at(i)->GetWolfSprites().at(a)).getPosition().x + 10, (*wolf).at(cells.at(i)->GetWolfSprites().at(a)).getPosition().y - 10);
									wolf->push_back(sprite);
									random = (rand() + i) % 1000;
									break;
								}
							}

						}
					}
				}
			}
	}

	void Grid::HareCollideWithHare(std::vector<sf::Sprite> *hare)
	{
		Collision collision;
		for (int i = 0; i < cells.size(); i++)
		if (cells.at(i)->GetHareSprites().size() > 1 && cells.at(i)->GetHareSprites().size() < 4 && hare->size() < MAX_HARE)
		{
			for (int a = 0; a < cells.at(i)->GetHareSprites().size() - 1; a++)
			{
				for (int b = a + 1; b < cells.at(i)->GetHareSprites().size(); b++)
				{

					int random = rand() % 1000;
					if (random < 20)
					{
						if (a < hare->size() && b < hare->size() && a < cells.at(i)->GetHareSprites().size() && b < cells.at(i)->GetHareSprites().size()) {

							if (collision.CheckCollision(&(*hare).at(cells.at(i)->GetHareSprites().at(a)), &(*hare).at(cells.at(i)->GetHareSprites().at(b))))
							{
								sf::Sprite sprite(_data->assets.GetTexture("Hare Texture"));
								sprite.setPosition((*hare).at(cells.at(i)->GetHareSprites().at(a)).getPosition().x + 10, (*hare).at(cells.at(i)->GetHareSprites().at(a)).getPosition().y - 10);
								hare->push_back(sprite);
								random = (rand() + i) % 1000;
								break;
							}
						}

					}
				}
			}
		}
		
	}
	std::vector<GridCell*> Grid::GetColliderCells()
	{
		std::vector<GridCell*> colliderCells;
		for (int i = 0; i < cells.size(); i++)
		{
			if (cells.at(i)->IsCollider())
			{
				colliderCells.push_back(cells.at(i));
			}
		}
		return colliderCells;
	}
	Grid::~Grid()
	{
	}

}
	
	


