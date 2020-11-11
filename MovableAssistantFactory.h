#pragma once

#include "IMovingAssistant.h"
#include "Map.h"
#include "Subscriber.h"

namespace factory {
	object::cars::IMovingAssistant* createCarMovingStateAssistant(const std::string& name,
		base::Subscriber* pSubscriber,
		const map::Map& map);

	object::cars::IMovingAssistant* createCarPedalAssistant(const std::string& name,
		base::Subscriber* pSubscriber,
		const map::Map& map);

	object::cars::IMovingAssistant* createTurningStateAssistant(const std::string& name,
		base::Subscriber* pSubscriber,
		const map::Map& map);
}