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

namespace rou 
{

/**
 * @brief Digital Input Handle class
 * 
 * @extends Handle class
 */
class DigitalInputHandle : public Handle 
{
  public:
  /**
   * @brief Construct a new Digital Input Handle object
   * 
   * @param pin pin be used in this handle 
   */
    DigitalInputHandle(uint8_t pin) 
    {
      m_pin = pin;
      Crc::CrcLib::SetDigitalPinMode(pin, Crc::INPUT);
    }

    /**
     * @brief Check if Digitial Input in HIGH mode (True -> HIGH, False -> LOW)
     * 
     * @return bool (Crc::CrcLib::GetDigitalInput(pin) == Crc::HIGH) 
     */
    bool getValue() 
    { 
      return (Crc::CrcLib::GetDigitalInput(pin) == Crc::HIGH); 
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

#endif // _INCLUDE_ROU_DIGITAL_INPUT_HANDLE_H_
