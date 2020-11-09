#pragma once

#include "Taxi.h"
#include "CarSimulator.h"
#include "Subscriber.h"

#include <SFML/Graphics.hpp>

namespace factory {

	shape::cars::Taxi* createTaxi(const std::string& name,
		base::Subscriber* subscriber, const sf::Vector2f& pos);

	object::cars::CarSimulator* createCarSimulator(const std::string& name,
		const map::Map& map,
		base::Subscriber* pSubscriber,
		object::cars::CarSimulator::Config config);
}

