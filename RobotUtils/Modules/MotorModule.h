/**
 * @file MotorModule.h
 * @author Diana
 * @brief MotorModule class
 * 
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_MOTOR_MODULE_H_
#define _INCLUDE_ROU_MOTOR_MODULE_H_

//#include "ArduinoExtra.h"
#include "PWMHandle.h"
#include "Modules.h"               

namespace rou
{

class MotorModule : public Module
{
    public:
   
   MotorModule (PWMHandle& motor)
    {
        m_motor = &motor;
    }

   void motorStatus(int8_t motorSpeed)
   {
     CrcLib::SetPwmOutput(m_motor,motorSpeed);
       
   }

    void setup()
    {
        CrcLib::InitializePwmOutput(motor);
    }

    private:
    PWMHandle* m_motor;
};

} //namespace rou
#endif // _INCLUDE_ROU_MOTOR_MODULE_H_