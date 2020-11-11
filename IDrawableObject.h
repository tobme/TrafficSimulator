#pragma once

#include "IObject.h"
#include "DrawableShape.h"
#include "TextureId.h"

#include <SFML/Graphics.hpp>
#include<iostream>

static const int PROP_SIZE = 50;

namespace base {
	template <typename shapeT>
	class IDrawableObject : public IObject, public graphics::DrawableShape
	{
	public:

		using DrawingObject = shapeT;

		IDrawableObject<shapeT>(const std::string& name, std::unique_ptr<shapeT> shape, const base::TextureId& textureName, const sf::Vector2f& pos, unsigned int drawingOrder)
			: IObject(name), graphics::DrawableShape(drawingOrder), m_upShape(shape.release()), m_texture()
		{
			m_texture.loadFromFile(textureName);
			dynamic_cast<sf::Shape*>(m_upShape.get())->setTexture(&m_texture, true);
			dynamic_cast<sf::Shape*>(m_upShape.get())->setPosition(pos);
		}

		virtual ~IDrawableObject() = default;

		void draw(sf::RenderWindow& renderwindow) const override
		{
			renderwindow.draw(*m_upShape);
		}

		//! Default is non-wakable.
		//! Override this function if you want your object to be wakable.
		virtual bool isWalkable() const override
		{
			return false;
		}

		shapeT* getShape() { return m_upShape.get(); }

	private:
		std::unique_ptr<shapeT> m_upShape;
		sf::Texture m_texture;
	};

	using RectangleObject = base::IDrawableObject<sf::RectangleShape>;
}