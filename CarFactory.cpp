#include "CarFactory.h"

#include "FrontCamera.h"
#include "ICarTracker.h"
#include "World.h"
#include "Trigger.h"

#include<memory>

using namespace base;
using namespace map;
using namespace object::cars;
using namespace object::tracker;
using namespace shape::cars;

namespace factory {
	std::unique_ptr<Taxi> createTaxi(const std::string& name, base::Subscriber* subscriber, const sf::Vector2f& pos)
	{
		auto pCarTracker = World::getItem<ICarTracker>("CarTracker");

		auto spFrontCamera(std::make_shared<FrontCamera>(name, pCarTracker));

		auto pTaxi = std::make_unique<Taxi>(name, subscriber, pos, spFrontCamera);

		auto trigger = World::getItem<Trigger>("Trigger");

		trigger->addTriggable(pTaxi.get(), TimeElapsed::ELAPSED_0);

		return pTaxi;
	}

	std::unique_ptr<CarSimulator> createCarSimulator(const std::string& name, const Map& map, Subscriber* pSubscriber, CarSimulator::Config config)
	{
		return std::make_unique<CarSimulator>(name, map, pSubscriber, config);
	}
}
