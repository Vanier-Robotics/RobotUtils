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
#include <vector>

namespace rou {
class HandleManager : public Handle {
private:
  std::vector<Handle *> m_handles;

public:
  HandleManager() {}

  void releaseAll() {
    for (int i; i < m_handles.size(); i++) {
      m_handles[i]->release();
    }
  }

  void addHandle(Handle *handle) { m_handles.push_back(handle); }
};
} // namespace rou

#endif // _INCLUDE_ROU_HANDLE_MANAGER_H_
