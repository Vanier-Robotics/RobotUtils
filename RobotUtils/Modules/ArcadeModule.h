/**
 * @file ArcadeModule.h
 * @author Diana Riscanu
 * @brief ArcadeModule class
 * 
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_ARCADE_MODULE_H_
#define _INCLUDE_ROU_ARCADE_MODULE_H_

//#include "ArduinoExtra.h"
#include "PWMHandle.h"
#include "Modules.h"

namespace rou
{

class ArcadeModule : public Module
{
    public:
   
    ArcadeModule (PWMHandle& frontLeftMotor, PWMHandle& backLeftMotor, PWMHandle& frontRightMotor, PWMHandle& backRightMotor)
    {
      m_frontLeftMotor = &frontLeftMotor;
      m_backLeftMotor = &backLeftMotor;
      m_frontRightMotor = &frontRightMotor;
      m_backRightMotor = &backRightMotor;
    }

    virtual void move(int8_t forwardChannelA, int8_t yawChannelA)
    {
        if (m_frontLeftMotor->isAvailable() && m_backLeftMotor->isAvailable() && m_frontRightMotor->isAvailable() && m_backRightMotor->isAvailable())
        {
          m_frontLeftMotor->use();
          m_backLeftMotor->use();
          m_frontRightMotor->use();
          m_backLeftMotor->use();           
          CrcLib::MoveArcade(forwardChannelA, yawChannelA, frontLeftMotor, backLeftMotor, frontRightMotor, backRightMotor);
        }
    }

    private:
    PWMHandle* m_frontLeftMotor;
    PWMHandle* m_backLeftMotor;
    PWMHandle* m_frontRightMotor;
    PWMHandle* m_backRightMotor;

};

} //namespace rou
#endif // _INCLUDE_ROU_ARCADE_MODULE_H_