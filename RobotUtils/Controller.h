/**
 * @file Controller.h
 * @author Gabriel Saberian
 * @brief Controller header file for Vanier Robotics' RobotUtils library, controls the robot by pressing 
 * digital and analog buttons on a controller.
 * 
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#include "ArduinoExtra.h"
#include "CrcLib.h"

#ifndef _INCLUDE_ROU_CONTROLLER_H_
#define _INCLUDE_ROU_CONTROLLER_H_

namespace rou
{
  //Structure that contains the variables and fuctions for the digital binding
struct DigitalBinding
{
    BUTTON buttonID; //variable of type BUTTON (from CRC lib) that stores a specific button
    aex::Function<void(*)> callback; //pointer function used to do some action with a digital button
};

//Structure that contains the variables and fuctions for the toggle binding
struct ToggleBinding
{
    BUTTON buttonID; //variable of type BUTTON (from CRC lib) that stores a specific button
    bool isToggled; //boolean variable that stores the state of the button (Toggled = true and not toggled = false)
    bool lastValue; // ?
    aex::Function<void(bool)> callback;
};

//Structure that contains the variables and fuctions for the analog binding
struct AnalogBinding
{
    Analog sensorID; //variable of type Analog (from CRC lib) that stores a specific button
    aex::Function<void(*)> callback; //pointer function used to do some action with an analog button
};

//Structure that contains the variables and fuctions for the sensor binding
struct SensorBinding
{
    BUTTON buttonID; //variable of type BUTTON (from CRC lib) that stores a specific button
    uint8_t pin; //variable of type uint8_t that stores the number of the pin on the crcDuino board
    aex::Function<void(uint8_t)> callback;
};

//Controller class that contains the callback functions (pointer functions) of the different structures
class Controller:
{
  public:
  //callback function for digital bindings
 void digitalBind()
 {

 }

  //callback function for toggle bindings
 void toggleBinding(bool isToggled, bool lastValue)
 {

 }
  //callback function for analog bindings
 void analogBinding()
 {

 }
  //callback function for sensor bindings
 void sensorBinding(uint8_t pin){

 }
};

} // rou

#endif // _INCLUDE_ROU_CONTROLLER_H_