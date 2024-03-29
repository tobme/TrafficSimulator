#pragma once

#include "ITriggable.h"
#include "IDrawableObject.h"
//#include "MovableEvents.h"
#include "VehicleEventHandler.h"
#include "Subscriber.h"
#include "CarStates.h"
#include "FrontCamera.h"

#include "TextureId.h"

namespace object {
	namespace cars {

		class MovableObject : public base::ITriggable
			, public base::RectangleObject
			, public base::VehicleEventHandler
		{
		public:
			MovableObject(const std::string& name,
				const base::TextureId& textureName,
				base::Subscriber* pSubscriber,
				const sf::Vector2f& pos,
				unsigned int drawingorder,
				ICameraSP spCamera);

			virtual ~MovableObject();

			void updateTrigger()  override;

			void doHandleEvent(const event::VehicleMovedEvents& e) override;
			void doHandleEvent(const event::VehicleDirectionEvent& e) override;
			void doHandleEvent(const event::VehicleSetTurnEvent& e) override;
			void doHandleEvent(const event::VehiclePedalEvent& e) override;
			void doHandleEvent(const event::VehicleTurningEvent& e) override;
		private:

			void move();

			void checkFrontCamera();

			void updateCar();

			void updateCarSpeed();

			float getTurningSpeed();

			bool checkIfFinishedTurning();

			void setNewDirection();

			void setRotationPos();

			CarConfig m_config;
			base::Subscriber* m_pSubscriber;
			float m_speed;
			float m_turningSpeed;
			float m_rotationAngle;
			ICameraSP m_spCamera;
		};
	}
}


