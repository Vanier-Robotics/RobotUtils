/**
 * @file TankDriveModule.h
 * @author Diana Riscanu
 * @brief Module to drive the robot in tank mode
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */
#ifndef _INCLUDE_ROU_TANK_DRIVE_MODULE_H_
#define _INCLUDE_ROU_TANK_DRIVE_MODULE_H_

#include "../Handles/PwmHandle.h"
#include <CrcLib.h>

namespace rou
{

/**
 * @brief Module to drive the robot in tank mode
 *
 */
class TankDriveModule
{
public:
	/**
	 * @brief Create a new TankDriveModule
	 *
	 * @param frontLeftMotor handle associated to the front left motor
	 * @param backLeftMotor handle associated to the back left motor
	 * @param frontRightMotor handle associated to the front right motor
	 * @param backRightMotor handle associated to the back right motor
	 */
	TankDriveModule(PwmHandle* frontLeftMotor, PwmHandle* backLeftMotor,
		PwmHandle* frontRightMotor, PwmHandle* backRightMotor)
	{
		m_frontLeftMotor	= frontLeftMotor;
		m_backLeftMotor		= backLeftMotor;
		m_frontRightMotor	= frontRightMotor;
		m_backRightMotor	= backRightMotor;
	}

	/**
	 * @brief Move the robot with the given channel values
	 *
	 * @param leftChannel the power given to the left-sided motors
	 * @param rightChannel the power given to the right-sided motors
	 *
	 * The robot will not move if any of the motor handles has been used previously
	 */
	virtual void move(int8_t leftChannel, int8_t rightChannel)
	{
		if (m_frontLeftMotor->isAvailable() && m_backLeftMotor->isAvailable()
			&& m_frontRightMotor->isAvailable() && m_backRightMotor->isAvailable())
		{
			// don't use them before we made sure that all are available
			m_frontLeftMotor->use();
			m_backLeftMotor->use();
			m_frontRightMotor->use();
			m_backLeftMotor->use();

			Crc::CrcLib::MoveTank(leftChannel, rightChannel,
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

} //namespace rou

#endif // _INCLUDE_ROU_TANK_DRIVE_MODULE_H_
