#pragma once

#include<string>

namespace base {
	enum EventSpecifier {
		VEHICLE_MOVED,
		VEHICLE_DIRECTION,
		GPS_UPDATE
	};

	class IEvent {
	public:
		std::string getName() const
		{
			return m_name;
		}
		EventSpecifier getEvent() const
		{
			return m_event;
		}
	protected:
		IEvent(const std::string& name, EventSpecifier event)
			: m_name(name), m_event(event)
		{}
	private:
		std::string m_name;
		EventSpecifier m_event;
	};
}