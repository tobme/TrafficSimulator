#pragma once

#include "Trigger.h"

namespace factory {
	std::unique_ptr<base::Trigger> createTrigger();
}