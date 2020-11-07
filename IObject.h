#pragma once

#include<memory>
#include<string>

namespace base {
	class IObject
	{
	public:
		IObject(const std::string& name)
			: m_name(name)
		{
		}

		virtual ~IObject() = default;

		std::string getName() { return m_name; }

		template<typename type>
		bool checkIfType() { return typeid(*this) == typeid(type); }
	private:
		std::string m_name;
		
	};
}