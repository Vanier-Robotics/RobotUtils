/**
 * @file AnalogHandle.h
 * @author Jiucheng Zang
 * @brief Analog Handle
 * @version 0.1
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 *
 */

#include "Handle.h"
#include <CrcLib.h>

#ifndef _INCLUDE_ROU_ANALOG_HANDLE_H_
#define _INCLUDE_ROU_ANALOG_HANDLE_H_
namespace rou {
class AnalogHandle : public Handle {
private:
  uint8_t m_pin;

public:
  AnalogHandle(uint8_t pin) { m_pin = pin; }
  int getValue(){return (Crc::CrcLib::GetAnalogInput(m_pin))} uint8_t getPin() {
    return m_pin;
  }
}
} // namespace rou
#endif // _INCLUDE_ROU_ANALOG_HANDLE_H_