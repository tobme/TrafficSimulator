#pragma once

#include"IEvents.h"

namespace base {
	class IEventHandler {
	public:
		virtual void handleEvent(const IEvent& e) = 0;
		virtual ~IEventHandler() = default;
	};
}