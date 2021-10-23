#pragma once

#include "ICamera.h"

#include "CarTracker.h"
#include "CarStates.h"

namespace object {
	namespace cars {
		class FrontCamera : public ICamera
		{
		public:
			FrontCamera(const std::string& vehicleName, const object::tracker::ICarTracker* pCarTracker);
			~FrontCamera();

			/* Controls if an object is ahead.
			* 
			* Checks for 100 pixels.
			* 
			* @returns true if an object if found, otherwise, false.
			*/
			bool objectAhead(const sf::Vector2f& myPos, Direction dir) const override;
		private:
			std::string m_vehicleName;
			const object::tracker::ICarTracker* m_pCarTracker;
		};
	}
}