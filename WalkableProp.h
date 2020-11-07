#pragma once

#include "IDrawableObject.h"
#include "TextureId.h"

namespace object {
	class WalkableRectangleProp : public base::RectangleObject
	{
	public:
		WalkableRectangleProp(const std::string& name, base::TextureId textureId, const sf::Vector2f& pos, unsigned int drawingOrder = 0);
		~WalkableRectangleProp();
		bool isWalkable() const override;
	};
}