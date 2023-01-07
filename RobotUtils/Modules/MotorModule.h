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

const int STOP_POSITION;                       
//find out what a 360deg would be
    
const int MOTOR_SPEED;                     
//test out irl

namespace rou
{

class MotorModule : public Module
{
    public:
   
    void setup()
    {
        CrcLib::Initialize(false);                  
        //initialization phase
        CrcLib::InitializePwmOutput(CRC_PWM_1);
        //pin     
        analogWrite(CRC_PWM_1,MOTOR_SPEED);
    
    }
   
    virtual void update()
    {

    }

};

} //namespace rou
#endif // _INCLUDE_ROU_MOTOR_MODULE_H_