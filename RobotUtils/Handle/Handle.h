/**
 * @file Handle.h
 * @author Jiucheng Zang
 * @brief Handle class
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_HANDLE_H_
#define _INCLUDE_ROU_HANDLE_H_

namespace rou {

class Handle {
protected:
  bool m_available = true;

public:
  bool isAvailable() { return m_available; }

  bool use() {
    bool temp_available = (isAvailable()) ? true : false;
    m_available = false;
    return temp_available;
  }

  void release() { m_available = true; }
};

} // namespace rou
#endif // _INCLUDE_ROU_HANDLE_H_