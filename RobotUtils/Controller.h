/**
 * @file Controller.h
 * @author Gabriel Saberian
 * @brief Controller class used to manage all sorts of inputs
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */
#include "Handles/AnalogHandle.h"
#include "Handles/DigitalInputHandle.h"
#include "Handles/EncoderHandle.h"
#include <ArduinoExtra.h>
#include <CrcLib.h>

#ifndef _INCLUDE_ROU_CONTROLLER_H_
#define _INCLUDE_ROU_CONTROLLER_H_

namespace rou
{

/**
 * @brief Controller class, which can be used to manage the various inputs for a robot
 *
 */
class Controller
{
	/**
	 * @brief Structure that contains the variables and function for a button binding
	 *
	 * The boolean parameter of the callback function determines whether the button
	 * was pressed (true) or released (false)
	 */
	struct ButtonBinding
	{
		Crc::BUTTON 				buttonID; ///< variable of type BUTTON (from CrcLib) that stores a specific button
		aex::Function<void(bool)>	callback; ///< pointer to the function called when the binding changes state

		bool lastValue; ///< keeps track of the previous state of the button
	};

	/**
	 * @brief Structure that contains the variables and function for a toggle binding
	 *
	 * The boolean parameter of the callback function determines whether the button
	 * has switched to being toggled on (true) or off (false)
	 */
	struct ToggleButtonBinding
	{
		Crc::BUTTON	              buttonID; ///< variable of type BUTTON (from CrcLib) that stores a specific button
		aex::Function<void(bool)> callback; ///< pointer to the function called when the binding changes state

		bool isToggled; ///< stores the state of the binding
		bool lastValue; ///< keeps track of the previous state of the button
	};

	/**
	 * @brief Structure that contains the variables and functions for a digital sensor binding
	 *
	 * The boolean parameter of the callback function determines whether the sensor
	 * returns a HIGH (true) or a LOW (false)
	 */
	struct DigitalSensorBinding
	{
		DigitalInputHandle&       handle;   ///< reference to the handle associated with the sensor
		aex::Function<void(bool)> callback; ///< pointer to the function called when the binding changes state

		bool lastValue; ///< keeps track of the previous state of the sensor
	};

public:
	/**
	 * @brief Setup a callback function for a button binding
	 *
	 * @param buttonID CrcLib BUTTON to which the binding is assigned
	 * @param callback pointer to the function that will be called when this binding is updated
	 */
	void bindButton(Crc::BUTTON buttonID, aex::Function<void(bool)> callback)
	{
		m_buttonBindings.pushBack({buttonID, callback, false});
	}

	/**
	 * @brief Setup a callback function for a toggle binding
	 *
	 * @param buttonID CrcLib BUTTON to which the binding is assigned
	 * @param callback pointer to the function that will be called when this binding is updated
	 */
	void bindToggleButton(Crc::BUTTON buttonID, aex::Function<void(bool)> callback)
	{
		m_toggleButtonBindings.pushBack({buttonID, callback, false, false});
	}

	/**
	 * @brief Setup a callback function for a digital sensor binding
	 *
	 * @param handle handle associated to the digital sensor
	 * @param callback pointer to the function that will be called when this binding is updated
	 */
	void bindDigitalSensor(DigitalInputHandle& handle, aex::Function<void(bool)> callback)
	{
		m_digitalSensorBindings.pushBack({handle, callback, false});
	}

	/**
	 * @brief Update all the bindings and call the required callbacks
	 *
	 */
	void update()
	{
		// During each update, check which button are pressed and update necessary callbacks

		// Button bindings
		for (int i = 0; i < m_buttonBindings.getSize(); i++)
		{
			bool status = Crc::CrcLib::ReadDigitalChannel(m_buttonBindings[i].buttonID);
			if (status != m_buttonBindings[i].lastValue)
			{
				m_buttonBindings[i].callback(status);
			}

			m_buttonBindings[i].lastValue = status;
		}

		// Toggle button bindings
		for (int i = 0; i < m_toggleButtonBindings.getSize(); i++)
		{
			bool status = Crc::CrcLib::ReadDigitalChannel(m_toggleButtonBindings[i].buttonID);
			if (status && !m_toggleButtonBindings[i].lastValue) // the button was just pressed
			{
				m_toggleButtonBindings[i].isToggled != m_toggleButtonBindings[i].isToggled;
				m_toggleButtonBindings[i].callback(m_toggleButtonBindings[i].isToggled);
			}

			m_toggleButtonBindings[i].lastValue = status;
		}

		// Digital Sensor Bindings verification
		for (int i = 0; i < m_digitalSensorBindings.getSize(); i++)
		{
			bool status = m_digitalSensorBindings[i].handle.getValue();
			if (status != m_buttonBindings[i].lastValue)
			{
				m_digitalSensorBindings[i].callback(status);
			}

			m_digitalSensorBindings[i].lastValue = status;
		}
	}

	/**
	 * @brief Get whether a button is pressed or not on the controller
	 *
	 * @param buttonID CrcLib button that is being checked
	 * @return true the button is pressed
	 * @return false the button is not pressed
	 *
	 * This function is here for consistency, but the original Crc method can be used instead.
	 */
	inline bool getButtonInput(Crc::BUTTON buttonID)
	{
		return Crc::CrcLib::ReadDigitalChannel(buttonID);
	}

	/**
	 * @brief Get the state of an analog input on the controller (i.e. joystick or trigger)
	 *
	 * @param analogID CrcLib ANALOG channel for the desired input
	 * @return int8_t the value of the input (depends on which one it is)
	 *
	 * This function is here for consistency, but the original Crc method can be used instead.
	 */
	inline int8_t getAnalogInput(Crc::ANALOG analogID)
	{
		return Crc::CrcLib::ReadAnalogChannel(analogID);
	}

	/**
	 * @brief Get whether a digital sensor is in HIGH or LOW state
	 *
	 * @param handle reference to the digital sensor's handle
	 * @return true the sensor is in a HIGH state
	 * @return false the sensor is in a LOW state
	 *
	 * This function is here for consistency, but the value can be obtained directly from the handle instead.
	 */
	inline bool getDigitalSensorInput(const DigitalInputHandle& handle)
	{
		return handle.getValue();
	}

	/**
	 * @brief Get the state of an analog sensor
	 *
	 * @param handle reference to the analog sensor's handle
	 * @return unsigned int value representing the voltage read at that pin (0 is 0 volts and 1023 is 7.5 volts)
	 *
	 * This function is here for consistency, but the value can be obtained directly from the handle instead.
	 */
	inline unsigned int getAnalogSensorInput(const AnalogHandle& handle)
	{
		return handle.getValue();
	}

	/**
	 * @brief Get the position of an encoder
	 *
	 * @param handle reference to the encoder's handle
	 * @return int32_t position of the encoder
	 *
	 * This function is here for consistency, but the value can be obtained directly from the handle instead.
	 */
	inline int32_t getEncoderInput(const EncoderHandle& handle)
	{
		return handle.getValue();
	}

private:
	aex::Vector<ButtonBinding>        m_buttonBindings;        ///< Vector containing all the button bindings for this Controller
	aex::Vector<ToggleButtonBinding>  m_toggleButtonBindings;  ///< Vector containing all the toggle button bindings for this Controller
	aex::Vector<DigitalSensorBinding> m_digitalSensorBindings; ///< Vector containing all the digital sensor bindings for this Controller
};

} // rou

#endif // _INCLUDE_ROU_CONTROLLER_H_
