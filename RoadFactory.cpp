#include "RoadFactory.h"

using namespace object;
using namespace road;

namespace factory {
	std::unique_ptr<VerticalRoad> createVerticalRoad(const std::string& name, base::Subscriber* subscriber, const sf::Vector2f& pos)
	{
		return std::make_unique<VerticalRoad>(name, subscriber, pos);
	}
}
