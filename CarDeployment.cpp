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

	auto spIMovingAssistantHandler = createIMovingAssistantHandler(pSubscriber, map);
	addItem(spIMovingAssistantHandler->getName(), spIMovingAssistantHandler.get(), true);

	CarSimulator::Config config;
	config.spIMovingAssistantHandler = spIMovingAssistantHandler;

	addItem("CarSimulator",
		createCarSimulator("CarSimulator", map, pSubscriber, config), true);
}
