/**
 * @file PwmHandle.h
 * @author Jiucheng Zang
 * @brief Handle for managing PWM-controlled actuators
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
 * @brief Handle for managing PWM-controlled actuators
 *
 * @extends Handle
 */
class PwmHandle : public Handle
{
public:
	/**
	 * @brief Create a new PwmHandle
	 *
	 * @param pin CrcLib pin to which the PWM connector is physically wired
	 * @param minPulseWidth the minimum pulse width, in microseconds
	 * @param maxPulseWidth the maximum pulse width, in microseconds
	 * @param reverse whether or not to invert the rotation direction of the servo
	 */
	PwmHandle(uint8_t pin, int minPulseWidth = 1000, int maxPulseWidth = 2000, bool isReversed = false)
	{
		m_pin			= pin;
		m_minPulseWidth	= minPulseWidth;
		m_maxPulseWidth	= maxPulseWidth;
		m_isReversed	= isReversed;
	}

	/**
	 * @brief Create a new PwmHandle
	 *
	 * @param pin CrcLib pin to which the PWM connector is physically wired
	 * @param reverse whether or not to invert the rotation direction of the servo
	 *
	 * Defaults to a pulse width ranging from 1000 to 2000 ms
	 */
	PwmHandle(uint8_t pin, bool isReversed)
	{
		m_pin			= pin;
		m_minPulseWidth	= 1000;
		m_maxPulseWidth	= 2000;
		m_isReversed	= isReversed;
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
	 * @brief Set the PWM pin at initialization
	 *
	 */
	void setup() override
	{
		Crc::CrcLib::InitializePwmOutput(m_pin, m_minPulseWidth, m_maxPulseWidth, m_isReversed);
	}

private:
	uint8_t	m_pin;           ///< CrcLib pin to which this object is associated
	int		m_minPulseWidth; ///< the minimum PWM pulse width for the connected actuator
	int		m_maxPulseWidth; ///< the maximum PWM pulse width for the connected actuator
	bool	m_isReversed;    ///< whether or not the signal should be reversed
};

} // namespace rou

#endif // _INCLUDE_ROU_PWM_HANDLE_H_
