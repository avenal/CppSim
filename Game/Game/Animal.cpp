#include "Animal.h"

namespace Engine
{
	Animal::Animal(GameDataRef data) : _data(data)
	{

	}
	void Animal::DrawAnimals()
	{
		for (unsigned int i = 0; i < animalSprites.size(); i++)
		{
			_data->window.draw(animalSprites.at(i));
		}
	}
	void Animal::Move(float dt)
	{
		Collision collision;
		std::srand(std::time(NULL));
		for (unsigned int i = 0; i < animalSprites.size(); i++)
		{
			int random = rand() % 8;
			sf::Vector2f position = animalSprites.at(i).getPosition();
			float movement = ANIMAL_MOVEMENT_SPEED * dt;
			if (collision.CheckBorderCollision(animalSprites.at(i)) == 1)
			{
				animalSprites.at(i).move(movement * BOUNCE_SPEED, 0);
				movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites.at(i)) == 2)
			{
				animalSprites.at(i).move(0, movement *  BOUNCE_SPEED);
				movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites.at(i)) == 3)
			{
				animalSprites.at(i).move(0, -movement * BOUNCE_SPEED);
				movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites.at(i)) == 4)
			{
				animalSprites.at(i).move(-movement * BOUNCE_SPEED, 0);
				movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites.at(i)) == 5)
			{
				animalSprites.at(i).move(movement *  BOUNCE_SPEED, movement *  BOUNCE_SPEED);
				movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites.at(i)) == 6)
			{
				animalSprites.at(i).move(-movement * BOUNCE_SPEED, movement * BOUNCE_SPEED);
				movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites.at(i)) == 7)
			{
				animalSprites.at(i).move(movement * BOUNCE_SPEED, -movement * BOUNCE_SPEED);
				movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites.at(i)) == 8)
			{
				animalSprites.at(i).move(-movement * BOUNCE_SPEED, -movement * BOUNCE_SPEED);
				movement *= -1;
			}
			else if (random == 0)//up
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
	 std::vector<sf::Sprite>& Animal::GetSprite() 
	{
		return animalSprites;
	}

	Animal::~Animal()
	{
		delete [] &animalSprites;
	}
}