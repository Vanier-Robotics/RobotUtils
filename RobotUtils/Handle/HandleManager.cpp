/**
 * @file LEDModule.h
 * @author Jiucheng Zang
 * @brief HandleManager class
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_LED_MODULE_H_
#define _INCLUDE_ROU_LED_MODULE_H_

#include "ArduinoExtra.h"
#include "Handle.h"
#include <CrcLib.h>
#include <cstdint>

namespace rou {
class Handle_Manager {
private:
  vector<Handle> handles;

public:
  Handle_Manager() {}

  void to_string() {
    for (Handle handle : handles) {
      cout << "\nStatus: ";
      cout << handle.isAvailable();
      cout << "\n\n";
    }
  }

  void release_all() {
    for (Handle handle : handles) {
      handle.release();
    }
  }

  void addHandle(Handle handle) { handles.push_back(handle); }
};
} // namespace rou

#endif // _INCLUDE_ROU_LED_MODULE_H_
