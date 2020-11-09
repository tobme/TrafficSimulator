#include "Map.h"
#include "IDrawableObject.h"

using namespace base;
using namespace graphics;
using namespace object::cars;

using posPair = sf::Vector2f;
using constPosPair = const posPair;

namespace map {

	DrawableShape* Map::posToDrawableObject(const sf::Vector2f& pos) const
	{
		unsigned int x = pos.x / 50;
		unsigned int y = pos.y / 50;

		return dynamic_cast<DrawableShape*>(m_map[x][y]);
	}


	Map::Map()
		:m_map(), m_width(0), m_height(0)
	{
	}

	Map::Map(unsigned int width, unsigned int height)
		: m_map(width, std::vector<IObject*>(height)), m_width(width), m_height(height)
	{}

	Map::~Map()
	{}

	bool Map::isWalkable(const sf::Vector2f& pos) const
	{
		std::cout << "isWakableeee " << pos.x << " " << pos.y << std::endl;
		if (pos.x < 0 || pos.y < 0 || pos.x / 50 > m_width || pos.y / 50 > m_height)
		{
			//std::cout << "X" << pos.x << " Y " << pos.y << std::endl;
			//std::cout << "X / 50" << pos.x / 50 << " Y / 50" << pos.y / 50 << std::endl;
			//std::cout << "Width " << m_width << " height " << m_height << std::endl;
			//std::cout << "Here232" << std::endl;
			return false;
		}

		return posToDrawableObject(pos)->isWalkable();
	}
	constPosPair& Map::toTheLeft(constPosPair& pos, Direction dir) const
	{
		switch (dir)
		{
		case Direction::EAST:
			return constPosPair(pos.x, pos.y - PROP_SIZE * 2);
			break;
		case Direction::NORTH:
			return constPosPair(pos.x - PROP_SIZE * 2, pos.y);
			break;
		case Direction::SOUTH:
			return constPosPair(pos.x + PROP_SIZE * 2, pos.y);
			break;
		case Direction::WEST:
			return constPosPair(pos.x, pos.y + PROP_SIZE * 2);
			break;
		default:
			return pos;
			break;
		}
	}
	constPosPair& Map::toTheRight(constPosPair& pos, Direction dir) const
	{
		switch (dir)
		{
		case Direction::EAST:
			return constPosPair(pos.x, pos.y + PROP_SIZE);
			break;
		case Direction::NORTH:
			return constPosPair(pos.x + PROP_SIZE, pos.y);
			break;
		case Direction::SOUTH:
			return constPosPair(pos.x - PROP_SIZE, pos.y);
			break;
		case Direction::WEST:
			return constPosPair(pos.x, pos.y - PROP_SIZE);
			break;
		default:
			return pos;
			break;
		}
	}
	constPosPair& Map::toTheUp(constPosPair& pos, Direction dir) const
	{
		switch (dir)
		{
		case Direction::EAST:
			return constPosPair(pos.x + PROP_SIZE, pos.y);
			break;
		case Direction::NORTH:
			return constPosPair(pos.x, pos.y - PROP_SIZE);
			break;
		case Direction::SOUTH:
			return constPosPair(pos.x, pos.y + PROP_SIZE);
			break;
		case Direction::WEST:
			return constPosPair(pos.x - PROP_SIZE, pos.y);
			break;
		default:
			return pos;
			break;
		}
	}
	constPosPair& Map::toTheDown(constPosPair& pos, Direction dir) const
	{
		switch (dir)
		{
		case Direction::EAST:
			return constPosPair(pos.x - PROP_SIZE, pos.y);
			break;
		case Direction::NORTH:
			return constPosPair(pos.x, pos.y + PROP_SIZE);
			break;
		case Direction::SOUTH:
			return constPosPair(pos.x, pos.y - PROP_SIZE);
			break;
		case Direction::WEST:
			return constPosPair(pos.x + PROP_SIZE, pos.y);
			break;
		default:
			return pos;
			break;
		}
	}
}