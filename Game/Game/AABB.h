#pragma once
#include <SFML\System.hpp>

class AABB
{
	sf::Vector2f center;
	float halfDimension;

public:
	AABB(sf::Vector2f center, float halfDimension);
	bool containsPoint(sf::Vector2f point);
	bool intersectsAABB(AABB *other);
	~AABB();
};

