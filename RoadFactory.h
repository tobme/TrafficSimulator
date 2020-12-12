#pragma once

#include "Road.h"
#include "Subscriber.h"

#include <SFML/Graphics.hpp>

namespace factory {

	std::unique_ptr<road::VerticalRoad> createVerticalRoad(const std::string& name,
		base::Subscriber* subscriber, const sf::Vector2f& pos);
}
