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

namespace rou 
{

/**
 * @brief Digital Output Handle class
 * 
 * @extends Handle class
 */
class DigitalOutputHandle : public Handle 
{
public:
  /**
   * @brief Construct a new Digital Output Handle object
   * 
   * @param pin pin be used in this handle 
   */
  DigitalOutputHandle(uint8_t pin) 
  {
    m_pin = pin;
    Crc::CrcLib::SetDigitalPinMode(pin, Crc::OUTPUT);
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

#endif // _INCLUDE_ROU_DIGITAL_OUTPUT_HANDLE_H_
