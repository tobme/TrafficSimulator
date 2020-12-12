#include "PropFactory.h"

using namespace shapes;

namespace factory {

	namespace {
		template<typename T>
		std::unique_ptr<T> createProp(const std::string& name, const sf::Vector2f& pos)
		{
			return std::make_unique<T>(name, pos);
		}
	}

	std::unique_ptr<Grass> createGrass(const std::string& name, const sf::Vector2f& pos)
	{
		return createProp<Grass>(name, pos);
	}
}