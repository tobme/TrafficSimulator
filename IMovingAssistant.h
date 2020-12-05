#pragma once

#include "IObject.h"
#include "CarStates.h"

#include <SFML/Graphics.hpp>

namespace object {
	namespace cars {
		class IMovingAssistant : public base::IObject
		{
		public:
			using IObject::IObject;

			virtual ~IMovingAssistant() = default;

			virtual void updateState(const std::string& name, const CarConfig& config, const sf::Vector2f& pos) = 0;
		};

		using IMovingAssistantSP = std::shared_ptr<IMovingAssistant>;
	}
}