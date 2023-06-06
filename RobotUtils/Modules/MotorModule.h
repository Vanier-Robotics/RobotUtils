/**
 * @file MotorModule.h
 * @author Diana Riscanu
 * @brief Module to control an individual motor or servomotor
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */
#ifndef _INCLUDE_ROU_MOTOR_MODULE_H_
#define _INCLUDE_ROU_MOTOR_MODULE_H_

#include "../Handles/PwmHandle.h"
#include <CrcLib.h>

namespace rou
{

/**
 * @brief Module to control an individual motor or servomotor
 *
 */
class MotorModule
{
public:
	/**
	 * @brief Create a new MotorModule
	 *
	 * @param motorHandle handle associated to the motor
	 */
	MotorModule(PwmHandle* motorHandle)
	{
		m_motorHandle = motorHandle;
	}

	/**
	 * @brief Set the speed or angle of the associated motor
	 *
	 * @param motorSpeed the value that will be directly sent via a PWM signal
	 *
	 * This will not do anything if the handle has previously been used
	 */
	void setSpeed(int8_t motorSpeed)
	{
		if (m_motorHandle->use())
		{
			Crc::CrcLib::SetPwmOutput(m_motorHandle->getPin(), motorSpeed);
		}
	}

private:
	PwmHandle* m_motorHandle; ///< handle associated to the motor
};

} // namespace rou

#endif // _INCLUDE_ROU_MOTOR_MODULE_H_
