#pragma once

#include "Map.h"
#include "EventHandler.h"
#include "VehicleEventHandler.h"
#include "Subscriber.h"
#include "ITriggable.h"
#include "IObject.h"

#include "IMovingAssistant.h"

namespace object {
	namespace cars {
		class CarSimulator 
			: public base::EventHandler<event::GPSUpdateEvent>
			, public base::ITriggable
			, public base::IObject
		{
		public:
			struct Config {
				IMovingAssistant* m_pCarMovingStateAssistant;
				IMovingAssistant* m_pCarPedalAssistant;
				IMovingAssistant* m_pCarTurningAssistant;
			};

			CarSimulator(const std::string& name,
				const ::map::Map& map,
				base::Subscriber* pSubscriber,
				Config config);
			~CarSimulator() = default;

			void doHandle(const event::GPSUpdateEvent& event) override;
			void updateTrigger() override;
		private:
			::map::Map m_map;
			base::Subscriber* m_pSubscriber;
			IMovingAssistant* m_pCarMovingStateAssistant;
			IMovingAssistant* m_pCarPedalAssistant;
			IMovingAssistant* m_pCarTurningAssistant;
		};

	}
}