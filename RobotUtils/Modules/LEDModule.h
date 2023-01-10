/**
 * @file LEDModule.h
 * @author Diana
 * @brief LEDModule class
 * 
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_LED_MODULE_H_
#define _INCLUDE_ROU_LED_MODULE_H_

#include "ArduinoExtra.h"
#include "../Handle/Handle.h"
#include <CrcLib.h>
#include <cstdint>
#include "Modules.h"

uint8_t lightPin = 1;

namespace rou
{
    class LEDModule : public Module
    {
        public:

        void setup()
        {
            CrcLib::Initialize(false);
            CrcLib::SetDigitalPinMode(lightPin, INPUT);
        }

        bool lightStatus()
        //verify if light is on or off
        {
            if (CrcLib::GetDigitalInput(lightPin); == HIGH)
            return true;
            
            else if (CrcLib::GetDigitalInput(lightPin); == LOW)
            return false;
        }

        virtual void update()
        {

        }
    }
} // rou

#endif // _INCLUDE_ROU_LED_MODULE_H_
