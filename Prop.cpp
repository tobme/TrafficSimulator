#include "Prop.h"

using namespace base;
using namespace sf;

namespace object {

	RectangleProp::RectangleProp(const std::string& name, TextureId textureId, const sf::Vector2f& pos, unsigned int drawingOrder)
		: RectangleObject(name, std::make_unique<RectangleShape>(Vector2f(PROP_SIZE, PROP_SIZE)), textureId, pos, drawingOrder)
	{

	}
	RectangleProp::~RectangleProp()
	{}
}