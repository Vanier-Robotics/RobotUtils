/**
 * @file MotorModule.h
 * @author Diana Riscanu
 * @brief MotorModule class
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_MOTOR_MODULE_H_
#define _INCLUDE_ROU_MOTOR_MODULE_H_

#include "../Handles/PwmHandle.h"
#include "../Module.h"

namespace rou
{

class MotorModule : public Module
{
public:
	MotorModule(PwmHandle& motorHandle)
	{
		m_motorHandle = &motorHandle;
	}

	void motorStatus(int8_t motorSpeed)
	{
		CrcLib::SetPwmOutput(m_motorHandle, motorSpeed);
	}

	void setup()
	{
		CrcLib::InitializePwmOutput(motorHandle);
	}

private:
	PwmHandle* m_motorHandle;
};

} // namespace rou

#endif // _INCLUDE_ROU_MOTOR_MODULE_H_
