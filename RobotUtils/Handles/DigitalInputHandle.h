/**
 * @file DigitalInputHandle.h
 * @author Jiucheng Zang
 * @brief Handle for managing digital sensors
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */
#ifndef _INCLUDE_ROU_DIGITAL_INPUT_HANDLE_H_
#define _INCLUDE_ROU_DIGITAL_INPUT_HANDLE_H_

#include "../Handle.h"
#include <CrcLib.h>

namespace rou
{

/**
 * @brief Handle for managing digital sensors
 *
 * @extends Handle
 */
class DigitalInputHandle : public Handle
{
public:
	/**
	 * @brief Create a new DigitalInputHandle
	 *
	 * @param pin the CrcLib pin to which the sensor is physically connected
	 */
	DigitalInputHandle(uint8_t pin)
	{
		m_pin = pin;
	}

	/**
	 * @brief Get the state of the digital sensor
	 *
	 * @return true the sensor is in HIGH mode
	 * @return false the sensor is in LOW mode
	 */
	bool getValue()
	{
		return (Crc::CrcLib::GetDigitalInput(m_pin) == HIGH);
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
	 * @brief Set the pin mode to input at initialization
	 *
	 */
	void setup() override
	{
		Crc::CrcLib::SetDigitalPinMode(m_pin, INPUT);
	}

private:
	uint8_t m_pin; ///< CrcLib pin to which this object is associated
};

} // namespace rou

#endif // _INCLUDE_ROU_DIGITAL_INPUT_HANDLE_H_
