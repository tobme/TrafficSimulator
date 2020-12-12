#pragma once

#include "ICamera.h"

#include "CarTracker.h"
#include "CarStates.h"

namespace object {
	namespace cars {
		class FrontCamera : ICamera
		{
		public:
			FrontCamera(const std::string& vehicleName, const object::tracker::ICarTrackerSP spCarTracker);
			~FrontCamera();

			bool objectAhead(Direction dir) const;
		private:
			std::string m_vehicleName;
			const object::tracker::ICarTrackerSP m_spCarTracker
		};
	}
}