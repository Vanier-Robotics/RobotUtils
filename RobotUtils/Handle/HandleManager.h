/**
 * @file HandleManager.h
 * @author Jiucheng Zang
 * @brief Handle Manager class
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_HANDLE_MANAGER_H_
#define _INCLUDE_ROU_HANDLE_MANAGER_H_

#include "Handle.h"
#include <cstdint>
#include <vector>

namespace rou {
class HandleManager : public Handle {
private:
  std::vector<Handle> handles;

public:
  HandleManager() {}

  void release_all() {
    for (Handle handle : handles) {
      handle.release();
    }
  }

  void addHandle(Handle handle) { handles.push_back(handle); }
};
} // namespace rou

#endif // _INCLUDE_ROU_HANDLE_MANAGER_H_
