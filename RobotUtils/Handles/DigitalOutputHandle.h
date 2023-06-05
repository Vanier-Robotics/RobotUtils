/**
 * @file DigitalOutputHandle.h
 * @author Jiucheng Zang
 * @brief Handle for managing digital actuators
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */
#ifndef _INCLUDE_ROU_DIGITAL_OUTPUT_HANDLE_H_
#define _INCLUDE_ROU_DIGITAL_OUTPUT_HANDLE_H_

#include "../Handle.h"
#include <CrcLib.h>

namespace rou
{

/**
 * @brief Handle for managing digital actuators
 *
 * @extends Handle
 */
class DigitalOutputHandle : public Handle
{
public:
	/**
	 * @brief Create a new DigitalOutputHandle
	 *
	 * @param pin the CrcLib pin to which the actuator is physically connected
	 */
	DigitalOutputHandle(uint8_t pin)
	{
		m_pin = pin;
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

protected:
	/**
	 * @brief Set the pin mode to output at initialization
	 *
	 */
	void setup() override
	{
		Crc::CrcLib::SetDigitalPinMode(m_pin, OUTPUT);
	}

private:
	uint8_t m_pin; ///< CrcLib pin to which this object is associated
};

} // namespace rou

#endif // _INCLUDE_ROU_DIGITAL_OUTPUT_HANDLE_H_
