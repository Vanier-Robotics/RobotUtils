/**
 * @file LEDModule.h
 * @author Diana
 * @brief LEDModule class
 * 
 * @copyright Copyright (c) 2023 Vanier Robotics (MIT License)
 */

#ifndef _INCLUDE_ROU_LED_MODULE_H_
#define _INCLUDE_ROU_LED_MODULE_H_

//#include "ArduinoExtra.h"
//#include "DigitalOutputHandle.h"
#include "Modules.h"



namespace rou
{
    class LEDModule : public Module
    {
        public:
        LEDModule (DigitalOutputHandle& lightHandle)
        {
          m_lightHandle = &lightHandle;
        }

        void lightStatus(bool isOn)
        //verify if light is on or off
        {
          if (m_lightHandle->use())
            {
              CrcLib::SetDigitalInput(lightHandle->getPin(), (isOn ? HIGH : LOW));   
            }
        }

        private:
        DigitalOutputHandle* m_lightHandle;
    };
} // rou

#endif // _INCLUDE_ROU_LED_MODULE_H_
