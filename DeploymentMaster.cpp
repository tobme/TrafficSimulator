#include "DeploymentMaster.h"

#include "TriggerFactory.h"
#include "World.h"

#include "CarDeployment.h"

using namespace factory;
using namespace base;

namespace deployment {
	void deployWorld()
	{
		addItem("Trigger", createTrigger(), true);

		auto& world = World::getInstance();
		world.init();

		deployCars();
	}
}