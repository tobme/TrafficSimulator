#include "CarSimulator.h"
#include "EventSubription.h"

using namespace base;
using namespace event;
using namespace map;

namespace object {
	namespace cars {
		CarSimulator::CarSimulator(const std::string& name,
			const Map& map,
			Subscriber* pSubscriber,
			Config config)
			: EventHandler<event::GPSUpdateEvent>()
			, ITriggable()
			, IObject(name)
			, m_map(map)
			, m_pSubscriber(pSubscriber)
			, m_pCarMovingStateAssistant(config.m_pCarMovingStateAssistant)
			, m_pCarPedalAssistant(config.m_pCarPedalAssistant)
			, m_pCarTurningAssistant(config.m_pCarTurningAssistant)
		{
			m_pSubscriber->subscribe(GPSUpdateSubscription, this);
		}

		// Car send gps update...
		// Start of simulation
		void CarSimulator::doHandle(const GPSUpdateEvent& event)
		{
			std::string name = event.getName();
			auto& pos = event.position;
			auto& config = event.config;

			//! Checks so the car doesn't leave road
			//! 
			//! If there are no turns available, then the assistant sets
			//! the cars turn state.
			m_pCarMovingStateAssistant->updateState(name, config, pos);

			m_pCarPedalAssistant->updateState(name, config, pos);

			m_pCarTurningAssistant->updateState(name, config, pos);
		}

		// NEEDED? doHandle and trigger work on different threads
		// Avoid if possible
		void CarSimulator::updateTrigger()
		{
		}

	}
}