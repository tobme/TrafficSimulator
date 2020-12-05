
#pragma once

#include "ICarTracker.h"

#include "Subscriber.h"

namespace factory {
	object::tracker::ICarTrackerSP createCarTracker(const std::string& name,
		base::Subscriber* pSubscriber);
}