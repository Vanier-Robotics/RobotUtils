/**
 * @file DigitalInputHandle.h
 * @author Jiucheng Zang
 * @brief Digital Input Handle
 * @version 0.1
 * @date 2023-01-12
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 *
 */

#ifndef _INCLUDE_ROU_DIGITAL_INPUT_HANDLE_H_
#define _INCLUDE_ROU_DIGITAL_INPUT_HANDLE_H_

#include "Handle.h"
#include <CrcLib.h>
#include <stdint.h>

namespace rou {
class DigitalInputHandle : public Handle {
private:
  uint8_t m_pin;

public:
  DigitalInputHandle(uint8_t pin, bool _isReversed) { m_pin = pin; }
  bool getValue() { return (Crc::CrcLib::GetDigitalInput(pin) == Crc::HIGH); }
  uint8_t getPin() { return m_pin; }
}
} // namespace rou
#endif // _INCLUDE_ROU_DIGITAL_INPUT_HANDLE_H_