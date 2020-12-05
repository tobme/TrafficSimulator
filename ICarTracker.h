#pragma once

#include "IObject.h"

#include<memory>

namespace object {
	namespace tracker {
		class ICarTracker : public base::IObject {
		public:
			using IObject::IObject;

			virtual ~ICarTracker() = default;
		};

		using ICarTrackerSP = std::shared_ptr<ICarTracker>;
	}
}