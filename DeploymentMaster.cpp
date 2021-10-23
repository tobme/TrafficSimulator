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
		auto upICarTracker = createCarTracker("CarTracker", pSubscriber);

		std::string trackerName(upICarTracker->getName());
		addItem(trackerName, std::move(upICarTracker), true);

		world.init();



		deployCars();
	}
}