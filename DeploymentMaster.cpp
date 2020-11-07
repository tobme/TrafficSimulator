#include "DeploymentMaster.h"

#include "TriggerFactory.h"
#include "World.h"

#include "CarDeployment.h"

using namespace factory;

namespace deployment {
	void deployWorld()
	{
		addItem("Trigger", createTrigger(), true);

		deployCars();
	}
}