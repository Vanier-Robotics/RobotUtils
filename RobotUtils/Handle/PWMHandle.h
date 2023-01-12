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
#include <stdint.h>

namespace rou {
class PWMHandle : public Handle {
private:
  uint8_t port;
  bool isOutput;
  bool isReversed;

public:
  PWMHandle(uint8_t _port, bool _isOutput, bool _isReversed) {
    port = _port;
    isOutput = _isOutput;
    isReversed = _isReversed;
  }

  uint8_t getport() { return port; }

  bool getisOutput() { return isOutput; }

  // bool status() { return isReversed; }

  // void use() { isReversed = true; }

  // void release() { isReversed = false; }
};

} // namespace rou
#endif // _INCLUDE_ROU_PWM_HANDLE_H_