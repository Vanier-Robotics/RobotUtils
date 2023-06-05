/**
 * @file Mode.h
 * @author Elisa Moscato
 * @brief Base  mode class
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */
#ifndef _INCLUDE_ROU_MODE_H_
#define _INCLUDE_ROU_MODE_H_

#include <ArduinoExtra.h>
#include "Controller.h"

namespace rou
{

class ModeManager;

/**
 * @brief Base Mode class (AKA a state)
 *
 */
class Mode
{
public:
	/**
	 * @brief Update the mode by fetching inputs and activating actuators accodringly
	 *
	 * @param dt time (in seconds) since the last update
	 */
	virtual void update(float dt) = 0;

	/**
	 * @brief Load the mode, reinitializing any state related to that mode
	 *
	 * This method is called on a mode that is about to be switch as the current mode
	 */
	virtual void load() = 0;

	/**
	 * @brief Unload the mode, stopping reseting any variables or actuators
	 *
	 * This method is called on the current mode when a new mode is about to replace it
	 */
	virtual void unload() = 0;

protected:
	Controller			m_controller; ///< controller class specific to the mode and defining all of its bindings
	static ModeManager&	ModeManager;  ///< reference to the mode manager to be able to switch to another mode
};

} // namespace rou

#endif // _INCLUDE_ROU_MODE_H_
