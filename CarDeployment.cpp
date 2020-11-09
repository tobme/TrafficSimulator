#include "CarDeployment.h"

#include "World.h"
#include "CarFactory.h"
#include "MovableAssistantFactory.h"

using namespace base;
using namespace factory;
using namespace object::cars;

void deployment::deployCars()
{
	auto pSubscriber = &World::getInstance().m_subscriber;
	auto& map = World::getInstance().m_map;

	auto pCarMovingStateAssistant = createCarMovingStateAssistant("CarMovingStateAssistant", pSubscriber, map);
	addItem(pCarMovingStateAssistant->getName(), pCarMovingStateAssistant, true);

	auto pCarPedalAssistant = createCarPedalAssistant("CarPedalAssistant", pSubscriber, map);
	addItem(pCarPedalAssistant->getName(), pCarMovingStateAssistant, true);

	CarSimulator::Config config;
	config.m_pCarMovingStateAssistant = pCarMovingStateAssistant;
	config.m_pCarPedalAssistant = pCarPedalAssistant;

	addItem("CarSimulator",
		createCarSimulator("CarSimulator", map, pSubscriber, config), true);
}
