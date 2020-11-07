#pragma once

#include "Taxi.h"
#include "Subscriber.h"

#include <SFML/Graphics.hpp>

namespace factory {

	shape::cars::Taxi* createTaxi(const std::string& name,
		base::Subscriber* subscriber, const sf::Vector2f& pos);
}

