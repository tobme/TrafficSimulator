#pragma once

#include <SFML/Graphics.hpp>

#include <memory>
#include<iostream>

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

		unsigned int getDrawingNumber() const
		{
			return m_drawingOrder;
		}

	private:
		// Drawing order 0 -> Outer Layer
        // So order = 1 draws on top of order = 0
		unsigned int m_drawingOrder;
	};

	inline bool isGreaterThan(const DrawableShape* rhs, const DrawableShape* lhs)
	{
		return rhs->getDrawingNumber() < lhs->getDrawingNumber();
	}
}

