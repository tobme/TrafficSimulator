#pragma once

#include "DrawableShape.h"
#include "IObject.h"

#include<vector>

#include <SFML/Graphics.hpp>

namespace map {

	class Map
	{
	public:
		Map();
		Map(unsigned int width, unsigned int height);
		~Map();

		template<typename T>
		void add(unsigned int x, unsigned int y, T item);
		bool isWalkable(const sf::Vector2f& pos) const;
	private:
		using PropMap = std::vector< std::vector<base::IObject*> >;

		graphics::DrawableShape* posToDrawableObject(const sf::Vector2f& pos) const;

		PropMap m_map;
	};

	template <typename T>
	inline void Map::add(unsigned int x, unsigned int y, T item)
	{
		m_map[x][y] = item;
	}
	//using Map = std::vector< std::vector<base::IObject*> >;
}