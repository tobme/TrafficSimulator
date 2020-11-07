#include "Subscriber.h"

using namespace event;

namespace base {


	Subscriber::Subscriber()
	{
	}


	Subscriber::~Subscriber()
	{
	}

	void base::Subscriber::subscribe(const base::EventSpecifier event, IEventHandler* eventhandler)
	{
		auto& eventHandlers(m_eventMap[event]);
		eventHandlers.push_back(eventhandler);
	}

	void base::Subscriber::unsubscribe(const base::EventSpecifier event, IEventHandler* eventhandler)
	{
		//! @todo

	}

	//template<typename T>
	//void Subscriber::dispatchEvent(const T& event)
	//{
	//	for (const SubData& data : m_vector)
	//	{
	//		if (typeid(data.event) == typeid(T))
	//		{
	//			data.eventhandler->handleEvent(event);
	//		}
	//	}
	//}

}