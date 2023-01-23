/**
 * @file Handle.h
 * @author Jiucheng Zang
 * @brief Handle class
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_HANDLE_H_
#define _INCLUDE_ROU_HANDLE_H_

namespace rou
{

/**
 * @brief Handle class
 *
 */
class Handle
{
public:
	/**
	 * @brief Check if Handle is available for now
	 *
	 * @return bool m_available value if available
	 */
	bool isAvailable()
	{
		return m_isAvailable;
	}

	/**
	 * @brief Check if this handle be used. If not add it up and return true, else return false do nothing.
	 *
	 * @return bool temp_available value if use success
	 */
	bool use()
	{
		bool t_wasAvailable = (isAvailable()) ? true : false;
		m_isAvailable = false;

		return t_wasAvailable;
	}

	/**
	 * @brief Release this handle
	 *
	 */
	void release()
	{
		m_isAvailable = true;
	}

protected:
	bool m_isAvailable = true;
};

} // namespace rou

#endif // _INCLUDE_ROU_HANDLE_H_
