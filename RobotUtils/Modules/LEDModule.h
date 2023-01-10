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



namespace rou
{
    class LEDModule : public Module
    {
        public:
        LEDModule (uint8_t lightPin)
        {
            m_lightPin = lightPin;
        }

        void setup()
        {
            CrcLib::SetDigitalPinMode(lightPin, OUTPUT);
        }

        void lightStatus(bool isOn)
        //verify if light is on or off
        {
           if (isOn) 
           {
            CrcLib::SetDigitalInput(lightPin,HIGH);
           }
            
           else 
           {
            CrcLib::SetDigitalInput(lightPin,LOW);
           }
            
        };

        virtual void update()
        {

        }

        private:
        uint8_t m_lightPin;
    }
} // rou

#endif // _INCLUDE_ROU_LED_MODULE_H_
