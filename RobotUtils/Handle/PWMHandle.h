/**
 * @file PWMHHandle.h
 * @author Jiucheng Zang
 * @brief Handle class
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_HANDLE_H_
#define _INCLUDE_ROU_HANDLE_H_

#include "Handle.h"
#include <stdint.h>

namespace rou {

class PWMHandle : public Handle {
protected:
  uint8_t port;
  bool isOutput;
  bool isReversed;

public:
  PWMHandle(uint8_t port, bool isOutput, bool isReversed) {
    this->port = port;
    this->isOutput = isOutput;
    this->isReversed = isReversed;
  }

  uint8_t getport() { return port; }

  bool getisOutput() { return isOutput; }

  bool status() { return isReversed; }

  void use() { this->isReversed = true; }

  void release() { this->isReversed = false; }
};

} // namespace rou
#endif // _INCLUDE_ROU_HANDLE_H_