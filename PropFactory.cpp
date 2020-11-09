#include "PropFactory.h"

using namespace shapes;

namespace factory {

	namespace {
		template<typename T>
		T* createProp(const std::string& name, const sf::Vector2f& pos)
		{
			return new T(name, pos);
		}
	}

	Grass* createGrass(const std::string& name, const sf::Vector2f& pos)
	{
		return createProp<Grass>(name, pos);
	}
}