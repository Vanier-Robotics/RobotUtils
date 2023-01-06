/**
 * @file MotorModules.h
 * @author Diana
 * @brief MotorModule class
 * 
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_MODULES_H_
#define _INCLUDE_ROU_MODULES_H_

#include "ArduinoExtra.h"
#include "../Handle/Handle.h"
#include <CrcLib.h>
#include <cstdint>
#include "Modules.h"
namespace rou
{


class MotorModule : public Module
{
    public:
   
    void setup()
    {
        CrcLib::Initialize(false);
        CrcLib::InitializePwmOutput(CRC_PWM_1);         // Pwm pins, motors.
        CrcLib::InitializePwmOutput(CRC_PWM_2,false);
    }
   
    virtual void update()
    {

    }

};

} //namespace rou
#endif // _INCLUDE_ROU_MODULES_H_