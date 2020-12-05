#include "DeploymentMaster.h"

#include "TriggerFactory.h"
#include "World.h"
#include "CarTrackerFactory.h"

#include "CarDeployment.h"

using namespace factory;
using namespace base;

namespace deployment {
	void deployWorld()
	{
		addItem("Trigger", createTrigger(), true);

		auto& world = World::getInstance();

		auto pSubscriber = &World::getInstance().m_subscriber;
		auto spICarTracker = createCarTracker("CarTracker", pSubscriber);

		world.init();

		addItem(spICarTracker->getName(), spICarTracker.get(), true);

		deployCars();
	}
}