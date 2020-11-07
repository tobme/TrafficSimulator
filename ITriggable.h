#pragma once

#include<memory>

namespace base {
	class ITriggable {
	public:
		virtual ~ITriggable() = default;

		virtual void updateTrigger() = 0;
	};
	using ITriggableSP = std::shared_ptr<ITriggable>;
}