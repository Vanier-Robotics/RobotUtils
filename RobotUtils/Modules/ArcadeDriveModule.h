/**
 * @file ArcadeDriveModule.h
 * @author Diana Riscanu
 * @brief Module to drive the robot in arcade mode
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */
#ifndef _INCLUDE_ROU_ARCADE_DRIVE_MODULE_H_
#define _INCLUDE_ROU_ARCADE_DRIVE_MODULE_H_

#include "../Handles/PwmHandle.h"
#include <CrcLib.h>

namespace rou
{

/**
 * @brief Module to drive the robot in arcade mode
 *
 */
class ArcadeDriveModule
{
public:
	/**
	 * @brief Create a new ArcadeDriveModule
	 *
	 * @param frontLeftMotor handle associated to the front left motor
	 * @param backLeftMotor handle associated to the back left motor
	 * @param frontRightMotor handle associated to the front right motor
	 * @param backRightMotor handle associated to the back right motor
	 */
	ArcadeDriveModule(PwmHandle* frontLeftMotor, PwmHandle* backLeftMotor,
		PwmHandle* frontRightMotor, PwmHandle* backRightMotor)
	{
		m_frontLeftMotor	= frontLeftMotor;
		m_backLeftMotor		= backLeftMotor;
		m_frontRightMotor	= frontRightMotor;
		m_backRightMotor	= backRightMotor;
	}

	/**
	 * @brief Move the robot with the given directional channel values
	 *
	 * @param forwardChannel the front and back speed
	 * @param yawChannel the rotation speed (in either direction)
	 */
	virtual void move(int8_t forwardChannel, int8_t yawChannel)
	{
		if (m_frontLeftMotor->isAvailable() && m_backLeftMotor->isAvailable()
			&& m_frontRightMotor->isAvailable() && m_backRightMotor->isAvailable())
		{
			// don't use them before we made sure that all are available
			m_frontLeftMotor->use();
			m_backLeftMotor->use();
			m_frontRightMotor->use();
			m_backLeftMotor->use();

			Crc::CrcLib::MoveArcade(forwardChannel, yawChannel,
				m_frontLeftMotor->getPin(), m_backLeftMotor->getPin(),
				m_frontRightMotor->getPin(), m_backRightMotor->getPin());
		}
	}

private:
	PwmHandle* m_frontLeftMotor;  ///< handle associated to the front left motor
	PwmHandle* m_backLeftMotor;   ///< handle associated to the back left motor
	PwmHandle* m_frontRightMotor; ///< handle associated to the front right motor
	PwmHandle* m_backRightMotor;  ///< handle associated to the back right motor
};

} // namespace rou

#endif // _INCLUDE_ROU_ARCADE_DRIVE_MODULE_H_
