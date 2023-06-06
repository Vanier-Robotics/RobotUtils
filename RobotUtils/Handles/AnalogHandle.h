/**
 * @file AnalogHandle.h
 * @author Jiucheng Zang
 * @brief Handle for managing analog sensors
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */
#ifndef _INCLUDE_ROU_ANALOG_HANDLE_H_
#define _INCLUDE_ROU_ANALOG_HANDLE_H_

#include "../Handle.h"
#include <CrcLib.h>

namespace rou
{

/**
 * @brief Handle for managing analog sensors
 *
 * @extends Handle
 */
class AnalogHandle : public Handle
{
public:
	/**
	 * @brief Create a new AnalogHandle
	 *
	 * @param pin the CrcLib pin number to which the sensor is physically connected
	 */
	AnalogHandle(uint8_t pin)
	{
		m_pin = pin;
	}

	/**
	 * @brief Get the value of the input
	 *
	 * @return int value in the range [0, 1023] where 0 means 0V are applied on the pin and 1023 means 7.5V are applied
	 */
	unsigned int getValue()
	{
		return Crc::CrcLib::GetAnalogInput(m_pin);
	}

	/**
	 * @brief Get the CrcLib pin to which this object is associated
	 *
	 * @return uint8_t the CrcLib pin number
	 */
	uint8_t getPin()
	{
		return m_pin;
	}

private:
	uint8_t m_pin; ///< CrcLib pin to which this object is associated
};

} // namespace rou

#endif // _INCLUDE_ROU_ANALOG_HANDLE_H_
