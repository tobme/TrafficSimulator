#pragma once

#include "IMovingAssistant.h"

#include "IObject.h"
#include "CarStates.h"

namespace object {
	class IMovingAssistantHandler : public base::IObject {
	public:
		using IObject::IObject;

		virtual ~IMovingAssistantHandler() = default;

		virtual void addAssistant(cars::IMovingAssistantSP assistant) = 0;

		virtual void updateAssistants(const std::string& name, const cars::CarConfig& config, const sf::Vector2f& pos) = 0;
	};

	using IMovingAssistantHandlerSP = std::shared_ptr<IMovingAssistantHandler>;
	using IMovingAssistantHandlerUP = std::unique_ptr<IMovingAssistantHandler>;
}