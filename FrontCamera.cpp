
#include "FrontCamera.h"

using namespace ::object::tracker;

namespace object {
	namespace cars {
		FrontCamera::FrontCamera(const std::string& vehicleName, const ICarTrackerSP spCarTracker)
			: m_vehicleName(vehicleName), m_spCarTracker(spCarTracker)
		{
		}
		FrontCamera::~FrontCamera() = default;

		bool FrontCamera::objectAhead(Direction dir) const
		{

		}
	}
}