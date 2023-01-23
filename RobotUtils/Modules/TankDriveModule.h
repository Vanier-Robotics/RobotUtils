/**
 * @file TankDriveModule.h
 * @author Diana Riscanu
 * @brief TankDriveModule class
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_TANK_DRIVE_MODULE_H_
#define _INCLUDE_ROU_TANK_DRIVE_MODULE_H_

#include "../Handles/PwmHandle.h"
#include "../Module.h"

namespace rou
{

class TankDriveModule : public Module
{
public:
	TankDriveModule(PwmHandle& frontLeftMotor, PwmHandle& backLeftMotor,
		PwmHandle& frontRightMotor, PwmHandle& backRightMotor)
	{
		m_frontLeftMotor	= &frontLeftMotor;
		m_backLeftMotor		= &backLeftMotor;
		m_frontRightMotor	= &frontRightMotor;
		m_backRightMotor	= &backRightMotor;
	}

	virtual void move(int8_t leftChannel, int8_t rightChannel)
	{
		if (m_frontLeftMotor->isAvailable() && m_backLeftMotor->isAvailable()
			&& m_frontRightMotor->isAvailable() && m_backRightMotor->isAvailable())
		{
			m_frontLeftMotor->use();
			m_backLeftMotor->use();
			m_frontRightMotor->use();
			m_backLeftMotor->use();

			CrcLib::MoveTank(leftChannel, rightChannel,
				frontLeftMotor, backLeftMotor, frontRightMotor, backRightMotor);
		}
	}

private:
	PwmHandle* m_frontLeftMotor;
	PwmHandle* m_backLeftMotor;
	PwmHandle* m_frontRightMotor;
	PwmHandle* m_backRightMotor;
};

} //namespace rou

#endif // _INCLUDE_ROU_TANK_DRIVE_MODULE_H_