#include "CarDeployment.h"

#include "World.h"
#include "CarFactory.h"

using namespace base;
using namespace factory;

void deployment::deployCars()
{
	auto pSubscriber = &World::getInstance().m_subscriber;

	//addItem("Taxi1", createTaxi("Taxi1", pSubscriber), true);
}
