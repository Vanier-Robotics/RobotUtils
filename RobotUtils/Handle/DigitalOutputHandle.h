/**
 * @file DigitalOutput.h
 * @author Jiucheng Zang
 * @brief Digital Output Handle
 * @version 0.1
 * @date 2023-01-12
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 *
 */

#ifndef _INCLUDE_ROU_DIGITAL_OUTPUT_HANDLE_H_
#define _INCLUDE_ROU_DIGITAL_OUTPUT_HANDLE_H_

#include "Handle.h"
#include <CrcLib.h>
#include <stdint.h>

namespace rou {
class DigitalOutputHandle : public Handle {
private:
  uint8_t m_pin;

public:
  DigitalOutputHandle(uint8_t pin) {
    m_pin = pin;
    Crc::CrcLib::SetDigitalPinMode(pin, Crc::INPUT);
  }

  //   void setValue(bool value) {
  //     Crc::CrcLib::SetDigitalOutput(m_pin, (value) ? Crc::HIGH : Crc::LOW);
  //   }
  uint8_t getPin() { return m_pin; }
}
} // namespace rou
#endif // _INCLUDE_ROU_DIGITAL_OUTPUT_HANDLE_H_