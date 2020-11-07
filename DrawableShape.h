#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

namespace graphics {

	class DrawableShape
	{
	public:
		DrawableShape(unsigned int drawingOrder)
			: m_drawingOrder(drawingOrder)
		{

		}
		virtual ~DrawableShape() = default;
		virtual void draw(sf::RenderWindow& renderwindow) const = 0;
		virtual bool isWalkable() const = 0;


		bool operator>(const DrawableShape* rhs) const
		{
			return !(this < rhs);
		}
		bool operator<(const DrawableShape* rhs) const
		{
			return this->m_drawingOrder < rhs->m_drawingOrder;
		}


	private:
		// Drawing order 0 -> Outer Layer
        // So order = 1 draws on top of order = 0
		unsigned int m_drawingOrder;
	};
}

