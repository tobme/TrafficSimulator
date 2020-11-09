#include "MovableAssistantFactory.h"

#include "CarMovingStateAssistant.h"
#include "CarPedalAssistant.h"

using namespace object::cars;
using namespace base;

namespace factory {
	IMovingAssistant* createCarMovingStateAssistant(const std::string& name,
		Subscriber* pSubscriber,
		const map::Map& map)
	{
		return new CarMovingStateAssistant(name, pSubscriber, map);
	}

	IMovingAssistant* createCarPedalAssistant(const std::string& name,
		Subscriber* pSubscriber,
		const map::Map& map)
	{
		return new CarPedalAssistant(name, pSubscriber, map);
	}
}