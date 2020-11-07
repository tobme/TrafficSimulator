#pragma once

#include <SFML/Graphics.hpp>

namespace graphics {
	class IDrawableShape{
	public:
		virtual ~IDrawableShape() = default;

		virtual void draw(const sf::RenderWindow& renderwindow) = 0;
	};
}