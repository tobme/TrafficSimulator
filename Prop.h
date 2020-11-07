#pragma once

#include "IDrawableObject.h"
#include "TextureId.h"

namespace object {
	class RectangleProp : public base::RectangleObject
	{
	public:
		RectangleProp(const std::string& name, base::TextureId textureId, const sf::Vector2f& pos, unsigned int drawingOrder = 0);
		~RectangleProp();
	};
}