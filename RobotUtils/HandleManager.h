/**
 * @file HandleManager.h
 * @author Jiucheng Zang
 * @brief Manages the use of all handles
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */
#ifndef _INCLUDE_ROU_HANDLE_MANAGER_H_
#define _INCLUDE_ROU_HANDLE_MANAGER_H_

#include "Handle.h"
#include <ArduinoExtra.h>

namespace rou
{

/**
 * @brief HandleManager class, which controls the use of all individual handles
 *
 */
class HandleManager
{
public:
	/**
	 * @brief Release all the handles stored in the handle manager
	 *
	 */
	void releaseAll()
	{
		for (int i = 0; i < m_handles.getSize(); i++)
		{
			m_handles[i]->release();
		}
	}

	/**
	 * @brief Add different Handle into Handle Manager Class
	 *
	 * @param handle a pointer to any handle
	 *
	 * All handles must be added to the handle manager
	 */
	void addHandle(Handle* handle)
	{
		m_handles.pushBack(handle);
		handle->setup();
	}

private:
	aex::Vector<Handle*> m_handles; ///< Vector of ALL handles used by the robot
};

} // namespace rou

#endif // _INCLUDE_ROU_HANDLE_MANAGER_H_
