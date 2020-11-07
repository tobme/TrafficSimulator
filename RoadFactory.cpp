#include "RoadFactory.h"

using namespace object;
using namespace road;

namespace factory {
	VerticalRoad* createVerticalRoad(const std::string& name, base::Subscriber* subscriber, const sf::Vector2f& pos)
	{
		return new VerticalRoad(name, subscriber, pos);
	}
}
