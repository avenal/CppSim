#include "Wolf.h"


namespace Engine
{
	Wolf::Wolf(GameDataRef data) : Animal(data)
	{

	}


	 sf::Vector2f Wolf::normalize(const sf::Vector2f & source)
	 {
		 float length = sqrt((source.x * source.x) + (source.y * source.y));
		 if (length != 0)
			 return sf::Vector2f(source.x / length, source.y / length);
		 else
			 return source;
	 }

	//todo: move towards shewolf and add hp to wolf (decrease by 1 for each step whithout hunting)
	 //add collision with terrain
	 void Wolf::Move(float dt, Grid *chaseGrid, std::vector<GridCell*> collisionCells, std::vector<sf::Sprite>* sheWolf, std::vector<sf::Sprite> *hare)
	 {
		 AvoidColliders(dt, collisionCells);
		 ChaseSheWolfOrHare(dt, chaseGrid, sheWolf, hare);
		 AvoidBoundaryAndMoveRandomly(dt);
	 }
	void Wolf::ChaseSheWolfOrHare(float dt, Grid * chaseGrid, std::vector<sf::Sprite>* sheWolf, std::vector<sf::Sprite>* hare)
	{
		float movement = ANIMAL_MOVEMENT_SPEED * dt;
		for (int z = 0; z < (chaseGrid->GetGridCells().size()); z++)
		{
			if ((chaseGrid->GetGridCells().at(z)->GetHareSprites().size() > 0 || chaseGrid->GetGridCells().at(z)->GetSheWolfSprites().size() > 0) && chaseGrid->GetGridCells().at(z)->GetWolfSprites().size() > 0)
			{

				for (int y = 0; y < chaseGrid->GetGridCells().at(z)->GetWolfSprites().size(); y++)
				{
					int randomChase = rand() % chaseGrid->GetGridCells().at(z)->GetWolfSprites().size();
					if (chaseGrid->GetGridCells().at(z)->GetHareSprites().size() > chaseGrid->GetGridCells().at(z)->GetSheWolfSprites().size())
					{
						//dziala ale przemysl zeby dzialalo lepiej
						sf::Vector2f dir = normalize(animalSprites.at(chaseGrid->GetGridCells().at(z)->GetWolfSprites().at(y)).getPosition() - hare->at(chaseGrid->GetGridCells().at(z)->GetHareSprites().at(0)).getPosition());
						animalSprites.at(chaseGrid->GetGridCells().at(z)->GetWolfSprites().at(randomChase)).move(-movement * dir);
					}
					else
					{
						sf::Vector2f dir = normalize(animalSprites.at(chaseGrid->GetGridCells().at(z)->GetWolfSprites().at(y)).getPosition() - sheWolf->at(chaseGrid->GetGridCells().at(z)->GetSheWolfSprites().at(0)).getPosition());
						animalSprites.at(chaseGrid->GetGridCells().at(z)->GetWolfSprites().at(randomChase)).move(-movement * dir);
					}
					
				}
			}
		}
		
	}
	void Wolf::AvoidColliders(float dt, std::vector<GridCell*> collisionCells)
	{
		float movement = ANIMAL_MOVEMENT_SPEED * dt;
		if (collisionCells.size() > 0)
		{
			for (int i = 0; i < animalSprites.size(); i++)
			{
				for (int h = 0; h < collisionCells.size(); h++)
				{
					if ((&animalSprites.at(i))->getGlobalBounds().intersects(collisionCells.at(h)->GetCellSprite().getGlobalBounds()))
					{
						sf::Vector2f dir = normalize((&animalSprites.at(i))->getPosition() - collisionCells.at(h)->GetCellSprite().getPosition());
						animalSprites.at(i).move(movement*dir*5.0f);
					}
				}
			}
		}

	}
	void Wolf::AvoidBoundaryAndMoveRandomly(float dt)
	{
		Collision collision;
		float movement = ANIMAL_MOVEMENT_SPEED * dt;
		for (int i = 0; i < animalSprites.size(); i++)
		{
		int random = rand() % 4;
			if (collision.CheckBorderCollision(animalSprites.at(i)) > 0)
			{
				animalSprites.at(i).move(movement * BOUNCE_SPEED, 0);
				//movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites.at(i)) == 2)
			{
				animalSprites.at(i).move(0, movement *  BOUNCE_SPEED);
				//movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites.at(i)) == 3)
			{
				animalSprites.at(i).move(0, -movement * BOUNCE_SPEED);
				//movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites.at(i)) == 4)
			{
				animalSprites.at(i).move(-movement * BOUNCE_SPEED, 0);
				//movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites.at(i)) == 5)
			{
				animalSprites.at(i).move(movement *  BOUNCE_SPEED, movement *  BOUNCE_SPEED);
				//movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites.at(i)) == 6)
			{
				animalSprites.at(i).move(-movement * BOUNCE_SPEED, movement * BOUNCE_SPEED);
				//movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites.at(i)) == 7)
			{
				animalSprites.at(i).move(movement * BOUNCE_SPEED, -movement * BOUNCE_SPEED);
				//movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites.at(i)) == 8)
			{
				animalSprites.at(i).move(-movement * BOUNCE_SPEED, -movement * BOUNCE_SPEED);
				//movement *= -1;
			}else if (random == 0)//up
			{
				animalSprites.at(i).move(0, -movement);
			}//down
			else if (random == 1)
			{
				animalSprites.at(i).move(0, movement);
			}//left
			else if (random == 2)
			{
				animalSprites.at(i).move(-movement, 0);
			}
			else if (random == 3)
			{
				animalSprites.at(i).move(movement, 0);
			}
		}
	}

	void Wolf::Spawn(int x, int y)
	{
		sf::Sprite sprite(_data->assets.GetTexture("Wolf Texture"));
		sprite.setPosition(x, y);
		animalSprites.push_back(sprite);
	}

	void Wolf::SpawnRandom()
	{

	}



	Wolf::~Wolf()
	{
	}
}

