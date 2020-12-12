
#include "TriggerFactory.h"

#include<memory>

using namespace base;

namespace factory {

	std::unique_ptr<Trigger> createTrigger()
	{
		return std::make_unique<Trigger>("Trigger");
	}
}