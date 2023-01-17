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

namespace rou 
{
  
/**
 * @brief Handle Manager class
 * 
 * @extends Handle class
 */
class HandleManager : public Handle
{
public:
  /**
   * @brief Construct a new Handle Manager object
   * 
   */
  HandleManager() 
  {
  }

  /**
   * @brief Release all the Handle in the Handle Manager
   * 
   */
  void releaseAll() {
    for (int i; i < m_handles.size(); i++) {
      m_handles[i]->release();
    }
  }

  /**
   * @brief Add different Handle into Handle Manager Class
   * 
   * @param handle Different types of handle
   */
  void addHandle(Handle *handle) 
  { 
    m_handles.push_back(handle); 
  }

private:
  std::vector<Handle *> m_handles;
};

} // namespace rou

#endif // _INCLUDE_ROU_HANDLE_MANAGER_H_
