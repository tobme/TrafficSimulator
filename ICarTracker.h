#pragma once

#include "IObject.h"

#include<memory>

namespace object {
	namespace tracker {
		class ICarTracker : public base::IObject {
		public:
			using IObject::IObject;

			virtual ~ICarTracker() = default;

			virtual const sf::Vector2f& getPosByName(const std::string& name) const = 0;
			virtual bool isVehicleWithinArea(const sf::Vector2f& topLeftCorner, const sf::Vector2f& bottomRightCorner) const = 0;
		};

		using ICarTrackerSP = std::shared_ptr<ICarTracker>;
		using ICarTrackerUP = std::unique_ptr<ICarTracker>;
	}
}