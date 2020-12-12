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
	std::string assistantName(spIMovingAssistantHandler->getName());

	CarSimulator::Config config;
	config.spIMovingAssistantHandler = static_cast<object::IMovingAssistantHandlerSP>(spIMovingAssistantHandler.get());

	addItem(assistantName, std::move(spIMovingAssistantHandler), true);

	addItem("CarSimulator",
		createCarSimulator("CarSimulator", map, pSubscriber, config), true);
}
