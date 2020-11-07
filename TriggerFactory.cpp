
#include "TriggerFactory.h"

#include<memory>

using namespace base;

namespace factory {

	Trigger* createTrigger()
	{
		return new Trigger("Trigger");
	}
}