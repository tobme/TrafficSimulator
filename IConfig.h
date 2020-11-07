
#pragma once

#include "Map.h"

namespace base {
	class IConfig
	{
	public:
		virtual ~IConfig() = default;

		virtual void setMap(const ::map::Map& map) = 0;
		virtual const ::map::Map& getMap() const = 0;

	};

	using IConfigSP = std::shared_ptr<IConfig>;
}