#pragma once

#include "IEvents.h"
#include "IEventHandler.h"
#include "EventSubription.h"

#include<functional>
#include<map>
#include<vector>
#include<unordered_map>
#include<iostream>

namespace base {

	class Subscriber
	{
	public:
		Subscriber();
		~Subscriber();
		void subscribe(const base::EventSpecifier event, IEventHandler* eventhandler);
		void unsubscribe(const base::EventSpecifier event, IEventHandler* eventhandler);

		template<typename T>
		void dispatchEvent(const T& event)
		{
			auto& eventHandlers(m_eventMap[dynamic_cast<const IEvent&>(event).getEvent()]);

			for (auto& eventHandler : eventHandlers)
			{
				eventHandler->handleEvent(event);
			}
		}
	private:
		std::map<base::EventSpecifier, std::vector<IEventHandler*>> m_eventMap;

	};

}

