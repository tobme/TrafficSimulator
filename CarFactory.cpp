#include "CarFactory.h"

#include "World.h"
#include "Trigger.h"

using namespace base;
using namespace map;
using namespace object::cars;
using namespace shape::cars;

namespace factory {
	Taxi* createTaxi(const std::string& name, base::Subscriber* subscriber, const sf::Vector2f& pos)
	{
		auto pTaxi = new Taxi(name, subscriber, pos);

		auto trigger = World::getItem<Trigger>("Trigger");

		trigger->addTriggable(pTaxi, TimeElapsed::ELAPSED_0);

		return pTaxi;
	}

	CarSimulator* createCarSimulator(const std::string& name, const Map& map, Subscriber* pSubscriber, CarSimulator::Config config)
	{
		return new CarSimulator(name, map, pSubscriber, config);
	}
}
