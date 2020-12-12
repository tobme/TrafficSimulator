
#include "CarTrackerFactory.h"

#include "CarTracker.h"

using namespace ::object::tracker;
using namespace ::base;

namespace factory {
	ICarTrackerUP createCarTracker(const std::string& name, Subscriber* pSubscriber)
	{
		return std::make_unique<CarTracker>(name, pSubscriber);
	}
}