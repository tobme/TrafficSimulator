#pragma once

#include "IMovingAssistant.h"
#include "Subscriber.h"
#include "Map.h"
#include "CarStates.h"

namespace object {
	namespace cars {

		class CarMovingStateAssistant : public IMovingAssistant {
		public:
			CarMovingStateAssistant(const std::string& name,
				base::Subscriber* pSubscriber,
				const map::Map& map);
			~CarMovingStateAssistant() = default;

			void updateState(const std::string& name, const CarConfig& config, const sf::Vector2f& pos) override;

		private:
			bool canTurn(const CarConfig& config, const sf::Vector2f& pos);

			base::Subscriber* m_pSubscriber;
			map::Map m_map;
		};
	}
}