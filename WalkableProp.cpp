#include "WalkableProp.h"

using namespace base;
using namespace sf;

namespace object {

	WalkableRectangleProp::WalkableRectangleProp(const std::string& name, TextureId textureId, const sf::Vector2f& pos, unsigned int drawingOrder)
		: RectangleObject(name, std::make_unique<RectangleShape>(Vector2f(100, 50)), textureId, pos, drawingOrder)
	{

	}
	WalkableRectangleProp::~WalkableRectangleProp()
	{}

	bool WalkableRectangleProp::isWalkable() const
	{
		return true;
	}
}