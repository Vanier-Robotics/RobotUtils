/**
 * @file ModeManager.h
 * @author Elisa Moscato
 * @brief Handles all the modes and allows to switch between them
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */
#ifndef _INCLUDE_ROU_MODE_MANAGER_H_
#define _INCLUDE_ROU_MODE_MANAGER_H_

#include "Mode.h"

namespace rou
{

/**
 * @brief Updates the modes and switches between them when necessary
 *
 */
class ModeManager
{
public:
	/**
	 * @brief Update the current state and load the next mode if needed
	 *
	 * @param dt time elapsed (in seconds) since the last update
	 */
	void update(float dt)
	{
		if (m_currentMode)
		{
			m_currentMode->update(dt);
		}

		if (m_nextMode)
		{
			if (m_currentMode)
			{
				m_currentMode->unload();
			}

			m_currentMode = m_nextMode;
			m_currentMode->load();
			m_nextMode = nullptr;
		}
	}

	/**
	 * @brief Switch to the given mode at the end of the current update
	 *
	 * @param nextMode pointer to the next mode to be loaded
	 */
	void changeMode(Mode* nextMode)
	{
		m_nextMode = nextMode;
	}

private:
	Mode* m_nextMode	= nullptr; ///< pointer to the next mode to be loaded (set to nullptr when we do not want to switch)
	Mode* m_currentMode	= nullptr; ///< pointer to the current mode that we need to update
};

} // namespace rou

#endif // _INCLUDE_ROU_MODE_MANAGER_H_
