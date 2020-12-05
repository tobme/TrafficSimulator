
#include "CarTrackerFactory.h"

#include "CarTracker.h"

using namespace ::object::tracker;
using namespace ::base;

namespace factory {
	ICarTrackerSP createCarTracker(const std::string& name, Subscriber* pSubscriber)
	{
		return std::make_shared<CarTracker>(name, pSubscriber);
	}
}