/**
 * @file DrivetrainModule.h
 * @author Diana
 * @brief DrivetrainModule class
 * 
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_DRIVETRAIN_MODULE_H_
#define _INCLUDE_ROU_DRIVETRAIN_MODULE_H_

#include "ArduinoExtra.h"
#include "../Handle/Handle.h"
#include <CrcLib.h>
#include <cstdint>
#include "Modules.h"

uint8_t frontLeftMotor = CRC_PWM_2;
uint8_t backLeftMotor = CRC_PWM_3;
uint8_t frontRightMotor = CRC_PWM_4;
uint8_t backRightMotor = CRC_PWM_5;

int8_t leftChannel;
int8_t rightChannel;
//MoveTank

int8_t forwardChannelA;
int8_t yawChannelA;
//MoveArcade

int8_t forwardChannelH;
int8_t yawChannelH;
int8_t strafeChannel;
//MoveHolonomic

namespace rou
{

class DrivetrainModule : public Module
{
    public:
   
    void setup()
    {
     CrcLib::Initialize(false);                  
     //initialization phase
     CrcLib::InitializePwmOutput(CRC_PWM_2);
     CrcLib::InitializePwmOutput(CRC_PWM_3);
     CrcLib::InitializePwmOutput(CRC_PWM_4);
     CrcLib::InitializePwmOutput(CRC_PWM_5);
     //pins
    }

    CrcLib::MoveTank(leftChannel, rightChannel, frontLeftMotor, backLeftMotor, frontRightMotor, backRightMotor); 
    CrcLib::MoveArcade(forwardChannelA, yawChannelA, frontLeftMotor, backLeftMotor, frontRightMotor, backRightMotor);
    CrcLib::MoveHolonomic(forwardChannelH, yawChannelH, strafeChannel, frontLeftMotor, backLeftMotor, frontRightMotor, backRightMotor);
   
    virtual void update()
    {

    }

};

} //namespace rou
#endif // _INCLUDE_ROU_DRIVETRAIN_MODULE_H_