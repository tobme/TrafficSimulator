#include "Grass.h"

#include "TextureId.h"

using namespace base;
using namespace object;

namespace shapes {

	unsigned int Grass::counter(1);

	Grass::Grass(const std::string& name, const sf::Vector2f& pos)
		: RectangleProp(name + std::to_string(counter++), GrassId, pos)
	{

	}
}