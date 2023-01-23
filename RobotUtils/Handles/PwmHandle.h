/**
 * @file PwmHandle.h
 * @author Jiucheng Zang
 * @brief Pwm Handle class
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_PWM_HANDLE_H_
#define _INCLUDE_ROU_PWM_HANDLE_H_

#include "../Handle.h"
#include <CrcLib.h>

namespace rou
{

/**
 * @brief Pwm Handle class
 *
 * @extends Handle class
 */
class PwmHandle : public Handle
{
public:
	/**
	 * @brief Construct a new PwmHandle object
	 *
	 * @param pin pin be used in this handle
	 * @param minPulseWidth The minimum pulse width, in microseconds
	 * @param maxPulseWidth The maximum pulse width, in microseconds
	 * @param reverse Whether or not to invert the rotation direction of the servo
	 */
	PwmHandle(uint8_t pin, int minPulseWidth, int maxPulseWidth, bool reverse)
	{
		m_pin = pin;
		Crc::CrcLib::InitializePwmOutput(pin, minPulseWidth, maxPulseWidth, reverse);
	}

	/**
	 * @brief Return the pin be used in this handle
	 *
	 * @return uint8_t m_pin
	 */
	uint8_t getPin()
	{
		return m_pin;
	}

private:
	uint8_t m_pin;
};

} // namespace rou

#endif // _INCLUDE_ROU_PWM_HANDLE_H_
