/**
 * @file DigitalInputModule.h
 * @author Diana Riscanu
 * @brief Module to control an individual digital sensor
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */
#ifndef _INCLUDE_ROU_DIGITAL_INPUT_MODULE_H_
#define _INCLUDE_ROU_DIGITAL_INPUT_MODULE_H_

#include "../Handles/DigitalInputHandle.h"
#include <CrcLib.h>

namespace rou
{

/**
 * @brief Module to control an individual digital sensor
 *
 */
class DigitalInputModule
{
public:
	/**
	 * @brief Create a new DigitalInputModule
	 *
	 * @param digitalInputHandle handle associated to the sensor
	 */
	DigitalInputModule(DigitalInputHandle* digitalInputHandle)
	{
		m_digitalInputHandle = digitalInputHandle;
	}

	/**
	 * @brief Get the status of the sensor
	 *
	 * @return true the sensor is in HIGH mode
	 * @return false the sensor is in LOW mode
	 */
	bool getStatus()
	{
		return m_digitalInputHandle->getValue();
	}

private:
	DigitalInputHandle* m_digitalInputHandle; ///< handle associated to the sensor
};

} // namespace rou

#endif // _INCLUDE_ROU_DIGITAL_INPUT_MODULE_H_
