/**
 * @file Controller.h
 * @author Gabriel Saberian
 * @brief Controller class used to manage all sorts of inputs
 *
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */
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
	 * @brief Structure that contains the variables and function for a digital binding
	 *
	 */
	struct DigitalBinding
	{
		Crc::BUTTON 				buttonID; ///< variable of type BUTTON (from CrcLib) that stores a specific button
		aex::Function<void(bool)>	callback; ///< pointer to the function called when the binding changes state
	};

	/**
	 * @brief Structure that contains the variables and function for a toggle binding
	 *
	 */
	struct ToggleBinding
	{
		Crc::BUTTON					buttonID; ///< variable of type BUTTON (from CrcLib) that stores a specific button
		aex::Function<void(bool)>	callback; ///< pointer to the function called when the binding changes state

		bool isToggled; ///< stores the state of the button
		bool lastValue; ///< boolean variable that keeps track of the previous value of a button
	};

	/**
	 * @brief Structure that contains the variables and function for an analog binding
	 *
	 */
	struct AnalogBinding
	{
		Crc::ANALOG 				analogID; ///< variable of type ANALOG (from CrcLib) that stores a specific button
		aex::Function<void(int8_t)>	callback; ///< pointer to the function called when the binding changes state
	};

	/**
	 * @brief Structure that contains the variables and functions for a digital sensor binding
	 *
	 */
	struct DigitalSensorBinding
	{
		uint8_t						pin;      ///< the pin number from Crclib
		aex::Function<void(bool)>	callback; ///< pointer to the function called when the binding changes state
	};

	/**
	 * @brief Structure that contains the variables and functions for an analog sensor binding
	 *
	 */
	struct AnalogSensorBinding
	{
		uint8_t								pin;      ///< the pin number from Crclib
		aex::Function<void(unsigned int)>	callback; ///< pointer to the function called when the binding changes state
	};

public:
	/**
	 * @brief Setup a callback function for a digital binding
	 *
	 * @param buttonID The BUTTON to which the binding is assigned
	 * @param callback Pointer to the function that will be called when this binding is updated
	 */
	void digitalBind(Crc::BUTTON buttonID, aex::Function<void(bool)> callback)
	{
		m_digitalBindings.pushBack({buttonID, callback});
	}

	/**
	 * @brief Setup a callback function for a toggle binding
	 *
	 * @param buttonID The BUTTON to which the binding is assigned
	 * @param callback Pointer to the function that will be called when this binding is updated
	 */
	void toggleBind(Crc::BUTTON buttonID, aex::Function<void(bool)> callback)
	{
		m_toggleBindings.pushBack({buttonID, callback, false, false});
	}

	/**
	 * @brief Setup a callback function for an analog binding
	 *
	 * @param analogID The ANALOG input to which the binding is assigned
	 * @param callback Pointer to the function that will be called when this binding is updated
	 */
	void analogBind(Crc::ANALOG analogID, aex::Function<void(int8_t)> callback)
	{
		m_analogBindings.pushBack({analogID, callback});
	}

	/**
	 * @brief Setup a callback function for a digital sensor binding
	 *
	 * @param pin The CrcLib pin number to which the sensor is connected
	 * @param callback Pointer to the function that will be called when this binding is updated
	 */
	void digitalSensorBind(uint8_t pin, aex::Function<void(bool)> callback)
	{
		m_digitalSensorBindings.pushBack({pin, callback});
	}

	/**
	 * @brief Setup a callback function for an analog sensor binding
	 *
	 * @param pin The CrcLib pin number to which the sensor is connected
	 * @param callback Pointer to the function that will be called when this binding is updated
	 */
	void analogSensorBind(uint8_t pin, aex::Function<void(unsigned int)> callback)
	{
		m_analogSensorBindings.pushBack({pin, callback});
	}

	/**
	 * @brief Update all the bindings and call the required callbacks
	 *
	 */
	void update()
	{
		// For each frame, verify which button are pressed and call the corresponding methods

		// Digital Bindings verification
		for (int i = 0; i < m_digitalBindings.getSize(); i++)
		{
			m_digitalBindings[i].callback(
				Crc::CrcLib::ReadDigitalChannel(m_digitalBindings[i].buttonID));
		}

		// Analog Bindings verification
		for (int i = 0; i < m_analogBindings.getSize(); i++)
		{
			m_analogBindings[i].callback(
				Crc::CrcLib::ReadAnalogChannel(m_analogBindings[i].analogID));
		}

		// Toggle Bindings verification
		for (int i = 0; i < m_toggleBindings.getSize(); i++)
		{
			bool status = Crc::CrcLib::ReadDigitalChannel(m_toggleBindings[i].buttonID);
			if (m_toggleBindings[i].lastValue != status && status)
			{
				m_toggleBindings[i].isToggled != m_toggleBindings[i].isToggled;
				m_toggleBindings[i].callback(m_toggleBindings[i].isToggled);
			}

			m_toggleBindings[i].lastValue = status;
		}

		// Digital Sensor Bindings verification
		for (int i = 0; i < m_digitalSensorBindings.getSize(); i++)
		{
			m_digitalSensorBindings[i].callback(
				(Crc::CrcLib::GetDigitalInput(m_digitalSensorBindings[i].pin) == HIGH));
		}

		// Analog Sensor Bindings verification
		for (int i = 0; i < m_analogSensorBindings.getSize(); i++)
		{
			m_analogSensorBindings[i].callback(
				Crc::CrcLib::GetAnalogInput(m_analogSensorBindings[i].pin));
		}
	}

private:
	aex::Vector<DigitalBinding>			m_digitalBindings;       ///< Vector of DigitalBinding's which were created
	aex::Vector<ToggleBinding>			m_toggleBindings;        ///< Vector of ToggleBinding's which were created
	aex::Vector<AnalogBinding>			m_analogBindings;        ///< Vector of AnalogBinding's which were created
	aex::Vector<DigitalSensorBinding>	m_digitalSensorBindings; ///< Vector of DigitalSensorBinding's which were created
	aex::Vector<AnalogSensorBinding>	m_analogSensorBindings;  ///< Vector of AnalogSensorBinding's which were created
};

} // rou

#endif // _INCLUDE_ROU_CONTROLLER_H_
