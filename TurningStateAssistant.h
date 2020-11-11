#pragma once

#include "IMovingAssistant.h"
#include "Subscriber.h"
#include "Map.h"
#include "CarStates.h"

namespace object {
	namespace cars {

		class TurningStateAssistant : public IMovingAssistant {
		public:
			TurningStateAssistant(const std::string& name,
				base::Subscriber* pSubscriber,
				const map::Map& map);
			~TurningStateAssistant() = default;

			void updateState(const std::string& name, const CarConfig& config, const sf::Vector2f& pos) override;

		private:

			void Turn(const std::string& name,
				const CarConfig& config,
				const sf::Vector2f& pos,
				const sf::Vector2f& (::map::Map::* func)(const sf::Vector2f&, Direction) const,
				object::cars::DirectionState dirState);

			base::Subscriber* m_pSubscriber;
			map::Map m_map;
		};
	}
}