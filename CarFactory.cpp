#include "CarFactory.h"

using namespace object::cars;
using namespace shape::cars;

namespace factory {
	Taxi* createTaxi(const std::string& name, base::Subscriber* subscriber, const sf::Vector2f& pos)
	{
		return new Taxi(name, subscriber, pos);
	}
}
