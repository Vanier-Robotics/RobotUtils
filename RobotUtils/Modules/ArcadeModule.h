/**
 * @file ArcadeModule.h
 * @author Diana
 * @brief ArcadeModule class
 * 
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_ARCADE_MODULE_H_
#define _INCLUDE_ROU_ARCADE_MODULE_H_

#include "ArduinoExtra.h"
#include "../Handle/Handle.h"
#include <CrcLib.h>
#include <cstdint>
#include "Modules.h"

int8_t forwardChannelA;
int8_t yawChannelA;
//MoveArcade

namespace rou
{

class ArcadeModule : public Module
{
    public:
   
    ArcadeModule (uint8_t frontLeftMotor, uint8_t backLeftMotor, uint8_t frontRightMotor,uint8_t backRightMotor)
    {
        m_frontLeftMotor = frontLeftMotor;
        m_backLeftMotor = backLeftMotor;
        m_frontRightMotor = frontRightMotor;
        m_backRightMotor = backRightMotor;
    }

    void setup()
    {                  
     CrcLib::InitializePwmOutput(frontLeftMotor);
     CrcLib::InitializePwmOutput(backLeftMotor);
     CrcLib::InitializePwmOutput(frontRightMotor);
     CrcLib::InitializePwmOutput(backRightMotor);
     //pins
    }

    virtual void update()
    {
        CrcLib::MoveArcade(forwardChannelA, yawChannelA, frontLeftMotor, backLeftMotor, frontRightMotor, backRightMotor);
    }

    private:
    uint8_t m_frontLeftMotor;
    uint8_t m_backLeftMotor;
    uint8_t m_frontRightMotor;
    uint8_t m_backRightMotor;

};

} //namespace rou
#endif // _INCLUDE_ROU_ARCADE_MODULE_H_