#include "TriggerConnector.h"
#include "World.h"
#include "Trigger.h"
#include "MovableObject.h"
#include "Taxi.h"

using namespace base;
using namespace shape::cars;

namespace deployment {
	void connectTriggers()
	{
		auto trigger = World::getItem<Trigger>("Trigger");

		// @todo Needs to made dynamic
		auto Taxi1 = World::getItem<Taxi>("Taxi1");

		trigger->addTriggable(Taxi1, base::TimeElapsed::ELAPSED_0);
	}
}