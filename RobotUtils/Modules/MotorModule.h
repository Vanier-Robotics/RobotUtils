/**
 * @file MotorModule.h
 * @author Diana
 * @brief MotorModule class
 * 
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_MOTOR_MODULE_H_
#define _INCLUDE_ROU_MOTOR_MODULE_H_

#include "ArduinoExtra.h"
#include "../Handle/Handle.h"
#include <CrcLib.h>
#include <cstdint>
#include "Modules.h"
    
//as uint8_t as bool like in LEDModule                

namespace rou
{

class MotorModule : public Module
{
    public:
   
   MotorModule (uint8_t motor)
    {
        m_motor = motor;
    }

   void motorStatus(int8_t motorSpeed)
   {
     CrcLib::SetPwmOutput(m_motor,motorSpeed);
       
   }

    void setup()
    {
        CrcLib::InitializePwmOutput(motor);
    }
   
    virtual void update()
    {
    
    }

    private:
    uint8_t m_motor;
};

} //namespace rou
#endif // _INCLUDE_ROU_MOTOR_MODULE_H_