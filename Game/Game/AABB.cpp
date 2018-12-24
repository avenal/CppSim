#include "AABB.h"



AABB::AABB(sf::Vector2f center, float halfDimension) :center(center), halfDimension(halfDimension){ }

bool AABB::containsPoint(sf::Vector2f point)
{
	if (point.x >= center.x - halfDimension && point.x <= center.x + halfDimension
	 && point.y >= center.y - halfDimension && point.y <= center.y + halfDimension)
	{
		return true;
	}
	return false;
}

bool AABB::intersectsAABB(AABB * other)
{
	//top left
	if (center.x - halfDimension > other->center.x + other->halfDimension && center.y - halfDimension < other->center.y + other->halfDimension)
	{
		return true;
	}
	//bottom left
	if (center.x - halfDimension > other->center.x + other->halfDimension && center.y + halfDimension > other->center.y - other->halfDimension)
	{
		return true;
	}
	//top right
	if (center.x + halfDimension < other->center.x - other->halfDimension && center.y - halfDimension < other->center.y + other->halfDimension)
	{
		return true;
	}
	//bottom right
	if (center.x + halfDimension < other->center.x - other->halfDimension && center.y + halfDimension > other->center.y - other->halfDimension)
	{
		return true;
	}
	return false;
}

AABB::~AABB()
{
}
