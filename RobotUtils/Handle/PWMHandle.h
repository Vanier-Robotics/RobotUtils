/**
 * @file PWMHHandle.h
 * @author Jiucheng Zang
 * @brief PWM Handle class
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_PWM_HANDLE_H_
#define _INCLUDE_ROU_PWM_HANDLE_H_

#include "Handle.h"
#include <CrcLib.h>

namespace rou {
class PWMHandle : public Handle {
private:
  uint8_t m_pin;

public:
  PWMHandle(uint8_t pin, int minPulseWidth, int maxPulseWidth, bool reverse) {
    m_pin = pin;
    Crc::CrcLib::InitializePwmOutput(pin, minPulseWidth, maxPulseWidth, reverse)
  }
  uint8_t getPin() { return m_pin; }
};

} // namespace rou
#endif // _INCLUDE_ROU_PWM_HANDLE_H_