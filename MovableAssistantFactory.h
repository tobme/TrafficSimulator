#pragma once

#include "IMovingAssistant.h"
#include "IMovingAssistantHandler.h"
#include "Map.h"
#include "Subscriber.h"

namespace factory {

	object::IMovingAssistantHandlerSP createIMovingAssistantHandler(base::Subscriber* pSubscriber,
		const map::Map& map);
}