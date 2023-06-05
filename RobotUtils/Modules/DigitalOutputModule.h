/**
 * @file DigitalOutputModule.h
 * @author Diana Riscanu
 * @brief Module to control an individual digital actuator
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */
#ifndef _INCLUDE_ROU_DIGITAL_OUTPUT_MODULE_H_
#define _INCLUDE_ROU_DIGITAL_OUTPUT_MODULE_H_

#include "../Handles/DigitalOutputHandle.h"
#include <CrcLib.h>

namespace rou
{

/**
 * @brief Module to control an individual digital actuator
 *
 */
class DigitalOutputModule
{
public:
	/**
	 * @brief Create a new DigitalOutputModule
	 *
	 * @param digitalOuptutHandle handle associated to the actuator
	 */
	DigitalOutputModule(DigitalOutputHandle* digitalOuptutHandle)
	{
		m_digitalOutputHandle = digitalOuptutHandle;
	}

	/**
	 * @brief Set the status of the actuator
	 *
	 * @param isHigh true of HIGH and false for LOW
	 */
	void setStatus(bool isHigh)
	{
		if (m_digitalOutputHandle->use())
		{
			Crc::CrcLib::SetDigitalOutput(m_digitalOutputHandle->getPin(), (isHigh ? HIGH : LOW));
		}
	}

private:
	DigitalOutputHandle* m_digitalOutputHandle; ///< handle associated to the actuator
};

} // namespace rou

#endif // _INCLUDE_ROU_DIGITAL_OUTPUT_MODULE_H_
