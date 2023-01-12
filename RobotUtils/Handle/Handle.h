/**
 * @file Handle.h
 * @author Jiucheng Zang
 * @brief Handle class
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_HANDLE_H_
#define _INCLUDE_ROU_HANDLE_H_

#include <stdint.h>

namespace rou {

class Handle {
protected:
  bool available;

public:
  Handle() : available(true) {} // { available = true; }

  bool isAvailable() { return available; }

  void use() { available = true; }

  void release() { available = false; }
};

} // namespace rou
#endif // _INCLUDE_ROU_HANDLE_H_