#pragma once

namespace base {
	template <typename ...inheritance>
	class MultipleEventWrapper : public inheritance...
	{
	public:
		MultipleEventWrapper() {}
		~MultipleEventWrapper() = default;
	};
}