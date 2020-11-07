#include "Map.h"

using namespace base;
using namespace graphics;

namespace map {

	DrawableShape* Map::posToDrawableObject(const sf::Vector2f& pos) const
	{
		unsigned int x = pos.x / 50;
		unsigned int y = pos.y / 50;

		return dynamic_cast<DrawableShape*>(m_map[x][y]);
	}


	Map::Map()
		:m_map()
	{
	}

	Map::Map(unsigned int width, unsigned int height)
		: m_map(18, std::vector<IObject*>(32))
	{}

	Map::~Map()
	{}

	bool Map::isWalkable(const sf::Vector2f& pos) const
	{
		return posToDrawableObject(pos)->isWalkable();
	}
}