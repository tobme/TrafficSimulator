#pragma once

#include "CarStates.h"

#include <SFML/Graphics.hpp>

namespace object {
	namespace cars {
		class ICamera
		{
		public:
			virtual ~ICamera() = default;

			virtual bool objectAhead(const sf::Vector2f& myPos, Direction dir) const = 0;
		};

		using ICameraSP = std::shared_ptr<ICamera>;
		using ICameraUP = std::unique_ptr<ICamera>;
	}
}