
#pragma once

#include "ICarTracker.h"

#include "Subscriber.h"

namespace factory {
	object::tracker::ICarTrackerUP createCarTracker(const std::string& name,
		base::Subscriber* pSubscriber);
}