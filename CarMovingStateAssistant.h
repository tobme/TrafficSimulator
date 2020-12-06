#pragma once

#include "IMovingAssistant.h"
#include "Subscriber.h"
#include "Map.h"
#include "CarStates.h"

#include<chrono>
#include <random>

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
			object::cars::TurnState canTurn(const CarConfig& config, const sf::Vector2f& pos);
			object::cars::TurnState turnEarlier(object::cars::TurnState turnState, object::cars::TurnState turnChanceState = TurnState::GO_FORWARD);
			object::cars::TurnState checkIfTurnIsOk(const sf::Vector2f& isBlocked, object::cars::TurnState turnSignal);

			base::Subscriber* m_pSubscriber;
			map::Map m_map;
			std::chrono::high_resolution_clock::time_point m_timeSinceLastCheck;
			std::random_device m_dev;
			std::mt19937 m_rng;
		};
	}
}