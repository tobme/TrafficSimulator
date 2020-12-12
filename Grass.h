#pragma once

#include "Prop.h"

#include<iostream>

namespace shapes {

	class Grass : public object::RectangleProp
	{
	public:
		Grass(const std::string& name, const sf::Vector2f& pos);
		~Grass() = default;
	private:
		static unsigned int counter;
	};
}