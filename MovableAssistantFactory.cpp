#include "MovableAssistantFactory.h"

#include "CarMovingStateAssistant.h"
#include "CarPedalAssistant.h"
#include "TurningStateAssistant.h"
#include "MovingAssistantHandler.h"

#include<memory>

using namespace object;
using namespace object::cars;
using namespace base;

namespace factory {
	IMovingAssistantSP createCarMovingStateAssistant(const std::string& name,
		Subscriber* pSubscriber,
		const map::Map& map)
	{
		return std::make_shared<CarMovingStateAssistant>(name, pSubscriber, map);
	}

	IMovingAssistantSP createCarPedalAssistant(const std::string& name,
		Subscriber* pSubscriber,
		const map::Map& map)
	{
		return std::make_shared<CarPedalAssistant>(name, pSubscriber, map);
	}

	IMovingAssistantSP createTurningStateAssistant(const std::string& name, Subscriber* pSubscriber,
		const map::Map& map)
	{
		return std::make_shared<TurningStateAssistant>(name, pSubscriber, map);
	}

	object::IMovingAssistantHandlerSP createIMovingAssistantHandler(base::Subscriber* pSubscriber, const map::Map& map)
	{
		auto spMovingAssistantHandler(std::make_shared<MovingAssistantHandler>());

		spMovingAssistantHandler->addAssistant(createCarMovingStateAssistant("CarMovingStateAssistant", pSubscriber, map));

		spMovingAssistantHandler->addAssistant(createCarPedalAssistant("CarPedalAssistant", pSubscriber, map));

		spMovingAssistantHandler->addAssistant(createTurningStateAssistant("TurningStateAssistant", pSubscriber, map));

		return spMovingAssistantHandler;
	}
}