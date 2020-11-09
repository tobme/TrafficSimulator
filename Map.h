#pragma once

#include "DrawableShape.h"
#include "IObject.h"
#include "CarStates.h"

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

		const sf::Vector2f& toTheLeft(const sf::Vector2f& pos, object::cars::Direction dir) const;
		const sf::Vector2f& toTheRight(const sf::Vector2f& pos, object::cars::Direction dir) const;
		const sf::Vector2f& toTheUp(const sf::Vector2f& pos, object::cars::Direction dir) const;
		const sf::Vector2f& toTheDown(const sf::Vector2f& pos, object::cars::Direction dir) const;
	private:
		using PropMap = std::vector< std::vector<base::IObject*> >;

		graphics::DrawableShape* posToDrawableObject(const sf::Vector2f& pos) const;

		PropMap m_map;

		unsigned int m_width;
		unsigned int m_height;
	};

	template <typename T>
	inline void Map::add(unsigned int x, unsigned int y, T item)
	{
		m_map[x][y] = item;
	}
	//using Map = std::vector< std::vector<base::IObject*> >;
}