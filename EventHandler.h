#pragma once
#include "IEventHandler.h"

#include "IEvents.h"

namespace base {

	template <typename T>
	class EventHandler : public IEventHandler
	{
	public:
		EventHandler() = default;
		virtual ~EventHandler() = default;

		void handleEvent(const IEvent& e) override
		{
			doHandle(static_cast<const T&>(e));
		}

		virtual void doHandle(const T& e) = 0;
	};

}



