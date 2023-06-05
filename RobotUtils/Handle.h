/**
 * @file Handle.h
 * @author Jiucheng Zang
 * @brief Base Handle class
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */
#ifndef _INCLUDE_ROU_HANDLE_H_
#define _INCLUDE_ROU_HANDLE_H_

namespace rou
{

class HandleManager;

/**
 * @brief Base Handle class
 *
 */
class Handle
{
public:
	friend class HandleManager;

	/**
	 * @brief Check if Handle is currently available
	 *
	 * @return true the handle is available
	 * @return false the handle has already been used
	 */
	bool isAvailable()
	{
		return m_isAvailable;
	}

	/**
	 * @brief Check if this handle be used. If not, switch it to unavailable return true, else return false do nothing.
	 *
	 * @return true the handle can be used
	 * @return false the handle has been previously used and is no longer avaiable
	 */
	bool use()
	{
		bool t_wasAvailable = isAvailable();
		m_isAvailable = false;

		return t_wasAvailable;
	}

	/**
	 * @brief Release this handle, making it available again
	 *
	 */
	void release()
	{
		m_isAvailable = true;
	}

protected:
	/**
	 * @brief Setup the handle (ie. initialize the pin, etc.)
	 *
	 * Some handles do not require any setup, which is why the base defaults to an empty method
	 */
	virtual void setup()
	{
	}

	bool m_isAvailable = true; ///< stores whether the handle can be used or has already been used
};

} // namespace rou

#endif // _INCLUDE_ROU_HANDLE_H_
